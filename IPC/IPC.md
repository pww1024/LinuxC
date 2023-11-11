IPC
InterProcess Communication

including
1.pipe
core offers,simplex,self-Synchronization Mechanism

Anomymous pipe
Named pipe

2.XSI->Sys V

    主动端:先发包
    被动端:先收包 先运行

    !ipcs    #ipc show
    
    key:ftok();

    XXXget XXXop XXXctl
    XXX->msg sem shm

    Message Queues
    msgget();
    msgop();
    msgctl();

    Shared Memory Segments


    Semaphore Arrays


3.socket
    流式套接字 SOCKET_STREAM Stream Sockets
    报式套接字 SOCKET_DGRAM Datagram Sockets
