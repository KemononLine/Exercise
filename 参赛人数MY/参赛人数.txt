#include <stdio.h>

int main()
{
	int a[10000], i, n1, n2, n;
	scanf("%d %d", &n1,&n2);
	int sum=n1+n2;
	int cnt=0;
	for(i=0;i<n1+n2;i++)
		scanf("%d", &a[i]);
	i=0;
	while(i<sum)
	{
		for(n=i+1;n<sum;n++)
			if(a[i]==a[n])
			{
				cnt++;break;
			}
		i++;
	}
	sum-=cnt;
	printf("%d\n", sum);
	return 0;
}