#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int *f;
	int n, i; 
	long int sum = 0; 
	scanf("%d",&n);
	f = (long int*)malloc(sizeof(long int)*n);
	
	f[0] = 0;
	f[1] = 1;
	for(i=2; i<=n; i++) 
	{
		f[i] = f[i-1]+f[i-2];
	}
	for(i=1; i<=n; i++)
	{
		printf("%-8d",f[i]);
		if(i % 6 == 0)
		{
			printf("\n");
		}
	}
	printf("\n\nsum = ");
	for(i=0; i<=n; i++)
	{
		sum += f[i];
	}
	printf("%d", sum);
	return 0;
} 