#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main()
{
    int i,j;
    sigset_t set, oldset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    
    sigprocmask(SIG_BLOCK, &set, &oldset); // 保存原来的信号屏蔽字

    for (i=0; i<100; i++)
    {
        sigprocmask(SIG_BLOCK, &set, NULL);
        for(j=0; j<5; j++)
        {
            write(1, "*", 1);
            sleep(1);
        }
        write(1, "\n", 1);
        sigprocmask(SIG_UNBLOCK, &set, NULL);
    }

    sigprocmask(SIG_SETMASK, &oldset, NULL); // 恢复原来的信号屏蔽字

}