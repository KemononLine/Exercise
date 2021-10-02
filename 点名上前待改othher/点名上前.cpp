#include <stdio.h>

int main()
{
	int n, k, x;
	int a[100000],i=0;
	scanf("%d %d", &n, &k);
	while(i<n)
	{
		scanf("%d", &a[i]);
		i++;
	}
	x=a[k-1];
	for(i=k-1;i>0;i--)
		a[i]=a[i-1];
	a[0]=x;
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}