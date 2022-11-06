#include <stdio.h>
int main()
{
    int year=0;
    float money=1000000.;
    do{
        year++;
        money*=1.08;
        money-=100000;
        printf("year:%d,money:%.2f\n",year,money);
    }while(money>0);
    printf("need %d year",year);
    return 0;
} 