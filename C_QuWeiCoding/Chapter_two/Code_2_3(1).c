#include<stdio.h>
void print(int s[]);
int judge(int c[]);
int j=0;

int main()
{
    int sweet[10]={10,2,8,22,16,4,10,6,14,20};
    int i,t[10];
    printf("child 1 2 3 4 5 6 7 8 9 10\n");

    print(sweet);
    while(judge(sweet))
    {
        for(i=0;i<10;i++)
        {
            if(sweet[i]%2==0)
                t[i]=sweet[i]=sweet[i]/2;
            else    
                t[i]=sweet[i]=(sweet[i]+1)/2;
        }
        for(i=0;i<9;i++)
            sweet[i+1]=sweet[i+1]+t[i];
        sweet[0]+=t[9];
        print(sweet);
    }
}
int judge(int c[])
{
    int i;
    for(i=0;i<10;i++)
        if(c[0]!=c[i])
            return 1;
    return 0;
}
void print(int s[])
{
    int k;
    for(k=0;k<10;k++)
        printf("%4d",s[k]);
    printf("\n");
}