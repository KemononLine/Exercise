#include <stdio.h>

int main()
{
    int x,i;
	scanf("%d",&x);
	while(x>0)
	{
		for(i=2;i<x;i++)
			if(x%i==0)
				break;
		if(i!=x)
			break;
		x=x/10;
	}
	if(x!=0)
		printf("No");
	else
		printf("Yes");
}
