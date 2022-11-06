#include <stdio.h>
#include <stdlib.h>
void test(int **pp);
int main()
{
   int **pp = (int **)malloc(sizeof(int*) * 10);
   for (int i = 0; i < 10; i++)
   {
      pp[i] = (int *)malloc(sizeof(int) * 20);
   };
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 20; j++)
      {
         pp[i][j] = i * 20 + j;
      };
   };
   pp[2][2] = 10;
   printf("%d", pp[2][2]);
   return 0;
}
