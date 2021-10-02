#include <stdio.h>
int c, big, little, L, i, j, k, n;

void main()
{
	scanf_s("%d", &c);
	while (c-- &&(2 == scanf_s("%d%d",&L,&n)))
	{
		big = little = 0;
		for (i = 0;i < n;i++)
		{
			scanf_s("%d", &k);
			if (k > big)
				big = k;
			if (L - k > big)
				big = L - k;
			if (k > L - k)
				k = L - k;
			if (k > little)
				little = k;
		}
		printf("%d %d\n", little, big);
	}
	if (c != -1)
		printf("missing put\n");
}
//每只蚂蚁看作一个点，计算其距离左右端点的距离，将这些距离排序。
//一共n只蚂蚁，最短时间即为，第n小的数，最长时间为最大的数。