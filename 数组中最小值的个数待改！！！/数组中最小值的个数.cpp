/*
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
}/*/

#include <stdio.h>
void Input(int a[],int n);
void FindMinCount(int a[],int n);

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void FindMinCount(int a[],int n)
{
  	int i,min,cnt=0;
  	min=a[0];
  	for(i=0;i<n;i++)
    {
      	if(a[i]<min) 
			cnt=0;
      	else if(a[i]=min) 
			cnt++;
    }
  	printf("%d ",cnt);
}
int main()
{
  	int n1,n2,a[10000],b[10000];
  	scanf("%d %d",&n1,&n2);
    Input(a,n1);	Input(b,n2);
	FindMinCount(a,n1);	FindMinCount(b,n2);

	return 0;
}