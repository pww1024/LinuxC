#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int file_size(const char * filename)
{
    FILE * fp = fopen(filename,"r");
    if(fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    fseek(fp,0,SEEK_END);
    int size = ftell(fp);
    fclose(fp);

    return size;
}

int file_size2(const char * filename)
{
    FILE * fp = fopen(filename,"r");
    if(fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    int size = 0;
    while(fgetc(fp) != EOF)
    {
        size++;
    }
    fclose(fp);

    return size;
}

int main(int argc,char ** argv)
{
    if(argc<2)
    {
        perror("usage err\n");
    }
    printf("size=%d\n", file_size(argv[1]));
    printf("size=%d\n", file_size2(argv[1]));

    exit(0);
}