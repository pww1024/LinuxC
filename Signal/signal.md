# 并发(信号,线程)
同步
异步

异步事件的处理:查询法通知法

一.信号
1.信号的概念:*信号是软件中断
信号的响应依赖于中断

2.signal()
kill -l
p199

typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
equal to
void (*signal(int signum,void (*func)(int)))(int);

*信号会打断阻塞的系统调用

3.信号的不可靠
    内核帮忙布置执行现场,有可能第一个信号的动作还没结束,就来了第二个信号


4.可重入函数
    所有的系统调用都是可重入的,一部分库函数也是可重入的,如:memcpy,部分以_r结尾的函数

5.信号的响应过程
信号屏蔽字mask(全1) panding(全0) 位图
信号从收到到响应有一个不可避免的延迟
思考:如何忽略掉一个信号
    标准信号为什么要丢失
    标准信号的响应没有严格的顺序
    不能从信号处理函数中随意的往外跳(setjmp,longjmp),唯独不能随意从信号处理函数中往外跳

`在程序运行时间片耗尽时，被内核的中断机制打断时，程序保存当前的执行现场，进入到内核态的就绪队列等待就绪，当再次获取时间片时，从内核态回到用户态期间程序会将mask位图 按位与上 pending位图来判断是否接收到信号，当没有信号时，位图结果为0，表示没有收到信号，程序回到之前的执行现场继续执行。程序当收到信号时，对应的信号结果为1，程序执行对应的信号处理函数，此时对应的mask位和pending位均置为0，当执行完信号处理函数后，将对应的mask位置为1，如果时间片没有耗尽就回到用户态执行之前任务的位置，否则进入就绪队列等待调度。`


6.常用函数
    kill();
    raise();
    alarm(); // 1个以上alarm会出错
    setitimer();
例:使用单一计时器,利用alarm/setitimer构造一组函数,实现任意数量的计时器

    pause();
    abort();

    system();
    sleep(); // 部分平台用alarm封装,尽量不用
    nanosleep();
    usleep()
    select()

7.信号集
    信号集类型:sigset_t
    sigemptyset()
    sigfillset()
    sigaddset()
    sigdelset()
    sigismember()

8.信号屏蔽字/pending集的处理
    int sigprocmask(int how, const sigset_t *set, sigset_t *oldset); // 人为更改mask位图的值
    SIG_BLOCK（在当前屏蔽字基础上添加 set 里的信号）、SIG_UNBLOCK（从当前屏蔽字中移除 set 里的信号）和 SIG_SETMASK（用 set 里的信号替换当前的屏蔽字）
    sigpending();

    pending反应接到的信号
    mask反应是否响应


9.拓展
    sigsuspend();

    sigaction(); ->signal();
        signal(SIGINI,daemon_exit);
        signal(SIGQUIT,daemon_exit);
        signal(SIGTERM,daemon_exit);
        多个signal接收共用同一个handler函数可能会发生重入
        usage:
        struct sigaction sa;
        sa.sa_handler = daemon_exit;
        sigemptyset(&sa.sa_mask);
        sigaddset(&sa.sa_mask, SIGQUIT);
        sigaddset(&sa.sa_mask, SIGTERM);
        sa.sa_fLags = 0;
        sigaction(SIGINT, &sa, NULL);
        替代第一个signal函数,在接收SIGINI信号的同时把其他信号阻塞

        struct sigaction sa;
        sa.sa_handler = daemon_exit;
        sigemptyset(&sa.sa_mask);
        sigaddset(&sa.sa_mask, SIGQUIT);
        sigaddset(&sa.sa_mask, SIGTERM);
        sigaddset(&sa.sa_mask, SIGINI);
        sa.sa_fLags = 0;
        sigaction(SIGINT, &sa, NULL);
        sigaction(SIGINT, &sa, NULL);
        sigaction(SIGINT, &sa, NULL);



    setitimer();

10.实时信号
    存放实时信号的文件 /usr/include/bits/signum.h
    kill -l
    实时信号的名字通常是SIGRTMIN到SIGRTMAX这样的形式
    实时信号具有排队能力,不丢失


并发实现
信号先有实现再有标准,线程先有标准再有实现

