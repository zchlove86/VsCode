﻿//insuccess(202201)
#include<stdio.h>
#include<netinet/in.h>

#define MAXLINE 4096


int main(int argc,char* argv[])
{
    int sockfd,n;
    char recvline[MAXLINE+1];
    struct sockaddr_in servaddr;
    if(argc!=2)
    {
        printf("usage:a.out<IPaddress>");
    }
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
        printf("socker error");
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(13);/*daytime server*/
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0)
        printf("iner_pton error for %s",argv[1]);

    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
        printf("connect error");

    while((n=read(sockfd,recvline,MAXLINE))>0)
    {
        recvline[n]=0;//null terminate
        if(fputs(recvline,stdout)==EOF)
            printf("fputs error");
    }
    if(n<0)
        printf("read error");
    return 0;
}