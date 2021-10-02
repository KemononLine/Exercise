#include<stdio.h>
int main()
{
	int n, m, a[10000],i;
	scanf("%d", &n);
    m=m%n;//M有可能比N大
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = n - m; i < n; i++)//先输出后面数组前移的
		printf("%d ", a[i]);
	for (i = 0; i < n - m-1; i++)//再依次从数组0开始输出
		printf("%d ", a[i]);
    printf("%d",a[n-m-1]);//序列结尾不能有多余空格
	return 0;
}







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
    temp = a[n-1];
    for(j = n-1; j > 0; j--)
      a[j] = a[j-1];
    a[0] = temp;
  }
  for(i = 0; i < n; ++i)
  {
    if(i)
      printf(" ");
    printf("%d", a[i]);
  }

  return 0;
}

