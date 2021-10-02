#include<stdio.h>
int main()
{
	char a[100000],x[10];
	int i,j;
	gets(a);
	gets(x);
	for(i=0;x[i]!='\0';i++)
	{
		for(j=0;a[j]!='\0';j++)
			if(a[j]!=x[i])
				printf("%c",a[j]);
	}
	return 0;
}
