#include <stdio.h>
#include <string.h>

int main()
{
	int n2,n1;
	char s1[10000],s2[10000],s3[10000],s4[10000]={0};
	gets(s1);
	gets(s2);
	n1=strlen(s1);
	n2=strlen(s2);
	int i;
	for(i=0;i<n2;i++)
		s3[i]=s2[i+1];
	for(i=0;i<n1-1;i++)
		s4[i]=s1[i];
	strcat(s4,s3);
	puts(s4);

	return 0;
}
