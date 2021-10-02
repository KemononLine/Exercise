#include<stdio.h>
void Prime(int a[],int n);

void Prime(int a[],int n)
{
	int b=2;
	int max=0;
	int i;
	while(n>=b)
	{
		if(n%b==0)
		{	
			a[b]++;
			n=n/b;
		}
		else
			b++;
	}
	for(i=2;i<10000;i++)
		if(max<a[i])
			max=a[i];
	for(i=2;i<10000;i++)
		if(a[i]==max)
		printf("%d ",i);
}

int main()
{
	int a[10000]={0},n;
	scanf("%d",&n);
	Prime(a,n);
	return 0;
}