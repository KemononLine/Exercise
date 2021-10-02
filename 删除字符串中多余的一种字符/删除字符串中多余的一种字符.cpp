#include<stdio.h>
int main()
{
	char a[100000],x;
	int i;
	gets(a);
	scanf("%c",&x);
	for(i=0;a[i]!='\0';i++)
		if(a[i]!=x)
			printf("%c",a[i]);
	return 0;
}
