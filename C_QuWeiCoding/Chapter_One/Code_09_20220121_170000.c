/*bisearch*/
#include<stdio.h>
int main()
{
    int i,a[10]={-3,4,7,9,13,45,67,89,100,180};
    int low=0,heigh=9,mid,k=-1,m;
    printf("the array elements are:\n");
    for(i=0;i<10;i++)
        printf("%d  ",a[i]);
    printf("\n");
    scanf("%d",&m);
    while(low<=heigh)
    {
        mid=(low+heigh)/2;
        if(m<a[mid])
            heigh=mid-1;
        else if(m>a[mid])
               low=mid-1;
        else  
            {
                k=mid;
                break;
            }
    }
    if(k>=0)
        printf("m=%d,index =%d\n",m,k);
    else    
        printf("Not be found!\n");
}