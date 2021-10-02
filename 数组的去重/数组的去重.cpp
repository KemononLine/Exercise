#include <stdio.h>

void Input(int a[],int n);
void Output(int a[],int n);
int Search(int a[],int n, int x);
int Unique(int a[], int n);

int main(int argc, char* argv[])
{
	int a[10000],na,b[10000],nb;
	scanf("%d %d",&na,&nb);
	Input(a,na);	na=Unique(a,na);
	Input(b,nb);	nb=Unique(b,nb);
	Output(a,na);
	Output(b,nb);

	return 0;
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

