


报式套接字

    被动端(先运行)
    1.取得SOCKET
    2.给SOCKET取得地址
    3.收/发消息
    4.关闭SOCKET

    主动端
    1.取得SOCKET
    2.给SOCKET取得地址(可省略)
    3.发/收消息
    4.关闭SOCKET

struct sockaddr_in 
{
    sa_family_t    sin_family; /* address family: AF_INET */
    in_port_t      sin_port;   /* port in network byte order */
    struct in_addr sin_addr;   /* internet address */
};

/* Internet address. */
struct in_addr {
    uint32_t       s_addr;     /* address in network byte order */
};

in_addr中的s_addr属性是uint32_t类型的一大整数
使用inet_pton将点分式ip地址转换成大整数
"0.0.0.0" any address,转换成本机地址

recv() 流式
recvfrom() 报式

netstat -anu // u代表udp,
-ant // t代表tcp

send() 流式
sendto() 报式

int inet_pton(int af, const char *src, void *dst); // 从点分式到大整数

