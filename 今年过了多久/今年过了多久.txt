#include <stdio.h>
int main()
{
	int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,d,r=0,i;
	scanf("%d%d%d",&y,&m,&d);
	if(y%400==0 || (y%4==0 && y %100 != 0))
		mdays[1] = 29;
	
	for(i = 0; i < m-1; i ++)
		r+=mdays[i];
	r+=d;
	printf("%d\n",r);
	return 0;
}