#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int main()
{
    pid_t childpid;
    int status;
    int retval;

    childpid=fork();//Creating a child process ;
    if(childpid==-1)//Check whether the creation fails;
    {
        perror("fork()");
        exit(-1);
    }
    else if(childpid==0)
    {
        puts("In child process");
        sleep(100);//Let the child process sleep to see what the parent process is doing
    }
    retval=kill(childpid,SIGKILL);//Send SIGKILL to the child process to stop running;
    if(retval)//Determin if a signal has occurred;
    {
        puts("Kill Failed.");
        perror("kill");
        waitpid(childpid,&status,0);
    }
    else
    {
        printf("%d killed\n",childpid);
    }
        
    
    
}