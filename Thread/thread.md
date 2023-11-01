# 线程

1.线程的概念

    一个正在运行的函数
    posix线程,是一套标准,而不是实现
    openmp线程
    线程标识:pthread_t 其中的p指posix,类型具体什么内容不知道,有多种实现
    ps axm
    - -表示一个线程
    信号与多线程尽量别混用
    pthread_equal();
    pthread_self();

2.线程的创建
    pthread_create();
    线程的调度取决于调度器的策略


线程的终止
    3种方式:(1)线程从启动例程返回,返回值就是线程的退出码
        (2)线程可以被同一进程中的其他进程取消(异常终止)
        (3)线程调用pthread_exit()函数
    pthread_join() -->  wait()  //等待,给线程收尸

栈的清理
    pthread_cleanup_push();  // 挂钩
    pthread_cleanup_pop();  // 取钩

线程的取消选项

3.线程同步

4.线程属性
线程同步的属性

5.重入
线程与信号
线程与fork

