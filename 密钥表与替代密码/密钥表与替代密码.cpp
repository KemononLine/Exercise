/*
#include<stdio.h>
int main()
{
	char a[100000],b[27],*p;
	gets(b);
	gets(a);
	for(p=a;*p!='\0';p++)
	{
		if(*p>='a'&&*p<='z')
			*p=b[*p-'a'];
		else if(*p>='A'&&*p<='Z')
			*p=b[*p-'A']-32;
	}
	puts(a);
}
/*/

#include <stdio.h>
#include <string.h>
int main()
{
	char a[100000],b[27];
	gets(b);
	gets(a);
	int i;
	int n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]>=97&&a[i]<=122)
			a[i]=b[a[i]-97];
		else if(a[i]>=65&&a[i]<=90)
			a[i]=b[a[i]-65]-32;
	}
	puts(a);

	return 0;
}


