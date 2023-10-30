/*
每一秒写入行号与当前时间的格式化字符串,
程序中断后再运行能接着行号写
apue中p118
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<shadow.h>
#include <unistd.h> 
#include <string.h>
#include<time.h>

#define BUFSIZE 1024
#define FILE_NAME "/tmp/out"

int main()
{
    FILE * fp;
    time_t t;
    struct tm *tmp;
    int lines=0;
    char buf[BUFSIZE];

    fp=fopen(FILE_NAME,"a+");
    // fp=stdout;

    if(fp==NULL)
    {
        perror("fopen()");
        exit(1);
    }

    while (fgets(buf,BUFSIZE,fp) != NULL)
    {
        lines++;
    }
    
    while (1)
    {
        t=time(NULL);
        tmp=localtime(&t);
        fprintf(fp,"%-4d %d-%d-%d %d:%d:%d \n",lines++, \
        tmp->tm_year+1900,tmp->tm_mon+1,tmp->tm_mday, \
        tmp->tm_hour,tmp->tm_min,tmp->tm_sec);
        fflush(fp); // 记得刷新缓冲区
        sleep(1);
    }

    fclose(fp);

    exit(0);
}