#include <stdio.h>

int main()

{

int x,i,cnt=0,m;

scanf("%d",&m);

for(int x1=2;x1<=m;x1++)
{
	x=x1;
	
	while(x>0)
	{
		for(i=2;i<x;i++)
			if (x%i==0)break;
		if(x!=i	)break;
		x=x/10;
	}
	if(x==0)
		cnt++;
}
printf("%d",cnt);
return 0;
}