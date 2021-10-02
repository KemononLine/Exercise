#include <stdio.h>
void Input(int a[],int n);
void FindAscCount(int a[],int n);

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void FindAscCount(int a[],int n)
{
	int cnt=1,i;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
			cnt++;
	}
	printf("%d ",cnt);
}

int main()
{
	int a[10000],b[10000],n1,n2;
	scanf("%d%d\n",&n1,&n2);
	Input(a,n1);	Input(b,n2);
	FindAscCount(a,n1);	FindAscCount(b,n2);

	return 0;
}

