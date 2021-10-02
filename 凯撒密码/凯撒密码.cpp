#include <stdio.h>
void Caesar(char a[],int k);

void Caesar(char a[],int k)
{
	int i;
	for(i=0;a[i]!=0;i++)
	{
		if(a[i]>=65&&a[i]<=90)
		{
			a[i]=a[i]+k;
			if(a[i]>90)
				a[i]=a[i]-26;
		}
		if(a[i]>=97&&a[i]<=122)
		{
			a[i]=a[i]+k;
			if(a[i]>122)
				a[i]=a[i]-26;
		}
	}
}

int main()
{
	char a[100000];
	int k;
	gets(a);
	scanf("%d",&k);
	Caesar(a,k);
	puts(a);

	return 0;
}