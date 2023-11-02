#ifndef PROTO_H__
#define PROTO_H__

#define RECVPORT "1989" // 1024以下的端口号需要root权限,多半预留给系统使用

#define NAMESIZE 11 // 姓名长度

#define IPSTRSIZE 40 

struct msg_st
{
    uint8_t name[NAMESIZE]; // no char *
    uint32_t math;
    uint32_t chinese;
} __attribute__((packed)); // 




#endif 