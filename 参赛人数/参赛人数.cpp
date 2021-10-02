#include<stdio.h>
int main()
{
	int n1,n2,a[10000]={0},i,cnt=0;
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n1+n2;i++)
	{
		int n=0;
		scanf("%d",&n);
		cnt+=!a[n];
		a[n]=1;
	}
	printf("%d",cnt);

	return 0;

}