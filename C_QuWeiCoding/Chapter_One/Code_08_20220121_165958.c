/*Bubble sort*/
#include<stdio.h>
#define N 10
int main()
{
    int i,j,t,a[N],count=0;
    printf("Please initialize a[N]:\n");
    for(j=0;j<N;j++)
        scanf("%d",&a[j]);
    // int a[10]={5,3,9,6,8,2,7,5,4,2};
    for(i=1;i<=N-1;i++)
        for(j=0;j<N-1;j++)
            if(a[j]>a[j+1])
            {
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
    printf("After the bubble sort,the array elements are:\n");
    for(i=0;i<N;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}