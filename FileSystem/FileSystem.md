# FileSystem

本章目标:类ls的实现，如myls -l -a -i -n 

一.目录和文件

1、获取文件属性
    stat:通过文件路径获取 属性,面对符号链接文件时获取的是所指向的目标文件
    fstat:通过文件描述符获取属性
    lstat:面对符号链接文件时获取的是符号链接文件的属性

2、文件访问权限
    st_mode是一个16位的`位图`,用于表示文件类型,文件访问权限,及特殊权限位

3、umask
    0666 & ~umask
    防止产生权限过松的文件

4、文件权限的更改/管理
    fuc
        chmod,fchmod

5、粘住位
    t位:给模块在内存中留下痕迹
    ls / -l  # 根下的tmp目录

6、文件系统:FAT,UFS

7、硬链接，符号链接
    ln bigfile bigfile_link
    

8、utime
    可更改文件的最后读的时间和最后修改的时间

9、目录的创建和销毁
    mkdir
    rmdir

10、更改当前工作路径
    chdir
    fchdir
    getcwd

11、分析目录/读取目录内容
    glob()


    opendir();
    closedir();
    readdir(3);
    rewenddir();
    seekdir();
    telldir();


extra:
    touch -- -a

    tags
    vim -t size_t

二.系统数据文件和信息

1 /etc/passwd
	getpwuid()
	getpwnam()
2 /etc/group
	getgrgid()
	getgrgrnam()
3 /etc/shadow
	getspnam()
	crypt()
	getpass()

extra:
    su -切换到root用户

4.时间戳:time_t     char *      struct tm
    time()
    gmtime()
    localtime()
    mktime()
    strftime()

三.进程环境

1 main函数
    int main(int argc, char *argv[])

2 * 进程的终止 (背到非常熟练)
	5个正常终止3个异常终止
	正常终止
		从main函数返回
		调用exit
		调用_exit或_Exit
		最后一个线程从其启动例程返回
        最后一个线程调用pthread_exit
	异常终止
		调用abort
		接到一个信号并终止
		最后一个线程对其取消请求做出响应
	atexit():钩子函数

3 命令行参数的分析
	int getopt(int argc, char * const argv[],const char *optstring);
	getopt_long()

    extern char *optarg;
    extern int optind, opterr, optopt;

4 环境变量
    !export
    KEY = VALUE

    LANG=en
    date的变化

    全局变量 environ
    extern char ** environ;

    getenv("PATH");
    setenv  // 释放原先的内存,malloc出一块新的空间,指针指向他
    putenv

5 C程序的存储空间布局
    p127
    !pmap `process id`

6 库
    动态库 .a
    静态库 .so
    手工装载库
    dlopen();
    dlclose();
    dlerror();


7 函数跳转
    int setjmp(jmp_buf env);
    void longjmp(jmp_buf env, int val);


8 资源的获取及应用
    int getrlimit(int resource, struct rlimit *rlim);
    int setrlimit(int resource, const struct rlimit *rlim);



