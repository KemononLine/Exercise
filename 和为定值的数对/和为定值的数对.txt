#include<stdio.h>
int main()
{
	int n,m,a[100000],i,j,cnt=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
			if(a[i]+a[j]==m)
			{
				cnt++;
				break;
			}
	}
	printf("%d",cnt);
}