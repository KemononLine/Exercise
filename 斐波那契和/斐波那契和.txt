#include<stdio.h>

int main()
{
	int k1, a, b, sum1,k2,sum2,sum,aa,bb;
	scanf("%d %d",&k1,&k2);
	aa=a=1, bb=b=0, sum1=1,sum2=1;
		while(k1>1)
		{
			aa=aa+bb;
			bb=aa-bb;
			k1--;
			sum1+=aa;
		}
	
		while(k2>1)
		{
			a=a+b;
			b=a-b;
			k2--;
			sum2+=a;
		}
	sum=sum2-sum1+aa;
	printf("%d",sum);
	return 0;
}