#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

void * fuc(void * arg)
{
    puts("Thread is working!");

    pthread_exit(NULL);
    // return NULL;
}

int main()
{
    pthread_t pid;

    puts("Begin!");

    pthread_create(&pid, NULL,fuc,NULL);

    puts("End!");

    exit(0);

}