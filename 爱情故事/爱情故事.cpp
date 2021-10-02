#include <stdio.h>
int Index(char s[], char t[], int si);
void Replace(char s[], char t[],char u[]);

int main(int argc, char* argv[])
{
	char s[100000]; 
	char t[20]; 
	char u[20];
	gets(s);
	gets(t);
	gets(u);
	Replace(s,t,u);  puts(s);

	return 0;    
}

void Replace(char s[], char t[],char u[])
{
	int slen=strlen(s), tlen=strlen(t), ulen=strlen(u);
	int gap=ulen-tlen;
	int si=-1;
	while( 1 )
	{
		si=Index(s,t, si+1);
		if(si==-1)
			break;
		if(gap>0)  
			for(int i=slen; i>=si+tlen; i--)
				s[i+gap]=s[i];
		if(gap<0)  
			for(int i=si+tlen; i<=slen; i++)
				s[i+gap]=s[i];
		for(int i=0; u[i]!=0; i++)
			s[si+i] = u[i];
		slen += gap;
	}
}

int Index(char s[], char t[], int si)
{
	int i=si, j=0;
	while( s[i]!=0 && t[j]!=0 ) 
	{
		if(s[i]==t[j])
			i++, j++;
		else
			i=i-j+1,  j=0;
	}
	if( t[j]==0 )
		return i-j;
	else
		return -1;
}
