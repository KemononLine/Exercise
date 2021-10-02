#include <stdio.h>
#include <string.h>

int main()
{
	char s[100000]; 
	gets(s);
	int n=strlen(s),i,j;
	for(i=0;i<n-1;i++)
	{
		if(s[i]>=s[i+1])
			printf("%c",s[i]);
		else
		{
			for(j=i;j<n-1;j++)
			{
				s[j]=s[j+1];
				printf("%c",s[j]);
			}
			break;
		}
	}

	return 0;
}

