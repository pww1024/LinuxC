0.ps
    ps axm
    ps axf
    ps ax -L

1.



2.进程的产生
    fork()
    man手册关键字:duplicating,意味着拷贝,克隆,程序执行到的地方,一模一样等含义
    fork后父子进程的区别:fork的返回值不一样,pid,ppid不同,未决信号和文件锁不继承,资源利用量清零
    init进程:1号,是所有进程的祖先进程
    


    vfork()
    