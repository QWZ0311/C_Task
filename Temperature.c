#include <stdio.h>
void temperature(float tem);
int main()
{
    float tem =0;
    printf("请输入:");
    scanf("%f",&tem);
    temperature(tem);
    return 0;
}
void temperature(float tem)
{
    float s=0,k=0;
    s=5.0/9.0*(tem-32.);
    k=tem+273.16;
    printf("摄氏温度为%f\n",s);
    printf("开氏温度为%f\n",k);
}