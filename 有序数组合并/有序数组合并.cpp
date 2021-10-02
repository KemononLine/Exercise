#include <stdio.h>
void Input(int a[],int n);
void Output(int a[],int n);
int Insert(int a[],int n, int x);
int Merge(int a[],int na, int b[],int nb, int c[]);

int Merge(int a[],int na, int b[],int nb, int c[])
{
	// a[0]...a[na-1]  => c[0]..c[na-1]
	for(int i=0; i<na; i++)  c[i]=a[i];
	// 将b[i]有序插入到c[]
	int nc=na;
	for(i=0; i<nb; i++) 
		nc=Insert(c,nc, b[i]);
	return nc;
}

int Insert(int a[],int n, int x)
{
	for(int i=n-1; i>=0 && a[i]>x; i--)
		a[i+1]=a[i];
	a[i+1]=x;
	return n+1;
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

int main()
{
	int a[10000],na;
	int b[10000],nb;
	int f[10000],nf;
	scanf("%d %d %d",&na,&nb,&nf);
	Input(a,na);	Input(b,nb);	Input(f,nf);
	int c[10000],nc;
	int d[10000],nd;
	nc=Merge(a,na, b,nb, c);
	nd=Merge(a,na, f,nf, d);
	Output(c,nc);	Output(d,nd);		
	
	return 0;    
}

