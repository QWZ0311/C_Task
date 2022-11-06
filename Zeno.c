#include <stdio.h>
int main ()
{
    int time =0 ,t=0;
    float f=0.5,meters=0.0;
    scanf("%d",&time);
    meters+=f;
    f/=2.0;
    for (t=1;t<=time;meters+=f,f/=2.0,t+=1)
    {
        printf("time:%d,meters:%f\n",t,meters);
    };
    return 0;
}