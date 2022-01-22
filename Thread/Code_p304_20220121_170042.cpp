#include<iostream>
#include<unistd.h>
#include<stdio.h>

using namespace std;
int main()
{
    pid_t fpid;
    int count=0;
    fpid=fork();
    if(fpid<0)
        cout<<"Failed to fork.";
    else if(fpid==0)
    {
        cout<<"I am the child process, my pid is "<<getpid()<<endl;
        count++;
    }
    else 
    {
        cout<<"I am the parent process,my pid is "<<getpid()<<endl;
        cout<<"fpid = "<<fpid<<endl;
        count++;
    }
    printf("count:%d\n",count);
    return 0;
}