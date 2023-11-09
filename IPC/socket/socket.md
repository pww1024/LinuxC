# SOCKET

## 报式套接字

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

127.0.0.1 环回（loopback）地址,测试与开发
255.255.255.255 广播地址,发送到这个地址的数据包会发送给本地子网上的所有设备


报式套接字
    socket
    bind
    sendto
    rcvfrom
    inet_pton
    inet_ntop
    getsockopt
    setsockopt

    多点通迅: (只能用报式套接字)
        广播(全网广播,子网广播)
        多播/组播
        if_nametoindex

ip ro sh // 查看路由
ifconfig eth0 192.168.1.123 // 将IP地址192.168.1.123分配给网络接口eth0
ip ro add default via 192.168.1.123 // 分配路由
关防火墙 

memset // 使用wireshark查看到栈数据泄露

ttl time to leave 通过的路由器数量，default:Linux64 Windows128

丢包由于阻塞，硬性数据校验

停等式流控，会提高丢包率

TCP握手
    第一次握手（SYN）客户端
    第二次握手（SYN+ACK）服务器 半连接,半连接池
    第三次握手（ACK）客户端
    约定协议,编号
    
    问题:半连接池攻击
    解决:删除半连接池
    (对端ip,port,我端的ip,port,proto + salt) ->hash  --> cookie
    salt由内核产生,每秒一次
    第二加上cookie,第三次需要回cookie   


## 流式套接字

S端
    1.获取SOCKET socket
    2.给SOCKET取得地址 bind
    3.将SOCKET置为监听模式 listen
    4.接受连接 accept --> newsd
    5.收/发消息 serverjob()
    6.关闭 close(newsd,sd)

C端(主动端)
    1.获取SOCKET 
    2.给SOCKET取得地址(bind可省) 
    3.发送连接 conect
    4.收/发消息 fp = fdopen(sd, "r+"); 
    5.关闭
    



