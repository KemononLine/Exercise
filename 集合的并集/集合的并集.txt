#include <stdio.h>

void Input(int a[],int n);
void Output(int a[],int n);
int Search(int a[],int n, int x);
int UnionSet(int a[],int na, int b[],int nb, int c[]);

int main(int argc, char* argv[])
{
	int a[10000],na,b[10000],nb,c[10000],nc;
	scanf("%d %d %d",&na,&nb,&nc);
	Input(a,na);	Input(b,nb);	Input(c,nc);
	int x[10000],nx;
	nx = UnionSet(a,na, b,nb, x);
	int y[10000],ny;
	ny = UnionSet(a,na, c,nc, y);
	Output(x,nx);
	Output(y,ny);
	return 0;
}

int UnionSet(int a[],int na, int b[],int nb, int c[])
{
	int nc=0;
	for(int i=0; i<na; i++)
		if( Search(c,nc, a[i])==-1 )
			c[nc++]=a[i];
	for(    i=0; i<nb; i++)
		if( Search(c,nc, b[i])==-1 )
			c[nc++]=b[i];
	return nc;
}

int Search(int a[],int n, int x)
{
	for(int i=0; i<n; i++)
		if(a[i]==x)
			return i;
	return -1;
}
void Output(int a[],int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void Input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}