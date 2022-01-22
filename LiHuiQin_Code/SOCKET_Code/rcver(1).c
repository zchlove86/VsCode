#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<arpa/inet.h>

#include"p_129.h"
#define IPSTRSIZE 40

int main()
{
    int sd;
    struct sockaddr_in laddr,raddr;
    struct msg_st rbuf;
    socklen_t raddr_len;
    char ipstr[IPSTRSIZE];

    sd=socket(AF_INET,SOCK_DGRAM,0);//0 means default  //IPPROTO_UDP
    if(sd<0)
    {
        perror("socket()");
        exit(1);
    }
    if(bind(sd,(void *)&laddr,sizeof(laddr))<0)//notion the use of (void *),because the pointer is disaffinity
    {
        perror("bind()");
        exit(1);
    }
    laddr.sin_family=AF_INET;
    laddr.sin_port=htons(atoi(RCVPORT));
    inet_pton(AF_INET,"127.0.0.1",&laddr.sin_addr);/*"0.0.0.0" means the any adress.
    dian fen shi zhuan huan cheng pton*/
    /*!!!!*/
    raddr_len=sizeof(raddr);//Initial
    while(1)
    {
        recvfrom(sd,&rbuf,sizeof(rbuf),0,(void *)&raddr,&raddr_len);
        inet_ntop(AF_INET,&raddr.sin_addr,ipstr,IPSTRSIZE);
        printf("---MESSAGE FROM %S:%d---\n",raddr.sin_addr,ntohs(raddr.sin_port));
        printf("NAME = %s\n",rbuf.name);
        printf("MATH = %s\n",ntohl(rbuf.math));
        printf("CHINESE = %d\n",ntohl(rbuf.chinese));
    }
    
    close();
    return 0;
}