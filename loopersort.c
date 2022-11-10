#include <stdio.h>
#include <ctype.h>

void Bubble_sort(int arr[], int size)
{
    int j, i, tem;
    for (i = 0; i < size - 1; i++)
    {
        int count = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
                count = 1;

            }
        }
        if (count == 0)
            break;
    }

}
int main()
{
    int n = 0;
    scanf("%d", &n);
    char a[100];
    getchar();
    for (int i = 0; i < n; i++)
    {
        fgets(a, 100, stdin);
        int j = 0, num = 0, number[100], count = 0, flag = 0;
        while (a[j] != '\0')
        {
            if (isdigit(a[j]) == 0)
            {
                if (a[j] == '\x20')
                {
                    j++;
                    continue;
                }
                number[count++] = num;
                num = 0;
                if (a[j] == ',')
                {
                    if (flag)    //如果是区间
                    {
                        flag = 0;
                        int x1 = number[count - 2], x2 = number[count - 1];
                        count--;
                        for (int k = x1 + 1; k <= x2; k++)
                            number[count++] = k;
                    }
                }
                else    //检测到存在区间
                    flag = 1;
            }
            else   //如果是数字
                num = num * 10 + (int)a[j] - 48;
            j++;
        }
        number[count++] = num;
        num = 0;
        if (flag)    //如果是区间
        {
            flag = 0;
            int x1 = number[count - 2], x2 = number[count - 1];
            count--;
            for (int k = x1 + 1; k <= x2; k++)
                number[count++] = k;
        }
        Bubble_sort(number, count);
        printf("%d", number[0]);
        for (int k = 1; k < count; k++)
        {
            if (number[k] == number[k + 1])
                continue;
            printf(",%d", number[k]);
        }
        printf("\n");
    }
}