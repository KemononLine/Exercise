#include <stdio.h>
int main()
{
	int s=0,i,a[10]={0};
	for(i=0;i<=9;i++)
	{
		if(i%2==0)
			a[i]=i*2;
		else
			a[i]=a[i-1]*3;
		if(i%3==0)
			printf("%d",a[i]);
	}
	return 0;
}