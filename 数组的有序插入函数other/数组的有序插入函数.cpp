#include<stdio.h>
int a[10001];
int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=n-1;i>=0&&x<a[i];i--)
		a[i+1]=a[i];
	a[i+1]=x;
	for(i=0;i<=n;i++)
		printf("%d ",a[i]);
	return 0; 
}