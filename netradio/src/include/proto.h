#ifdef PROTO_H__
#define PROTO_H__

#include<stdint.h>



#define MGROUP		"224.2.2.2"
#define RCVPORT "2333"

#define CHANNEL 			200
#define LISTCHNID 			0

#define MIN_CHANNEL_ID 		1
#define MSG_CHANNEL_MAX		(65536-20-8)				// 一个频道包的大小:65535 - ip 报头 - udp报头

#define MSG_CHANNEL_MAX 	(65536-20-8)
#define MAX_DATA 			(MSG_CHANNEL_MAX-sizeof(uint8))	
#define MAX_ENTRY 			(MAX_DATA-sizeof(uint16_t))			// 节目单中的内容的最大长度

typedef uint8_t chnid_t;

struct msg_channel_st{									// 频道包	
	chnid_t chnid;										// 频道号
	uint8_t data[1];									// 包中的数据
}__attribute__((packed));								// 不需要对齐


struct msg_listentry_st{								// 节目单中的内容
	chnid_t chnid;										// 频道号
	uint16_t len;										// 每个频道内容的大小，用来区分一个节目单中不同频道的内容，不然所有内容连在一起，区分不开。
	uint8_t desc[1];									// 节目的描述信息
}__attribute__((packed));

struct msg_list_st{										// 节目单包
	chnid_t chnid;										// 频道号，必须为 LISTCHNID
	struct msg_listentry_st entry[1];					// 节目单中的内容
}__attribute__((packed));


#endif
