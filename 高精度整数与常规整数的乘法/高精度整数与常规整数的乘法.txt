void Output(int a[],int n);
int Mul(int a[],int n, int x);

void Output(int a[],int n)
{
  for(int i=n-1; i>=0; i--)
    printf("%d", a[i]);
  printf("\n");
}

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

int main(int argc, char* argv[])
{
  int m,N;
  scanf("%d %d",&m,&N);
  int x[100000], n=1;
  x[0]=1;  
  for(int i=1; i<=N; i++)
  {
    n = Mul(x,n, m);
  }
  Output(x, n);
  return 0;    
}

