#include<stdio.h>
#include<limits.h>
#include<string.h>
int main(int argc,const char *argv[])
{
    char a[4]={'h','e','l','o'};

    printf("the number of types a = %d \n",sizeof(a));
    printf("the number of types a = %d \n",sizeof("hello"));
    printf("%s \n",a[4]);
    return 0;
}