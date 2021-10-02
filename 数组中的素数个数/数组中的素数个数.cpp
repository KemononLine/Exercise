#include <stdio.h>

int main()
{
	int a[10000],b[10000],n1,n2,cnt1=0,cnt2=0,i,k;
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n2;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n1;i++)
    {
		for(k=2;k<=a[i];k++)
		if(a[i]%k==0)
			break;
      	if(k==a[i])
          cnt1++;
    } 				
	for(i=0;i<n2;i++)
	{
		for(k=2;k<=b[i];k++)
		if(b[i]%k==0)
			break;
      	if(k==b[i])
          cnt2++;
    } 				
	printf("%d %d\n",cnt1,cnt2);
	return 0;
}