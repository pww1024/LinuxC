# stdio

I/O : input & output ,是一切实现的基础
    stdio标准IO
    sysio系统调用IO

fopen()
    栈(F)   静态区(F)   堆
    FILE *fopen(const char *path, const char *mode)
fclose()

fgetc()
fputc()
fgets()
fputs()
fread()
fwrite()

printf()
scanf()

fseek()
ftell()
rewind()

fseeko()
ftello()

fflush()

getline()


extra:
    0666 & ~umask
    read write execute
    4   2   1
    0666与umask是8进制数
        0666:
            0特殊权限位
            6文件所有者,读,写
            6文件所属组
            6其他用户
        umask:
            umask命令查看/设置umask值

