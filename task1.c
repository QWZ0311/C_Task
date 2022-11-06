#include <stdio.h>
int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int flag[n + 1], sum = n, i = 0, count = 0;
    for (int j = 1; j <= n; j++)
        flag[j] = 0;
    while (sum >= m)
    {
        i=(i+1)%n;
        if (flag[i] == 1)
            continue;
        else
        {
            count++;
            if (count == m)
            {
                sum--;
                flag[i] = 1;
                count = 0;
            }
        }
    }
    if (flag[k])
        printf("YES");
    else
        printf("NO");

    return 0;
}