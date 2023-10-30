/*
atexit()
在函数正常终止后,逆序调用钩子中传入的函数
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <unistd.h> 

void f1()
{
    puts("f1 is running");
}
void f2()
{
    puts("f2 is running");
}
void f3()
{
    puts("f3 is running");
}

int main()
{
    puts("begin!");

    atexit(f1);
    atexit(f2);
    atexit(f3);

    puts("end!");
    
    exit(0);

}