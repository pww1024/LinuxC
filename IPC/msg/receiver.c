#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#include"proto.h"

int main()
{
    key_t key;
    int msgid;
    struct msg_st rbuf;

    key = ftok(KEYPATH,KEYPROJ);
    if (key<0)
    {
        perror("ftok");
        exit(1);
    }   

    if(msgget(key,IPC_CREAT|0666)<0)
    {
        perror("msgget");
        exit(1);
    }

    while(1)
    {
        msgrcv(msgid,&rbuf,sizeof(rbuf)-sizeof(long),0,0); // 
        fprintf(stdout,"name : %s ",rbuf.name);
        fprintf(stdout,"chinese : %d ",rbuf.chinese);
        fprintf(stdout,"math : %d\n",rbuf.math);
        fflush(NULL);
    }

    msgctl(msgid,IPC_RMID,0); //销毁当前实例

    exit(0);
}