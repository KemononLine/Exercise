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
//最终结果为0，所以谁让状态回归平衡，谁就赢。
//若开局平衡，则后手赢，反之，先手赢
//每次都需将不平衡状态抽为平衡状态
//二进制