#include <stdio.h>
int main()
{
	int x,xx;
	int sum=0;
	scanf("%d",&x);
	while(x>0)
	{
		xx=x%10;
		x=x/10;
		sum+=xx;
	}
	printf("%d\n",sum);

	return 0;
}

