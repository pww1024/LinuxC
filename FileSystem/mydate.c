/*
man 3 getopt // 库函数
使用getopt函数选择输出时间的格式
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h> 
#include<string.h>
#include<time.h>
#include <getopt.h>

#define BUFSIZE 1024
#define FILE_NAME "/tmp/out"

int main(int argc,char **argv)
{
    time_t t;
    struct tm *tmp;
    char fmtstr[BUFSIZE]; // 命令行选项字符串
    char timestr[BUFSIZE]; // 最终输出的时间字符串
    int c;
    fmtstr[0]='\0';

    c=getopt(argc,argv,"H:MSy:md"); //hour minute second year month day

    if (c<0 || c>7)
    {
        printf("Usage: %s [-HMSymd]\n",argv[0]);
        exit(1);
    }

    t=time(NULL);
    tmp=localtime(&t);

    switch (c)
    {
        case 1:
            break;
        case 'H':
            if(strcmp(optarg,"12"))
                strncat(fmtstr,"%H:",BUFSIZE);
            else if (strcmp(optarg,"24"))
            {
                strncat(fmtstr,"%I(%P)",BUFSIZE);
            }
            else
            {
                fprintf(stderr,"Usage: %s [-H 12|24]\n",argv[0]);
            }
            break;
        case 'M':
            strncat(fmtstr,"%M:",BUFSIZE);
            break;
        case 'S':
            strncat(fmtstr,"%S:",BUFSIZE);
            break;
        case 'y':
            if(strcmp(optarg,"2"))
            {
                strncat(fmtstr,"%y",BUFSIZE);        
            }
            else if (strcmp(optarg,"4"))
            {
                strncat(fmtstr,"%Y",BUFSIZE);
            }
            else
            {
                fprintf(stderr,"Usage: %s [-y 2|4]\n",argv[0]);
            }
            break;
        case 'm':
            strncat(fmtstr,"%m:",BUFSIZE);
            break;
        case 'd':
            strncat(fmtstr,"%d:",BUFSIZE);
            break;
        default:
            printf("default\n");
            break;
    }

    strftime(timestr,BUFSIZE,fmtstr,tmp);
    puts(timestr);
    
    exit(0);
}
