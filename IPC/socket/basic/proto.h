#ifndef PROTO_H__
#define PROTO_H__

#define RECVPORT "1989" // 1024以下的端口号需要root权限,多半预留给系统使用
#define NAMESIZE 11 // name数组长度
#define IPSTRSIZE 40 
#define NAMEMAX (512-8-8) 
// 512是udp包的推荐长度,8是math和chinese的长度,第二个8是报头的长度

struct msg_st
{
    uint8_t name[NAMESIZE]; // no char *
    uint32_t math;
    uint32_t chinese;
} __attribute__((packed)); // 




#endif 