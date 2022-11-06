#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
uint64_t max = 18446744073709551615;
uint64_t mod(uint64_t a, uint64_t b, uint64_t m);
uint64_t amod(uint64_t a, uint64_t m); 
int bit(uint64_t a,int i);
uint64_t plus(uint64_t a, uint64_t b, uint64_t m);
void test(uint64_t a, uint64_t b, uint64_t m) {
#define U64 "%" PRIu64
    printf(U64 " * " U64 " mod " U64 " = " U64 "\n", a, b, m, mod(a, b, m));
}

int main(void) {
    FILE* fp;
    fp = fopen("testexample.txt", "r");
    uint64_t a = 0, b = 0, m = 0, ans = 0;
    uint64_t count = 0;
    rewind(fp);
    while (fscanf(fp, U64 U64 U64 U64, &a, &b, &m, &ans) == 4)
    {
        if (mod(a, b, m) == ans)
        {
            test(a, b, m);
            printf("pass:" U64 "\n", count++);
        }
        else
        {
            test(a, b, m);
            printf("error:" U64 "\n", count++);
            printf("your answer:" U64 "\n" "correct answer:" U64 "\n", mod(a, b, m), ans);
            break;
        }
    }
    fclose(fp);
    return 0;
}
uint64_t mod(uint64_t a, uint64_t b, uint64_t m)
{
    a = amod(a, m);
    b = amod(b, m);
    uint64_t res = 0;
    for (int i = 0; i < 64; i++)
    {
        if (bit(b, i) == 0)
            continue;
        uint64_t ax = a;
        for (int j = 0; j < i; j++)
        {
            ax=plus(ax, ax, m);
        }
        res = plus(res, ax, m);
    }
    return res;
}
uint64_t amod(uint64_t a, uint64_t m)
{  
    uint64_t m1=m;
    while (a >= m)
    {
        while (m1 < (uint64_t)1 << 63 && m1 < a)
        {
            m1 = m1 << 1;
        }
        while (m1 > a && m1 > m)
        {
            m1 = m1 >> 1;
        }
        a -= m1;
    }
    return a;
}
int bit(uint64_t a, int i)
{
    return (a >> i) & 1;
}
uint64_t plus(uint64_t a, uint64_t b, uint64_t m)
{
    a = amod(a, m);
    b = amod(b, m);
    if (a > m - b)
        return a + (b-m);
    else
        return a + b;
}