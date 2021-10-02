/*
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
/*/

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m, a, b, r,cnt=0;
	while (n>0)
	{
		m=n-1;
		while (m>0)
		{
			r=1; a=n; b=m;
			while(r!=0)
			{
				r=a%b; a=b; b=r;
				if(b==1)
				{	
					cnt++; break;
				}
			}
			m--;
		}
		n--;
	}
	printf("%d\n",cnt);

	return 0;
}