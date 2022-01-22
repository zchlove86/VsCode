#include<stdio.h>
int main(int argc,const char *argv[])
{
    if(argc==0)
        return -1;
    printf("The program name is: %s\n",argv[0]);
    argc=10;
    int i;
    for(i=1;i<argc;i++)
    {
        printf("arg %d: %s\n",i,argv[i]);
    }
    
    argv[0]="hello";
    argv[1]="world";

    argv=NULL;
    

    return 0;
}