#include <stdio.h>

void Output(int a[],int n);
int  RemoveAt(int a[],int n, int k);
int main()
{
	int a[100000],n,i,kk,k,temp;
	scanf("%d %d",&n,&kk);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	k=kk-1;
	temp=a[k];
	n=RemoveAt(a,n, k); 
	printf("%d ",temp);
	Output(a,n);

	return 0;
}

int  RemoveAt(int a[],int n, int k)
{
	if(k<0 || k>=n)
		return n;
	for(int i=k+1; i<n; i++)
		a[i-1]=a[i];
	return n-1;
}

void Output(int a[],int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

