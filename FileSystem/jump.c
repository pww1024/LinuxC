#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<setjmp.h>

static jmp_buf env; //通常作为一个数组，用于存储 setjmp 保存的上下文信息

void func_a()
{
    int ret;

    ret = setjmp(env);

    if (ret==0)
    {
    printf("%s():begin\n",__FUNCTION__);

    printf("%s():call b()\n",__FUNCTION__);
    func_b();    

    printf("%s():end\n",__FUNCTION__);
    }
    else
    {
        printf("%s():jumped back here with code %d\n",__FUNCTION__,ret);
    }
    
}

void func_b()
{
    printf("%s():begin\n",__FUNCTION__);

    printf("%s():call c()\n",__FUNCTION__);
    func_c();

    printf("%s():end\n",__FUNCTION__);
}

void func_c()
{
    printf("%s():begin\n",__FUNCTION__);

    printf("%s():call d()\n",__FUNCTION__);
    func_d();

    printf("%s():end\n",__FUNCTION__);
}

void func_d()
{
    printf("%s():begin\n",__FUNCTION__);

    printf("%s():jump a()\n",__FUNCTION__);
    longjmp(env,42);
    printf("%s():end\n",__FUNCTION__);
}

int main()
{
    func_a();
    exit(0);
}