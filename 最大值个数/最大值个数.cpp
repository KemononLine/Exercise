#include<stdio.h>
int main()
{
	int n,x;
	int max=0,cnt=0;	
	scanf("%d",&n);
	for(;n>0;n--)
	{
		scanf("%d",&x);
		if(x==max)
		    cnt++;
		if(x>max)
		{
			cnt=0;
			max=x;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}