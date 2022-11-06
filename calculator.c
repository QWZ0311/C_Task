#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
typedef struct StackNode //节点
{
    char node;
    struct StackNode* next;
} StackNode, * LinkStackPtr;
typedef struct LinkStack //栈
{
    LinkStackPtr top;
    int count;
} LinkStack;
void Push(LinkStack* S, char e)
{
    LinkStackPtr s;
    s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->node = e;
    s->next = S->top;
    S->top = s;
    S->count++;
}
void Pop(LinkStack* S, char* e) //运算符出栈
{
    LinkStackPtr p;
    if (S->count == 0)
        return;
    *e = S->top->node;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
}
int check(LinkStack* S, char* e)
{
    if (S->top == NULL)
        return 0;
    int rank1, rank2;
    rank1 = rank(S->top->node);
    rank2 = rank(*e);
    if (rank1 < rank2 || rank2==0)
        return 0;
    else
        return 1;
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
int main()
{
    LinkStack* numstack, * oprestack;
    numstack = (LinkStack*)malloc(sizeof(LinkStack));
    oprestack = (LinkStack*)malloc(sizeof(LinkStack));
    numstack->count = 0;
    numstack->top = NULL;
    oprestack->count = 0;
    oprestack->top = NULL;
    char line[20], * ep, e;
    ep = &e;
    int i = 0, flag = 0;
    fgets(line, 100, stdin);
    while (line[i] != '\n')
    {
        e = line[i];
        if (isdigit(e))
            Push(numstack, e);
        else
        {
            if (e == ')') //如果是右括号
            {
                while (1)
                {
                    Pop(oprestack, ep);
                    if (e == '(')
                        break;
                    else
                        Push(numstack, e);
                }
            }
            else
            {
                while (check(oprestack, ep)) //如果优先级不大于
                {
                    Pop(oprestack, ep);
                    Push(numstack, e);
                    e = line[i];
                }
                Push(oprestack, e);
            }
        }
        i++;
    }
    while (oprestack->count != 0)
    {
        Pop(oprestack, ep);
        Push(numstack, e);
    }
    char out[40];
    for (int i = 0; i < 40; i++)
    {
        out[i] = '\0';
    }
    while (numstack->count != 0)
    {
            out[(numstack->count-1)*2] = numstack->top->node;
            out[(numstack->count - 1) * 2 + 1] = '\x20';
            Pop(numstack, ep);
    }
    printf("%s", out);
    return 0;
}
