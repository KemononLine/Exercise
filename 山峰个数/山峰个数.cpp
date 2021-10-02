#include <stdio.h>
#include <string.h>

int main()
{
	int x,y,a[500][500]={0};
	int cnt=0;
	int i,j;
	scanf("%d %d",&x,&y);
 	for (i=0; i<x; i++)
		for (j=0; j<y; j++)
			scanf("%d", &a[i][j]);
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i-1][j-1]&&a[i][j]>a[i-1][j]&&a[i][j]>a[i-1][j+1]&&a[i][j]>a[i+1][j-1]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i+1][j+1])
				cnt++;
		}
	}
	printf("%d",cnt);

	return 0;
}