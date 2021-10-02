/*
#include <stdio.h>
void Input(int a[],int n);

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int x[100];
	Input(x,k);
	int i,a,b,r;
	for(i=0;i<k;i++)
	{
		r=1;a=n;b=x[i];
		while (r!=0)
		{
			r=a%b;
			a=b;
			b=r;
			if(b==1)
			{
				int m;
				for(m=1;m<n;m++)
				{
					if((x[i]*m)%n==1)
					{
						printf("%d ",m);
						break;
					}
				}
			}
		}
	}

	return 0;
}

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
/*/

#include<stdio.h>
void Input(int a[],int n);

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

int main()
{
	int n,k,i=0,x[100],b=2;
	scanf("%d %d",&n,&k);
	Input(x,k);
	for(i=0;i<k;i++)
	{
		for(b=2;b<n;b++)
		{
			if(x[i]*b%n==1)
				{
					printf("%d ",b); break;
				}
		}
		if(b==n)
			printf("0 ");
	}
	return 0;
}