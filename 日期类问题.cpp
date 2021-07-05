/*日期类问题*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define isyeap(x) (x%100!=0 && x%4==0)||(x%400==0)?1:0
int MON[13][2]={
                0,0,
                31,31,
                28,29,
                31,31,
                30,30,
                31,31,
                30,30,
                31,31,
                31,31,
                30,30,
                31,31,
                30,30,
                31,31};
using namespace std;

int days[5100][13][32];

struct date{
    int year;
    int month;
    int day;
    void nextDay(){   //结构体函数引用结构体里面的变量，不需要声明
        day++;
        if(day>MON[month][isyeap(year)]){
            day = 1;
            month++;
            if(month>12){
                year++;
                month = 1;
            }
        }
    }
};
void init(){
    date date;
    date.day=1;date.month=1;date.year=0;
    int num_day = 1;
    while(date.year<=5000){
        days[date.year][date.month][date.day] = num_day;
        date.nextDay();
        num_day++;
    }
}
int main()
{
    init();
    int y1,y2,m1,m2,d1,d2;
    scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
    printf("%d",abs(days[y1][m1][d1]-days[y2][m2][d2]));
    return 0;
}
