#include <stdio.h>
typedef struct date
{
 int year;
 int month;
 int day;
}
DATE;
int leapyear(int year)
{
 if((year%4==0 && year%100!=0) || year%400==0)
  return 1;
 else
  return 0;
}
int compare(DATE *d1, DATE *d2)    //如果第一个日期比第二个日期大，交换日期
{
 DATE *tmp;
 if(d1->year == d2->year)    //年数相等
 {
  if(d1->month > d2->month)   //月数相等
  {
   tmp = d1;
   d1 = d2;
   d2 = d1;
  }
  else if(d1->month == d2->month)  //日期相等
  {
   if(d1->day > d2->day)
   {
    tmp = d1;
    d1 = d2;
    d2 = d1;
   }
  }
 }
 else if(d1->year > d2->year)
 {
  tmp = d1;
  d1 = d2;
  d2 = tmp;
 }
 return 0;
}
int diff(DATE *date1, DATE *date2)
{
 int i;
 int diff = 0;
 const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 if(date1->year == date2->year)
 {
  if(date1->month == date2->month)
  {
   diff = date2->day - date1->day;
  }
  else
  {
   for(i=date1->month+1; i<date2->month; i++)
   {
    diff += month[i];
   }
   diff += month[date1->month] - date1->day + date2->day;
   if(leapyear(date1->year))
    if(date1->month <=2 && date2->month >2)
     diff++;
  }
 }
 else
 {
  for(i=date1->year+1; i<date2->year; i++)
  {
   if(leapyear(i))
    diff += 366;
   else
    diff += 365;
  }
  for(i=date1->month+1; i<=12; i++)    //date1距离年末多少天
  {
   diff += month[i];
  }
  diff += month[date1->month] - date1->day;
  if(date1->month <= 2)
   if(leapyear(date1->year))
    diff++;
  for(i=1; i<date2->month; i++)     //date2距离年初多少天
  {
   diff += month[i];
  }
  diff += date2->day;
  if(date1->month > 2)
   if(leapyear(date2->year))
    diff++;
 }
 return diff;
}
int main()
{
 int days = 0;
 DATE day1, day2;
 DATE *date1, *date2;
 date1 = &day1;
 date2 = &day2;
 scanf("%d %d %d",&(date1->year), &(date1->month), &(date1->day));
 scanf("%d %d %d",&date2->year, &date2->month, &date2->day);
 compare(date1, date2);
 days = diff(date1, date2);
 printf("%d\n",days);
 return 0;
}