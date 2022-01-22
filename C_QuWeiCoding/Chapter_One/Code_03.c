#include<stdio.h>

typedef struct date
{
    int year;
    int month;
    int day;
} DATE;
int countDay(DATE);
int Ryear(int);

void main()
{
    DATE today;
    int totalDay;
    int result;
    puts("please input date,Year Month and Day:\n");
    scanf("%d-%d-%d",&today.year,&today.month,&today.day);
    
    totalDay=countDay(today);

    result=totalDay%5;
    if(result>0&&result<4)
        printf("Fishing");
    else
        printf("sun and fishnet!");
    return ;
}
int Ryear(int year)
{
    if((year%4==0))
        return 1;
    else 
        return 0;
}
int countDay(DATE currentDay)
{ 
    int perMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDay=0,year,i;
    for(year=1990;year<currentDay.year;year++)
    {
        if(Ryear(year))
            totalDay=totalDay+366;
        else    
            totalDay=totalDay+365;
    }
    if(Ryear(currentDay.year))
        perMonth[2]+=1;
    for(i=0;i<currentDay.month;i++)
        totalDay+=perMonth[i];

    totalDay+=currentDay.day;
    return totalDay;
}


