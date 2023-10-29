#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>

off_t flen(char * filename)
{
    struct stat statres;
    
    if(stat(filename,&statres)<0)
    {
        perror("stat()");
        exit(1);
    }

    return statres.st_size;
}

static int ftype(const char * filename)
// 尽量不用char类型返回
{
    struct stat statres;

    if(stat(filename,&statres)<0)
    {
        perror("stat()");
        exit(1);
    }
    // man 7 inode
    if(S_ISREG(statres.st_mode))
        return '-';
    else if(S_ISDIR(statres.st_mode))
        return 'd';
    else if(S_ISCHR(statres.st_mode))
        return 'c';
    else if(S_ISBLK(statres.st_mode))
        return 'b';
    else if(S_ISFIFO(statres.st_mode))
        return 'p';
    else if(S_ISLNK(statres.st_mode))
        return 'l';
    else if(S_ISSOCK(statres.st_mode))
        return 's';
    else
        return '?';
}
static int ftype2(const char * filename)
{
    struct stat statres;
    mode_t mode;
    stat(filename, &statres);

    // 获取当前权限模式
    mode = statres.st_mode;

    // 修改权限模式：给所有者增加读和写的权限
    mode |= S_IRUSR | S_IWUSR;

    // 修改权限模式：去掉群组和其他人的所有权限
    mode &= ~(S_IRWXG | S_IRWXO);

    // 应用新的权限模式到文件
    if (chmod(filename, mode) != 0) {
        perror("chmod");
    }

    // chmod 751 filename
    // 751 S_IRWXU（700）、S_IRGRP | S_IXGRP（050）和S_IROTH（001）加在一起得到的
    return 0;
}
int main(int argc, char ** argv)
{
    if (argc<2)
    {
        perror("Usage: ./mylen <filename>");
        exit(1);
    }

    printf("%lld\n",(long long)flen(argv[1]));

    printf("%c\n",ftype(argv[1]));

    exit(0);
}