#include <stdio.h>
int main ()
{
    double t=0.,x,out=1.,sum=1.;
    scanf("%lf",&x);
    while(abs(sum)>=0.00001){
        t++;
        sum*=x/t;
        out+=sum;
    };
    printf("%f",out);
    return 0;
}