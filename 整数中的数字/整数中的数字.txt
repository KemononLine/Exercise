#include<stdio.h>
int main()
{
  int xmin,xmax,a,f,c=0,d,e=0,b[10]={0};
  scanf("%d %d",&xmin,&xmax);
  a=xmin;
  while(a<=xmax)
  {
    f=a;
    for(;f>0;)
    {
      d=f%10;
      b[d]++;
      f=f/10;
    }
	a++;
  }
  d=0;
  while(d<10)
  {
    if(c<b[d])
    {
      c=b[d];
      e=d;
    }
	d++;
  }
  printf("%d",e);

  return 0;
}