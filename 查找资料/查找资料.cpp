#include <stdio.h>
#include <string.h>
int Index(char s[], char t[], int si);

int Index(char s[], char t[], int si)
{
	int i=si, j=0;
	while( s[i]!=0 && t[j]!=0 ) 
	{
		if(s[i]==t[j])  
			i++, j++;
		else
			i++,  j=0;  
	}
	if( t[j]==0 )
		return i-j; 
	else
		return -1;
}

int main(int argc, char* argv[])
{
	char s[100000];
	char t[100]; 
	gets(s);
	gets(t);
	int n=strlen(t);
	int k=-1;
	int cnt=1;
	k=Index(s, t, k+1);
	if(k==-1)
		printf("0");
	while( 1 )
	{
		k=Index(s, t, k+n);
		if(k!=-1)
			cnt++;
		if(k==-1)
			break;
	}
	printf("%d",cnt);
	return 0;    
}

