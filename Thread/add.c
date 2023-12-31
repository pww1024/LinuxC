#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<string.h>

#define LINESIZE 1024
#define THRNUM 20
#define FNAME "/tmp/out"

static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

static void *thr_add(void *p)
{
    FILE *fp;
    char linebuf[LINESIZE];

    fp = fopen(FNAME, "r+");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    pthread_mutex_lock(&mut);
    fgets(linebuf, LINESIZE, fp);
    fseek(fp, 0, SEEK_SET);
    sleep(1);
    fprintf(fp, "%d\n", atoi(linebuf) + 1); 
    fclose(fp);
    pthread_mutex_unlock(&mut);

    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[THRNUM];
    int i;
    int err;
    FILE *fp;

    fp = fopen(FNAME, "w");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    fputs("0\n", fp);

    for(i = 0; i < THRNUM; i++)
    {
        err=pthread_create(tid + i, NULL, thr_add, NULL);
        if (err)
        {
            fprintf(stderr, "pthread_create():%s\n", strerror(err));
            exit(1);
        }
    }

    for(i=0;i<THRNUM;i++)
        pthread_join(tid[i], NULL);

    pthread_mutex_destroy(&mut);

    exit(0);
}