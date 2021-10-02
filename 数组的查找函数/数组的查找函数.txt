#include <stdio.h>

void Input (int a[],int na);
int Search(int a[],int n, int x);


int main()
{
	int a[10000];
	int n;
	int x;
	scanf("%d",&n);
	Input(a,n);
	scanf("%d",&x);
	int k=Search(a,n, x);
	if(k==-1)
		printf("-1\n");
	else
		printf("%d\n", k);
	return 0;
	

}
void Input(int a[],int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
}
int Search(int a[],int n, int x)
{
	for(int i=0; i<n; i++)
	{
		if(a[i]==x)	
			return i;
	}
	return -1;
}

