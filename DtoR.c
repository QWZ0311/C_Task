#include <stdio.h>
void to(int n, int r);
char num[17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    if (n >= 0)
        to(n, r);
    else
        return 0;
    return 0;
}
void to(int n, int r)
{

    if (n < r)
        printf("%c", num[n]);
    else
    {
        to(n / r, r);
        printf("%c", num[n % r]);
    }
}