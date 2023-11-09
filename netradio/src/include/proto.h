#ifndef PROTO_H__
#define PROTO_H__

#define DEFAULT_MGROUP "224.2.2.2"
#define DEFAULT_RCVPORT "1989"

#define CHNNR 100
#define LISTCHNID 0 // list id

#define MINCHNID 1
#define MAXCHNID (MINCHNID+CHNNR-1)

#define MSG_CHANNEL_MAX (65536-20-8) // 65536:IP包最大长度 20:IP头部长度 8:UDP头部长度
#define MAX_DATA (MSG_CHANNEL_MAX-sizeof(chnid_t)) // data成员最大长度
#define MAX_ENTRY (MAX_DATA-sizeof(uint16_t)) // 节目单中的内容的最大长度

#define MSG_LIST_MAX (65536-20-8)
#define MAX_LIST (MSG_LIST_MAX-sizeof(chnid_t))

typedef uint8_t chnid_t;

struct msg_channel_st
{									
	chnid_t chnid;							// must between MINCHNID and MAXCHNID
	uint8_t data[1];						// 包中的数据
}__attribute__((packed));					// 不需要对齐


struct msg_listentry_st
{								
	chnid_t chnid;							
	uint16_t len;							// 每个频道内容的大小，用来区分一个节目单中不同频道的内容，不然所有内容连在一起，区分不开。
	uint8_t desc[1];						// 节目的描述信息
}__attribute__((packed));

struct msg_list_st
{
	chnid_t chnid;							// 频道号，必须为 LISTCHNID
	struct msg_listentry_st entry[1];		// 节目单中的内容
}__attribute__((packed));


#endif
