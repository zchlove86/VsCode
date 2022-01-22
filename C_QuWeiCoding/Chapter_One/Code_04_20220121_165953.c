#include<stdio.h>

int main()
{
    int i,j,temp;
    for(i=0;i<=9;i++)
        for(j=0;j<=9;j++)
        {
            if(i!=j)
            {
                int k=i*1000+i*100+j*10+j;
                for(temp=1;temp<=99;temp++)
                    if(temp*temp==k)
                        printf("the number is :%d\n",k);
            }
        }
        return 0;

}