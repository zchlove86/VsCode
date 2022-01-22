#include<stdio.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    printf("[%d] Begin!\n",getpid());
    pid=fork();
    if(pid<0)
    {
        perror("fork()");
        exit(0);
    }
    if(pid==0)
    {
        printf("[%d]:child is working!\n",getpid());
    }
    else    
    {
        printf("[%d] parent is working !\n",getpid());
    }
    printf("[%d]End!\n",getpid());
    return 0;
}