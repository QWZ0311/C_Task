#include <stdio.h>
#include <stdlib.h>

typedef struct row
{
    int number;
    struct row *next;
} row;
int main()
{
    row *head = NULL, *current, *prev;
    int n, m;
    scanf("%d %d", &n, &m);
    int sum = n, count = 0;
    for (int i = 1; i <= n; i++)
    {
        current = (row *)malloc(sizeof(row));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->number = i;
        current->next = NULL;
        prev = current;
    }
    prev->next = head;
    current = head;
    while (sum >= m)
    {
        for (int i = 0; i < m-1; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = prev->next->next;
        // free(current);
        // printf("%d\n",current->number);
        current = current->next;
        sum--;
    }
    for (int i = 0; i < m-1; i++)
    {
        printf("%d", current->number);
        current=current->next;
    }
    return 0;
}