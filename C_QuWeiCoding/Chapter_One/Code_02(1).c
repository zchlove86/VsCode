/*borrow books ,now XiaoMing has 5 books; A B C three friend to borrow these books.
If each person can only borrow one book per day.How many ways are there?*/
#include<stdio.h>
int main()
{
    int a,b,c,i=0;
    printf("The isbn chosen by A/B/C is:\n ");
    for(a=1;a<=5;a++)
        for(b=1;b<=5;b++)
            for(c=1;c<=5;c++)
                if(a!=b&&b!=c&&a!=c)
                {
                    printf("A:%2d B:%2d C:%2d",a,b,c);
                    i++;
                    if(i%4==0)
                        printf("\n");
                   
                }
                 printf("the number of i is :%d\n",i);
    return 0;
}