#include <stdio.h>
int main()
{
  int x, n, i, j;
  int a[10001];
  scanf("%d", &n);
  for(i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  scanf("%d",&x);
  x = x % n;
  for(i = 0; i < x; ++i)
  {
    int temp;
    temp = a[0];
    for(j = 0; j < n - 1; j++)
      a[j] = a[j+1];
    a[n - 1] = temp;
  }
  for(i = 0; i < n; ++i)
  {
    if(i)
      printf(" ");
    printf("%d", a[i]);
  }
}

