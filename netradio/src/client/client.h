#ifndef PROTO_H__
#define PROTO_H__

#define DEFAULT_MGROUP "224.2.2.2"
#define DEFAULT_RCVPORT "1989"

#define CHNNR 100
#define LISTCHNID 0

#define MINCHNID 1
#define MAXCHNID (MINCHNID+CHNNR-1)

#define MSG_CHANNEL_MAX (65536-20-8) // 65536:IP包最大长度 20:IP头部长度 8:UDP头部长度
#define MAX_DATA (MSG_CHANNEL_MAX-sizeof(chnid_t))

struct msg_channel_st 
{
    chnid_t chnid;
    uint8_t data[1];
}__attribute__((packed));



#endif