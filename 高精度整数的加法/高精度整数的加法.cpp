/*
#include <stdio.h>
int Mul(int x,int n,int a[]);
int Add(int a[],int b[],int c[],int w1);
int main()
{
	int x1,n1,x2,n2,i,w1=1,w2=1,w3=1;
	int a[100000]={0};
	a[0]=1;
	int b[100000]={0};
	b[0]=1;
	int c[100000];
	scanf("%d%d%d%d",&x1,&n1,&x2,&n2);
	for(i=1;i<=n1;i++)
	{
		w1=Mul(x1,w1,a);
	}
	for(i=1; i<=n2; i++)
	{
		w2=Mul(x2,w2,b);
	}
	w1=w1>w2?w1:w2;
	w3=Add(a,b,c,w1);
	for(i=w3-1;i>=0; i--)
		printf("%d",c[i]);
	printf("\n");
	return 0;
}
int Mul(int x,int n,int a[])
{
	int y,i,jc=0;
	for(i=0;i<n;i++)
	{
		y=a[i]*x+jc;
		a[i]=y%10;
		jc=y/10;
	}
	while(jc>0)
	{
		a[n]=jc%10,n++;
		jc=jc/10;
	}
	return n;
}
int Add(int a[],int b[],int c[],int w1)
{
	int y,i,jc=0;
	for(i=0;i<w1;i++)
	{
		y=a[i]+b[i]+jc;
		c[i]=y%10;
		jc=y/10;
	}
	while(jc>0)
	{
		c[w1]=jc%10,w1++;
		jc=jc/10;
	}
	return w1;
}
/*/






#include <stdio.h>
int Add(int a[],int b[],int c[],int n1);
int Mul(int a[],int n, int x);

int Mul(int a[],int n, int x)
{
  int jw=0;
  for(int i=0; i<n; i++)
  {
    int y=a[i]*x+jw;
    a[i] = y%10;
    jw   = y/10;
  }
  while(jw>0)
  {
    a[n]=jw%10, n++;
    jw=jw/10;
  }
  return n;
}

int Add(int a[],int b[],int c[],int n1)
{
	int y,i,jw=0;
	for(i=0;i<n1;i++)
	{
		y=a[i]+b[i]+jw;
		c[i]=y%10;
		jw=y/10;
	}
	while(jw>0)
	{
		c[n1]=jw%10,n1++;
		jw=jw/10;
	}
	return n1;
}

int main(int argc, char* argv[])
{
  int m1,m2,N1,N2,n3;
  scanf("%d %d %d %d",&m1,&N1,&m2,&N2);
  int x[10000], n1=1;
  x[0]=1;  
  for(int i=1; i<=N1; i++)
  {
    n1 = Mul(x,n1, m1);
  }
  int y[100000], n2=1;
  y[0]=1;
  int z[100000];
  for(int k=1;k<=N2;k++)
  {
	  n2=Mul(y,n2,m2);
  }
  n1=n1>n2?n1:n2;
  n3=Add(x,y,z,n1);
	for(i=n3-1;i>=0; i--)
		printf("%d",z[i]);
	printf("\n");
  return 0;    
}

