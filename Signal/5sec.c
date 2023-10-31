/*
使用time函数测试5秒种能跑多少循环
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
int main()
{
    time_t  end;
    end  = time(NULL) + 5;
    int64_t count = 0;
    while (time(NULL)<=end)
    {
        count++;
    }
    printf("Count = %ld\n",count);
    exit(0);
}