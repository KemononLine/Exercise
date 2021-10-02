#include <stdio.h>
void Input (int a[],int n);
int main ()

{
	int a[10000], n, i, x;
	scanf("%d", &n);
	Input(a,n);
	scanf("%d", &x);
	for(i=0;i<n;i++)
	{
		if(x<=a[i])
		{
			printf("%d ", x);break;
		}
		printf("%d ", a[i]);
	}
	while(i<n)
	{
		printf("%d ", a[i]);
		i++;
	}
	
	if(a[n-1]<=x)
		printf("%d", x);
	return 0;
}

void Input(int a[],int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
}