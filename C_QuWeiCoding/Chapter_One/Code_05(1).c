#include<stdio.h>

int main()
{
    int fib1=1,fib2=1,fib;
    int i;
    printf("%12d%12d",fib1,fib2);
    for(i=3;i<=30;i++)
    {
        fib=fib1+fib2;
        printf("%12d",fib);
        if(i%4==0)
            printf("\n");
        
        fib2=fib1;
        fib1=fib;
        
    }
}