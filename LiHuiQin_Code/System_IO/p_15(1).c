/*Standard IO relys on System IO;
(1)file descriptor:In fact ,it's a int(number)
file operation  :open()  close()  read()  write()  lseek()

    inode;
    #include<sys/types.h>
    #include<sys/stat.h>
    #include<fcntl.h>

    int open(const char *pathname,int flags);
    int open(const char *pathname,int flags,mode_t mode);
    int creat(const char *pathname,mode_t mode);

    ssize_t read(int fd,void *buf,size_t count);//read from a file descriptor;


(2)effiency problem about IO
(3)file sharing
(4)atomic operation
        //indivisible   ;resolve competition and conflict
(5)rediction in the program:dup dup2
(6)synchronization(sync):  sync() fsync() fdatasync()

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#define BUFSIZE 1024
int main()
{
    char buf[BUFSIZE];
    int sfd, dfd,len;
    sfd = open("atmp", O_RDONLY);
    if (sfd < 0)
    {
        perror("open()");
        exit(1);
    }
    dfd = open("atmp2", O_WRONLY | O_CREAT, O_TRUNC, 1024);
    if (dfd < 0)
    {
        close(sfd);
        perror("open()");
        exit(1);
    }

    while (1)
    {
        len=read(sfd,buf,BUFSIZE);
        puts(buf);  
        if(len<0)
        {
            perror("read()");
            break;
        }
        if(len==0)
            break;
        
        int ret=write(dfd,buf,len);
    }

    close(dfd);
    close(sfd);

    exit(0);
}