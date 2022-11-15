//不支持空格以及未完成负数
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct stack
{
    char data[100];
    int top;
} stack;
typedef struct stack2
{
    double data[100];
    int top;
} stack2;
void calculate(stack2 *p, char a);
int rank(char a);
int main()
{
    char list[100], in[100];
    fgets(in, 100, stdin);
    int i = 0, count = -1;
    stack s;
    s.top = -1;
    if (isdigit(in[i]) || (i == 0 && in[i] == '-'))
        list[++count] = in[i];
    else
        s.data[++s.top] = in[i];
    i++;
    while (in[i] != '\n')
    {
        if (isdigit(in[i]) || (!isdigit(in[i - 1])) && in[i] == '-') //若为数字，直接加入数组
            list[++count] = in[i];
        else //运算符进栈
        {
            list[++count] = ' ';
            s.data[++s.top] = in[i];
            if (s.data[s.top] == ')')
            {
                s.top--;
                while (s.data[s.top] != '(')
                {
                    list[++count] = s.data[s.top];
                    s.top--;
                }
                s.top--;
            }
            else if (rank(s.data[s.top]) <= rank(s.data[s.top - 1]) && s.data[s.top] != '(')
            {
                while (rank(s.top) <= rank(s.data[s.top - 1]) && s.top != 0)
                {
                    list[++count] = s.data[s.top - 1];
                    s.data[s.top - 1] = s.data[s.top];
                    s.top--;
                }
            }
        }
        i++;
    }
    while (s.top != -1)
    {
        list[++count] = s.data[s.top];
        s.top--;
    }
    list[++count] = '\0';
    printf("%s\n", list); //转换为后缀表达式

    stack2 out; //读入并计算后缀表达式
    stack2 *p;
    p = &out;
    out.top = -1;
    i = 0;
    int flag = 1, num = 0;
    // if (list[i] = '-' || isdigit(list[i])) //先读入第一位
    // {
    //     // if (list[i] == '-')
    //     // {
    //     //     flag = -1;
    //     //     i++;
    //     // }
    while (isdigit(list[i]))
    {
        num = num * 10 + (double)list[i] - 48;
        i++;
    }
    out.data[++out.top] = flag * num;
    num = 0;
    flag = 1;
    // }
    while (list[i] != '\0')
    {
        if (isdigit(list[i]))
        {
            while (isdigit(list[i]))
            {
                num = num * 10 + (double)list[i] - 48;
                i++;
            }
            out.data[++out.top] = flag * num;
            num = 0;
            flag = 1;
            i--;
        }
        else if ((!isdigit(list[i])) && (list[i] != ' '))
            calculate(p, list[i]);
        i++;
    }
    printf("%f", out.data[out.top]);

    return 0;
}
void calculate(stack2 *p, char a)
{
    switch (a)
    {
    case '+':
        p->data[p->top - 1] = p->data[p->top] + p->data[p->top - 1];
        p->top--;
        break;
    case '-':
        p->data[p->top - 1] = p->data[p->top - 1] - p->data[p->top];
        p->top--;
        break;
    case '*':
        p->data[p->top - 1] = p->data[p->top] * p->data[p->top - 1];
        p->top--;
        break;
    case '/':
        p->data[p->top - 1] = p->data[p->top - 1] / p->data[p->top];
        p->top--;
        break;
    }
}
int rank(char a)
{
    switch (a)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '(':
        return 0;
    }
}