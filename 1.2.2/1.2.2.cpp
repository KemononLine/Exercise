#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (scanf_s("%d", &n))
	{
		int a = 0, b;
		for (int i = 0;i < n;i++)
		{
			scanf_s("%d", &b);
			a ^= b;
		}
		printf("%s\n", a ? "Yes" : "No");
	}
	return 0;
}
//���ս��Ϊ0������˭��״̬�ع�ƽ�⣬˭��Ӯ��
//������ƽ�⣬�����Ӯ����֮������Ӯ
//ÿ�ζ��轫��ƽ��״̬��Ϊƽ��״̬
//������