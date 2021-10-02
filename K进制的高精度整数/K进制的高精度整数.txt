#include<stdio.h>
void Output(int a[],int n);
int Mul(int a[],int n, int x);
int k;
char s[7]={'A','B','C','D','E','F',0};

void Output(int a[],int n)
{
	for(int i=n-1; i>=0; i--)
	{
		if(a[i]>=10&&a[i]<=16)
			printf("%c",s[a[i]-10]);
		else
			printf("%d", a[i]);
	}
}

int Mul(int a[],int n, int x)
{
	int jw=0;
	for(int i=0; i<n; i++)
	{
		int y=a[i]*x+jw;
		a[i] = y%k;
		jw   = y/k;
	}
	while(jw>0)
	{
		a[n]=jw%k, n++;
		jw=jw/k;
	}
	return n;
}

int main()
{
	int x,n;
	scanf("%d %d %d",&x,&n,&k);
	int xx[100000]={0}, j=1;
	xx[0]=1;  
	for(int i=1; i<=n; i++)
		j=Mul(xx,j,x);
	Output(xx,j);
	return 0;    
}


