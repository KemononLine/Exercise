#include<stdio.h>

int FindiMinPos(int c[],int x);
void Input(int a[],int n);

void Input(int a[],int n)
{
  	int i;
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
}

int FindiMinPos(int c[],int x)
{
	int min,i;
	for(i=0;i<x;i++) 
		if(c[i]>0)
			break;	
	min=i;		
	for(;i<x;i++) 
		if(c[i]<c[min] && c[i]>0)
			min=i;	
	return min;
}
int main()
{
	int a[10000],b[10000];
	int n1,n2,i;
	scanf("%d%d",&n1,&n2);
	Input(a,n1);
	Input(b,n2);
	printf("%d %d",FindiMinPos(a,n1),FindiMinPos(b,n2));
	return 0;
}