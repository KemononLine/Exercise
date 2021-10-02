#include <stdio.h>
#include <string.h>
void Diff(char s[],int n);

int main()
{
	char s1[10000],s2[10000];
	int n1,n2;
	gets(s1);
	gets(s2);
	n1=strlen(s1);
	n2=strlen(s2);
	Diff(s1,n1);	Diff(s2,n2);

	return 0;
}

void Diff(char s[],int n)
{
	int i,ans;
	int cnt1=0,cnt2=0;
	for(i=0;i<n;i++)
	{
		if(s[i]>=65&&s[i]<=90)
			cnt1++;
		else if(s[i]>=97&&s[i]<=122)
			cnt2++;
	}
	ans=cnt1-cnt2;
	printf("%d ",ans);
}