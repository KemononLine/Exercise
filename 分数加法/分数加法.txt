#include <stdio.h>
int main()
{
	int a,b,c,d,n,x,y;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	int i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&c,&d);
		x=b*d;
		y=a*d+b*c;
		b=x;
		a=y;
		
	}
	int xx=x, yy=y;
	int r;
	while( 1 )
	{
		int r=xx%yy;
		if(r==0)
			break;
		xx=yy; yy=r;
	}
	x=x/yy;
	y=y/yy;
	printf("%d %d",y,x);
	return 0;
}