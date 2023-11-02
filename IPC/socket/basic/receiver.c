#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include"proto.h"

int main()
{
    int sd;
    struct sockaddr_in local_addr,remote_addr; 
    // sockaddr_in是AF_INET协议族专用的地址结构
    struct msg_st rcvbuf; 
    socklen_t remote_addr_len;
    char ipstr[IPSTRSIZE];

    sd=socket(AF_INET, SOCK_DGRAM, 0); 
    // 使用AF_INET协议族，SOCK_DGRAM数据报套接字，0表示使用默认的协议

    if(sd<0)
    {
        perror("socket()");
        exit(1);
    }

    local_addr.sin_family=AF_INET;
    local_addr.sin_port=htons(atoi(RECVPORT)); // host to network,大小端转换
    // local_addr.sin_addr.s_addr=INADDR_ANY; 
    inet_pton(AF_INET,"0.0.0.0",&local_addr.sin_addr);
    

    if(bind(sd, (struct sockaddr *)&local_addr, sizeof(local_addr))<0)
    // struct sockaddr 各个协议族的实现不同
    {
        perror("bind()");
        exit(1);
    }
    
    remote_addr_len=sizeof(remote_addr); // important

    while (1)
    {
        recvfrom(sd,&rcvbuf,sizeof(rcvbuf),0,(void *)&remote_addr,&remote_addr_len);
        inet_ntop(AF_INET,&remote_addr.sin_addr,ipstr,IPSTRSIZE);

        printf("--MESSAGE FROM %s:%d\n",ipstr,ntohs(remote_addr.sin_port));
        printf("NAME = %s\n",rcvbuf.name); // name单字节传输,不涉及大小端转换
        printf("MATH = %d\n",ntohl(rcvbuf.math)); // math涉及大小端转换
        printf("CHINESE = %d\n",ntohl(rcvbuf.chinese)); 
    }

    close(sd);

    exit(0);
}