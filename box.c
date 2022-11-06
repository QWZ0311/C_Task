#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}
int main()
{
    int n, W, height = 0, sum = 0, count = 0;
    scanf("%d %d", &n, &W);
    int *w = (int *)malloc(sizeof(int) * n);
    int *flag = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        flag[i] = 0;
        scanf("%d", &w[i]);
    };
    bubbleSort(w, n);
    while (count < n)
    {
        if (flag[count] == 0 && sum == 0)
        {
            sum += w[count];
            flag[count] = 1;
            count++;
        }
        else
        {
            count++;
            continue;
        };
        for (int i = count; i < n; i++)
        {
            if (flag[i] == 0 && sum + w[i] <= W)
            {
                sum += w[i];
                flag[i]=1;
            };
        };
        sum = 0;
        height++;
    }
    printf("%d", height);
    return 0;
}