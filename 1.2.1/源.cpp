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
//ÿֻ���Ͽ���һ���㣬������������Ҷ˵�ľ��룬����Щ��������
//һ��nֻ���ϣ����ʱ�伴Ϊ����nС�������ʱ��Ϊ��������