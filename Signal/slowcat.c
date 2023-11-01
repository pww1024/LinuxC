/*
漏桶实现,每秒输出10个字符
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

#define CPS 10
#define BUFSIZE CPS

static volatile int loop=0;

void alarm_handler(int s)
{
    alarm(1);
    loop=1;
}

int main(int argc,char ** argv)
{
    int sfd;
    char buf[BUFSIZE];
    int len;

    if (argc < 2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }

    sfd=open(argv[1],O_RDONLY);

    signal(SIGALRM,alarm_handler);
    alarm(1);

    while (1)
    {
        while(1)
            pause(); // 不加pause，会一直循环，占用CPU,
            // 但pause也有问题，它可以接收到任何信号,无法精确控制

        loop=0; // 消耗一个令牌

        while ((len=read(sfd,buf,BUFSIZE)) < 0)
        {
            /* code */
        }
        


    }
    
    

    exit(0);
}