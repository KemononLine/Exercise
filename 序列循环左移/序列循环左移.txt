#include <stdio.h>

int main()
{
	int n,i;
	int x,y;
	scanf("%d\n",&n);
	scanf("%d",&x);		
	for (i=1;i<=n-1;i++)
	{
		scanf("%d", &y);
		printf("%d ", y);
	}
	printf("%d\n",x);
	return 0;
}
