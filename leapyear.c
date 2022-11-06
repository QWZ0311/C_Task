#include <stdio.h>
long int daynum(int yy, int mm, int dd);
int isleap(int yy);
int week(long int daynum);
int main()
{
    int yy1, yy2, mm1, mm2, dd1, dd2;
    scanf("%d-%d-%d", &yy1, &mm1, &dd1);
    scanf("%d-%d-%d", &yy2, &mm2, &dd2);
    printf("%d-%d-%d:%ld,%d\n",yy1,mm1,dd1,daynum(yy1,mm1,dd1),week(daynum(yy1,mm1,dd1)));
    printf("%d-%d-%d:%ld,%d\n",yy2,mm2,dd2,daynum(yy2,mm2,dd2),week(daynum(yy2,mm2,dd2)));
    printf("%f",(daynum(yy2,mm2,dd2)-daynum(yy1,mm1,dd1))/365.24);
    return 0;
}
int isleap(int yy)
{
    if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0)
        return 1;
    else
        return 0;
}
long int daynum(int yy, int mm, int dd)
{
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int daysum = 0;
    for (int i = 1; i < yy ; i++)
    {
        if (isleap(i))
            daysum += 366;
        else
            daysum += 365;
    }
    for (int i = 1; i < mm; i++)
    {
        if (isleap(yy) && i == 2)
            daysum += 29;
        else
            daysum += month[i];
    }
    daysum += dd;
    return daysum;
}
int week(long int daynum)
{
    return daynum % 7;
}