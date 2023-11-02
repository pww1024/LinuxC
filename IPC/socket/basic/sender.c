#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<string.h>

#include"proto.h"

int main(int argc,char **argv)
{
    int sd;
    struct msg_st sendbuf;
    struct sockaddr_in remote_addr;

    if(argc<2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }

    sd=socket(AF_INET, SOCK_DGRAM, 0);
    if(sd<0)
    {
        perror("socket()");
        exit(1);
    }

    //bind

    // 设置发送内容
    strcpy(sendbuf.name,"Alan");
    sendbuf.math=htonl(rand()%100);
    sendbuf.chinese=htonl(rand()%100);

    // 设置接收方地址
    remote_addr.sin_family=AF_INET;
    remote_addr.sin_port=htons(atoi(RECVPORT));
    inet_pton(AF_INET,argv[1],&remote_addr.sin_addr);

    if(sendto(sd,&sendbuf,sizeof(sendbuf),0, \
    (void *)&remote_addr,sizeof(remote_addr)) < 0)
    {
        perror("sendto()");
        exit(1);
    }

    puts("OK!");

    exit(0);
}