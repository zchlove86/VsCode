#include <stdio.h>
#include <math.h>
int main()
{
    int number,i;
    printf("Please input a number: \n");
    scanf("%d",&number);
    for(i=2;i<number;i++)
    {
        if(number%i==0)
        {
            printf("it's not a prime number.");
        }
        else  
            printf("it's  a prime number.");  
    }
    
    return 0;
}