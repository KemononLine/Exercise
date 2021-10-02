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
	int k=0;   // �������ľֲ�����
	for(int i=0; i<na; i++)
	{
		// ��b[0]..b[nb-1]�в���a[i]
		int ki=Search(b,nb, a[i]);   // ��伶�ľֲ�����
		if(ki!=-1)   // �ҵ���
			c[k]=a[i], k++; // Append����·
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
	int k=0;  // ��ɾ�������ֵĸ���
	for(int i=0; i<n; i++)
	{
		// a[i]��a[0]...a[i-k-1]���Ƿ���ֹ�
		int ki=Search(a,i-k, a[i]);
		if(ki!=-1)
			k++;    // ���ֹ�,�����ظ���
		else
			a[i-k]=a[i];
	}
	return n-k;
}

