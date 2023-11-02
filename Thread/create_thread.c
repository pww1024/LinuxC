#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

static void cleanup_func(void * p)
{
    puts(p);
}

static void * fuc(void * arg)
{
    puts("Thread is working!");

    pthread_cleanup_push(cleanup_func, "cleanup 1");
    pthread_cleanup_push(cleanup_func, "cleanup 2");
    pthread_cleanup_push(cleanup_func, "cleanup 3");

    puts("push over!");

    pthread_cleanup_pop(1); // 1 means execute the cleanup func
    pthread_cleanup_pop(0); // 0 means not execute the cleanup func
    pthread_cleanup_pop(0);

    pthread_exit(NULL);
    // return NULL;
    /*
    diff between pthread_exit and return

    */
}

int main()
{
    pthread_t pid;
    int err;

    puts("Begin!");

    err=pthread_create(&pid, NULL,fuc,NULL);
    // return 0(success) or errno(fail)

    if(err)
    {
        fprintf(stderr, "pthread_create error:%s\n", strerror(err));
        exit(1);
    }

    pthread_join(pid, NULL);

    puts("End!");

    exit(0);

}