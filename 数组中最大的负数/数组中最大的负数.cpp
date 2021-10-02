#include<stdio.h>

int FindMaxNeg(int c[],int x);
void Input(int a[],int n);

void Input(int a[],int n)
{
  	int i;
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
}

int FindMaxNeg(int c[],int x)
{
	int max=c[0],i;
	for(i=1;i<x;i++)
		if((c[i]<0&&c[i]>max)||max>=0)
			max=c[i];
	return max;
}
int main()
{
	int a[10000],b[10000];
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	Input(a,n1);
	Input(b,n2);
	printf("%d %d",FindMaxNeg(a,n1),FindMaxNeg(b,n2));
	return 0;
}