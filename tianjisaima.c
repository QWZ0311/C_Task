#include <stdio.h>
#include <stdlib.h>
#define win 200
void pop(int m[], int len);
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int num = 0, money = 0;
        scanf("%d", &num);
        //读入数据
        int* m1, * m2;
        m1 = (int*)malloc(sizeof(int) * num);
        m2 = (int*)malloc(sizeof(int) * num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &m1[j]);
        }
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &m2[j]);
        }
        pop(m1, num);
        pop(m2, num);
        int count = 0;
        for (int k = 0; k < num; k++)
        {
            if (m2[k] < m1[count])
            {
                count++;
                money += win;
            }
        }
        money -= (num - count) * win;
        printf("%d", money);
    }
    return 0;
}
void pop(int m[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (m[j] < m[j + 1])
            {
                int tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }
}