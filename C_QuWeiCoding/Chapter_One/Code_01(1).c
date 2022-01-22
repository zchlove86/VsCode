/*fun and useful*/
/*methord of exhaustion   and  triple circle methord
cock/5 hen/3 3chicken/1
now 100$ buy 100(cock+hen+chicken) 

*/
#include<stdio.h>
int main()
{
    int cock,hen,chicken;
    for(cock=0;cock<=20;cock++)
        for(hen=0;hen<=33;hen++)
            for(chicken=0;chicken<=100;chicken++)
            {
                if((5*cock+3*hen+chicken/3.0==100)&&(cock+hen+chicken==100))
                printf("cock=%2d,hen=%2d,chicken=%2d\n",cock,hen,chicken);
            }
    return 0;
}