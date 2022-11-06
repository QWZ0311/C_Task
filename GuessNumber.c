//猜数
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(0));
    int a = 0, count = 0;
    int b = rand() % 100;
    printf("请输入：");
    scanf("%d", &a);
    count++;
    while (a != b)
    {
        if (a > b)
        {
            printf("大了\n");
        }
        else
        {
            printf("小了\n");
        };
        count++;
        printf("请输入：");
        scanf("%d", &a);
    };
    printf("恭喜，猜中了，你花了%d次", count);
    return 0;
}
