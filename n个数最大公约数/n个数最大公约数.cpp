#include <stdio.h>



int main()
{
	int n,a,b;
	scanf("%d", &n);
	scanf("%d", &a);
	for(int i=1; i<n;  i++)
	{
		scanf("%d", &b);
		
		
		while( 1 )
		{
			int r=a%b;
			if(r==0)
				break;
			a=b;  b=r;
		}
		
	}
	printf("%d\n", b);

	return 0;
	

}

