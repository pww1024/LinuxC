# 使用_exit而不使用exit的情况

diff exit _exit

exit:标准io函数,对_exit进行封装
_exit:系统调用

int func()
{return 0/1/2}

int main()
{
    int f;

    f=func();

    ...???

    switch(f)
    {
        case 0:
        case 1:
        case 2:
        default:
            // exit(1); 
            // 出现意料之外的情况不能直接调用exit,这样会自动调用一系列钩子函数,刷新IO,缓冲区,写入数据等,扩大损失
            _exit(1); // 或者abort
    }
}