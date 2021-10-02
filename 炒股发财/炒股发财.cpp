#include<stdio.h>
int main(void)
{
	int n,a[100000],i=0,j,temp,m;
	scanf("%d",&n);
	while(i<n)
	{
		scanf("%d",&a[i]);
		i++;
	}
	m=a[1]-a[0];
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			temp=a[j]-a[i];
			if(m<temp)
				m=temp;
		}
	printf("%d",m);

	return 0;
}
