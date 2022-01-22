#include<stdio.h>
int main()
{
    int i,j,x,flag=0;//flag is the symble of contral int the circle;
    for(i=23;flag==0;i+=2)
    {
        for(j=1,x=i;j<=4&&x>=11;j++)
            if((x+1)%(j+1)==0)
                x-=(x+1)/(j+1);
            else
            {
                x=0;
                break;
            }
            if(j==5&&x==11)
            {
                printf("the number of fish in the bolt is:%d\n",i);
                flag=1;//set the value of the flag is 1 to stop circle;
            }
    
    }
    return 0;

}