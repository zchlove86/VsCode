/*tax*/
#include<stdio.h>
#define TAXBASH 3500
typedef struct 
{
    /* data */
    long start;
    long end;
    double taxrate;
}TAXTABLE;
TAXTABLE Taxtable[]={{0,1500,0.03},{1500,4500,0.10},{4500,9000,0.20}};
double CaculateTax(long profit)
{
    int i;
    double tax=0.0;
    profit-=TAXBASH;
    for(i=0;i<sizeof(Taxtable)/sizeof(TAXTABLE);i++)
    {
        if(profit>Taxtable[i].start)
        {
            if(profit>Taxtable[i].end)
                tax+=(Taxtable[i].end-Taxtable[i].start)*Taxtable[i].taxrate;
            else
                tax+=(profit-Taxtable[i].start)*Taxtable[i].taxrate;
        }
        profit-=Taxtable[i].end;
    }
    return tax;
}
int main()
{
    long profit;
    double tax;
    printf("Please enter the amount of personal income:");
    scanf("%ld",&profit);
    tax=CaculateTax(profit);
    printf("%12.2f\n",tax);

    return 0;
}
