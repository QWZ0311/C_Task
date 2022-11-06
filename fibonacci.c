#include <stdio.h>
int fibonacci(int n);
int main()
{
    int a = 0;
    scanf("%d", &a);
    printf("%d", fibonacci(a));
    return 0;
}
int fibonacci(int n)
{
    if (n <= 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}