 1.进程标识符pid
    
    类型pid_t
    传统意义上是一个16位的有符号整型数
    命令ps
        ps axm
        ps axf
        ps ax -L
    进程号是顺次向下使用
    getpid();
    getppid();


2.进程的产生
    fork()
    man手册关键字:duplicating,意味着拷贝,克隆,程序执行到的地方,一模一样等含义
    fork后父子进程的区别:fork的返回值不一样,pid,ppid不同,未决信号和文件锁不继承,资源利用量清零
    init进程:1号,是所有进程的祖先进程
    调度器的调度策略来决定哪个进程先运行
    fflush()的重要性


    vfork()

3.进程的消亡及释放资源

4.exec函数族

5.用户权限及组权限

6.观摩课:解释器文件

7.system()

8.进程会计


9.进程时间

10.守护进程 daemonize
    fork一个程序,dup2重定向3个流close,setsid脱离终端,改变工作目录(防止挂载时显示device busy)

    tail -f /tmp/out

11.系统日志


    