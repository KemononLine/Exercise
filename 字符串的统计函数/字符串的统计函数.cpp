#include <stdio.h>
#include <string.h>
void Count(char s[],int n);

int main()
{
	int n1,n2;
	char s1[10000],s2[10000];
	gets(s1);
	gets(s2);
	n1=strlen(s1);
	n2=strlen(s2);
	Count(s1,n1);	Count(s2,n2);

	return 0;
}
void Count(char s[],int n)
{
	int i;
	int cnt=0;
	for(i=0;i<n;i++)
	{
		if(s[i]>=97&&s[i]<=122)
			cnt++;
	}
	printf("%d ",cnt);
}

