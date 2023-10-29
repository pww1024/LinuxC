#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();

    printf("begin\n");

    if(pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0) // child process
    {
        printf("child process, pid = %d, ppid = %d\n", getpid(), getppid());
    }
    else // parent process
    {
        printf("parent process, pid = %d, ppid = %d\n", getpid(), getppid());
    }

    printf("[%d]end\n", getpid());

    exit(0);
}
