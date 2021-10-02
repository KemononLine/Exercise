#include<stdio.h>
#include<string.h> 
int main()
{
  char s[12];
  int i,j,c=0;
  gets(s);
  int n=strlen(s)+1;
  for(i=0;i<n;i++)
  {
	if(s[i]==32||s[i]==0)
	{
  	for(j=i-1;j>=c;j--)
  		printf("%c",s[j]);
  	printf(" ");
  	c=i+1;	
	}	
  }

  return 0;
}
