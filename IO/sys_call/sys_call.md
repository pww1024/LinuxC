# file io / system call
文件IO/系统调用IO
fd是在文件IO中贯穿始终的类型

文件描述符(file descriptor)的概念: (结构图:sys_call.png)
    整形数，数组下标，文件描述符优先使用当前可用范围内最小的
    ulimit更改这个数组的大小
    当一个进程启动时，通常会自动打开三个文件描述符012
    0 1 2 STDIN STDOUT STDERR 标准输入/输出/错误输出

文件IO操作:open,close,read,write,lseek
    判断某个函数是变参还是重载
    给变参函数传入多个参数,编译器只会报警告,而重载函数会报错
    open是用变参实现的

文件IO与标准IO的区别


IO的效率问题
- 习题:将mycopy.c程序进行更改,将BUFSIZE的值逐渐放大,按2的指数增大,并观察进程所消耗的时间,注意性能最佳拐点出现时的BUFSIZE值,以及何时程序会出问题

文件共享:多个任务共同操作一个文件或者协同完成任务
- 面试:仅使用系统调用函数写一个程序删除一个文件的第10行
补充函数:truncate/ftruncate

原子操作:不可分割的操作
原子:不可分割的最小单位
作用:解决竞争和冲突
临时文件:
不建议使用tmpnam,不原子
tmpfile

程序中的重定向:dup,dup2
dup拷贝传入的oldfd到一个最小的可用的文件描述符,
在结构中表现为在进程表项中将下一个单元指向oldfd指向的文件表

同步:sync,fsync,fdatasync


fcntL():文件描述符所变的魔术几乎都来源于该函数

ioctL():设备相关的内容

/dev/fd/目录:虚目录,显示的是当前进程的文件描述符的信息

