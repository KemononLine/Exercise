#include <stdio.h>
void Input(int a[],int n);
void SearchShortDistance(int a[],int n);

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void SearchShortDistance(int a[],int n)
{
	int i,j,dm=999999999;
	for (i=0;i<n;i++)
	{
		int d=0;
		for (j=0;j<n;j++)
		{
			if (a[j]>a[i])
				d=d+a[j]-a[i];
			else
				d=d+a[i]-a[j];
		}
		if (d<dm)
			dm=d;
	}
	printf("%d",dm);
}

int main()
{
	int a[100000],n;
	scanf("%d",&n);
	Input(a,n);
	SearchShortDistance(a,n);

		return 0;
}