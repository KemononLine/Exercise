#include<stdio.h>
int main()
{
	int n,i,j,cnt=0;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=i;j++)
		{
			if(i%j==0&&j==i)
				cnt++;
			else if(i%j==0&&j<i)
				break;
		}
	}
	printf("%d\n",cnt);

	return 0;
}