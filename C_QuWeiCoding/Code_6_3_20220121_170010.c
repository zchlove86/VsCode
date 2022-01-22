#include<stdio.h>
void main()
{
    int x,y,z;
        for(x=0;x<=1;x++)
            for(y=0;y<=1;y++)
                for(z=0;z<=1;z++)
                    if((x&&!y||!x&&y)&&(y&&!z||!y&&z)&&(z&&x==0&&y==0||!z&&(x+y)!=0))
                    {
                        printf("%s\n",x?"ture":"flase");
                        printf("%s\n",y?"ture":"flase");
                        printf("%s\n",z?"ture":"flase");

                    }
                   
}