#include<stdio.h>
int main()
{
	int sum,x,x1;
	scanf("%d",&x);
	for(sum=0,x1=1;x1<=x;x1++)
	{
	if(x%x1==0)
		sum+=x1;
	}

	printf("%d",sum);
	return 0;

}