/*
两种方式输出100天后的日期
1.直接修改time_t,加上100天的秒数
2.修改tm结构体,再用mktime修正
*/


#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<shadow.h>
#include <unistd.h> 
#include <string.h>
#include<time.h>

#define BUFSIZE 1024
#define FILE_NAME "tmp/out"

int main()
{
    time_t t;
    struct tm *tmp;
    char timestr[BUFSIZE];

    t=time(NULL);
    tmp=localtime(&t);

    strftime(timestr,BUFSIZE,"now: %Y-%m-%d %H:%M:%S\n",tmp);
    puts(timestr);

    t += 100*24*60*60;
    tmp=localtime(&t);
    strftime(timestr,BUFSIZE,"after 100 days 1: %Y-%m-%d %H:%M:%S\n",tmp);
    puts(timestr);

    tmp->tm_mday += 100;
    (void)mktime(tmp); // mktime会自动修正时间
    //(void) 会忽略返回值,消除警告
    strftime(timestr,BUFSIZE,"after 100 days 2: %Y-%m-%d %H:%M:%S\n",tmp);
    puts(timestr);

    exit(0);
}
