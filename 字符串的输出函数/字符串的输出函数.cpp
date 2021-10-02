#include <stdio.h>
#include <string.h>

int main()
{
	int n1,n2;
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	n1=strlen(s1);
	n2=strlen(s2);
	printf("%d %d",n1,n2);

	return 0;
}