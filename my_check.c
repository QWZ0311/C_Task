#include <stdio.h>
int main()
{
    int m,n,max,count=1;
    scanf("%d %d",&m,&n);
    if(m<n){
        max=m;
        m=n;
        n=max;
    };
    max=n;
    while (max%m!=0)
    {
        max=count*n;
        count++;
    };
    while(m!=0){
        count=m;
        m=n%m;
        n=count;
    }
    printf("%d %d\n",n,max);
    return 0;
}