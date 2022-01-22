#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<glob.h>

#define  PATHSIZE  1024
static int64_t mydu(const char* pathname)
{
    struct stat statres;
    char nextpath[PATHSIZE];
    glob_t globres;

    if(lstat(pathname,&statres)<0)
    {
        perror("lstat()");
        exit(1);
    }
    if(!S_ISDIR(statres.st_mode))
        return statres.st_blocks/2;
    
    strncpy(nextpath,pathname,PATHSIZE);
    strncat(nextpath,"/*",PATHSIZE);
    glob(nextpath,0,NULL,&globres);

    strncpy(nextpath,pathname,PATHSIZE);
    strncat(nextpath,"/.*",PATHSIZE);
    glob(nextpath,0,NULL,&globres);




}
int main(int argc,char *argv[])
{

    printf("%d\n",mydu(argv[1]));
    exit(0);
}