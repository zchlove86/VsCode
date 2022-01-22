/*stat
int stat(const char *path,struct stat *buf);
int stat(int fd,struct stat *buf);
int lstat(const char *path,structstat *buf);




*/
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>


static int flen(const char *fname)
{
    struct stat statres;
    if(stat(fname,&statres)<0)
    {
        perror("stat()");
        exit(1);
    }
    return statres.st_size;
}
int main(int argc,char *argv[])
{
    //char *buf="atmp";
    //char buf[10];

    // puts("intput the name of a file :\n");
    // scanf("%s\n",buf);
    // printf("%s\n",buf);
    //printf("%d\n",flen(buf));
    printf("%d\n",flen(argv[1]));
    return 0;
}