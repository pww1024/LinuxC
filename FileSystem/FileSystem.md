# FileSystem

类ls的实现，如myls -l -a -i -n

一.目录和文件

1、获取文件属性
    stat,fstat,lstat

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