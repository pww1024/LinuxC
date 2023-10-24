#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FNAME "/tmp/out"

void dup1_()
{
    int fd;

    close(1);

    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open()");
        exit(1);
    }

    /***********/

    puts("hello1");
    // cat /tmp/out
}
void dup2_()
{
    int fd;

    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open()");
        exit(1);
    }

    close(1);
    dup(fd);

    close(fd);

    /***********/

    puts("hello2");
    // error 
    // if program has no 1 fd
    // or bothor fd get 1 fd between close(1) and dup(fd)
}
void dup3_()
{
    int fd;

    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open()");
        exit(1);
    }

    dup2(fd, 1);

    if(fd != 1)
        close(fd);

    /***********/

    puts("hello2");

    /* restore stdout(fd 1) */ 
}
int main()
{
    dup2_();

    exit(0);
}