/*
使用alarm测试5秒种能跑多少循环
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include<signal.h>
#include <unistd.h>

static volatile int loop=1; // 使用volatile修饰，防止编译器优化

static void alarm_handler(int signo)
{
    loop = 0;
}

int main()
{
    int64_t count = 0;

    signal(SIGALRM,alarm_handler);
    // signal必须在alarm之前
    alarm(5);
    
    while(loop) // 若不加volatile修饰，这里会被优化成while(1)
    {
        count++;
    }

    printf("Count = %ld\n",count);
    exit(0);
}