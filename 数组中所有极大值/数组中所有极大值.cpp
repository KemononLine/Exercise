#include <stdio.h>
void Input(int a[],int n);
void FindMaxs(int a[],int n);

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void FindMaxs(int a[],int n)
{
	int i,max=0;
	for (i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
			printf("%d ",a[i]);
	}
	printf("%d",a[i]);
	printf("\n");
}

int main()
{
	int a[10000],b[10000],na,nb;
	scanf("%d %d",&na,&nb);
	Input(a,na);	Input(b,nb);
	FindMaxs(a,na);	FindMaxs(b,nb);
	
	return 0;
}

