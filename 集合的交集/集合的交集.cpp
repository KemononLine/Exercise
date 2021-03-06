#include <stdio.h>

void Input(int a[],int n);
void Output(int a[],int n);
int Search(int a[],int n, int x);
int InterSet(int a[],int na, int b[],int nb, int c[]);
int Unique(int a[], int n);

int main(int argc, char* argv[])
{
	int a[10000],na,b[10000],nb,c[10000],nc;
	scanf("%d %d %d",&na,&nb,&nc);
	Input(a,na);	na=Unique(a,na);
	Input(b,nb);	nb=Unique(b,nb);
	Input(c,nc);	nc=Unique(c,nc);
	int x[10000],nx;
	nx = InterSet(a,na, b,nb, x);
	int y[10000],ny;
	ny = InterSet(a,na, c,nc, y);
	Output(x,nx);	Output(y,ny);	
	return 0;
}

int InterSet(int a[],int na, int b[],int nb, int c[])
{
	int k=0;   // 函数级的局部变量
	for(int i=0; i<na; i++)
	{
		// 在b[0]..b[nb-1]中查找a[i]
		int ki=Search(b,nb, a[i]);   // 语句级的局部变量
		if(ki!=-1)   // 找到了
			c[k]=a[i], k++; // Append的套路
	}
	return k;
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
int Unique(int a[], int n)
{
	int k=0;  // 被删除的数字的个数
	for(int i=0; i<n; i++)
	{
		// a[i]在a[0]...a[i-k-1]中是否出现过
		int ki=Search(a,i-k, a[i]);
		if(ki!=-1)
			k++;    // 出现过,就是重复数
		else
			a[i-k]=a[i];
	}
	return n-k;
}

