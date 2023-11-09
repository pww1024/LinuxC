#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZE 20

int main()
{
    pid_t pid;
    int pd[2];
    char buf[BUFSIZE];
    int len;

    if(pipe(pd)<0)
    {
        printf("Error");
        return 1;
    }

    pid=fork();
    if(pid<0)
    {
        printf("Error");
        return 1;
    }
    else if(pid==0) //child process
    {
        close(pd[1]); // 0端作为读端
        len=read(pd[0],buf,14);
        write(1,buf,len);
        close(pd[0]);
        exit(0);
    }
    else //parent process
    {
        close(pd[0]); // 1端作为写端
        write(pd[1],"hello world\n",14);
        close(pd[1]);
        wait(NULL);
        exit(0);
    }

    exit(0);
}