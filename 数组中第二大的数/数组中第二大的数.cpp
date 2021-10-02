/*
void Input(int a[],int n);
int FindMax(int a[],int n);
int FindMin(int a[],int n);
int FindSecondMax(int a[],int n,int max);

int main(int argc, char* argv[])
{
	int a[10000],b[10000],n1,n2,sm,max,k=0,i;
	scanf("%d%d",&n1,&n2);
	Input(a,n1);
	Input(b,n2);
	max=FindMax(a,n1);
	for(i=0;i<n1;i++)
	{if(a[i]==max)
			k++;
		if(k==2)
		{printf("%d ",i);
		break;}}
	if(k==1)
	{sm=FindSecondMax( a,n1,max);
		printf("%d ",sm);}
	max=FindMax(b,n2);
	for(i=0,k=0;i<n2;i++)
	{if(b[i]==max)
		k++;
	if(k==2)
    {printf("%d ",i);
			break;}}
	if(k==1)
	{sm=FindSecondMax( b,n2,max);
	printf("%d\n",sm);}
	return 0;
}

void Input(int a[],int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

int FindMax(int a[],int n)
{
	int i,max=a[0];
	for(i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];
	return max;
}

int FindSecondMax(int a[],int n,int max)
{
	int i,sm=FindMin(a,n),imin;
	for(i=0;i<n;i++)
		if(a[i]>sm && a[i]<max)
		{sm=a[i];
		imin=i;}
	return imin;
}

int FindMin(int a[],int n)
{
	int min=a[0],i;
	for(i=0;i<n;i++)
		if(a[i]<min)
			min=a[i];
	return min;
}
/*/



#include <stdio.h>
void Input(int a[],int n);
void FindSecondMax(int a[],int n);

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void FindSecondMax(int a[],int n)
{
	int min=a[0],i,ans;
	for(i=1;i<n;i++)
		if(a[i]<min)
			min=a[i];
	int maxpos=0;
	for(i=1;i<n;i++)
		if(a[i]>a[maxpos])
			maxpos=i;
	for(i=0;i<n;i++)
		if(a[i]>min && i!=maxpos)
		{
			min=a[i];
			ans=i;
		}
	printf("%d ",ans);
}
int main()
{
	int a[10000],n1,b[10000],n2;
	scanf("%d %d",&n1,&n2);
	Input(a,n1);	Input(b,n2);
	FindSecondMax(a,n1);	FindSecondMax(b,n2);
	return 0;
}