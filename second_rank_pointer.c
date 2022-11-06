#include <stdio.h>
#include <stdlib.h>
void test(int **pp);
int main()
{
    // int a[10][20] = {0}, cnt = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 20; j++)
    //     {
    //         a[i][j] = cnt;
    //         cnt++;
    //     };
    // };
    // int *p[10]={NULL};
    // for(int i =0;i<10;i++){
    //     p[i]=a[i];
    // };
    // test(p);
    int cnt = 0;
    int **pp = (int **)malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        pp[i] = (int *)malloc(sizeof(int) * 20);
    };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            pp[i][j] = cnt;
            cnt++;
        };
    };
    test(pp);

    return 0;
}
void test(int **pp)
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            printf("%3d,", pp[i][j]);
        };
        puts("");
    };
}