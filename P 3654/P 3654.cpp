#include <iostream>
using namespace std;

int r, c, k, ans = 0, q;
int s[101][101];
void right(int i, int j, int r) 
{//x坐标，y坐标，循环次数 
	if (r == k) 
	{//如果循环次数和k相等 
		ans++;//答案++ 
		return;//结束搜索 
	}
	if (s[i][j + 1] == 1)
		right(i, j + 1, r + 1);//如果向右是空的，那么可以循环，次数++； 
}
void under(int i, int j, int r)
{//与上边相同，只是改了改方向 
	if (r == k) 
	{
		ans++;
		return;
	}
	if (s[i + 1][j] == 1)
		under(i + 1, j, r + 1);
}
int main() 
{
	cin >> r >> c >> k;//输入 
	char a[2];
	for (int i = 1;i <= r;i++) 
	{//输入(进行判断，如果是杂物就放0，可以站就是1) 
		for (int j = 1;j <= c;j++) 
		{
			cin >> a[1];
			if (a[1] == '#')
				s[i][j] = 0;
			else 
				s[i][j] = 1;
		}
	}
	for (int i = 1;i <= r;i++) 
	{ //对于每一个点都扫一遍 
		for (int j = 1;j <= c;j++) 
		{
			if (s[i][j] == 1) 
			{
				right(i, j, 1);//向右进行搜索
				under(i, j, 1);//向下进行搜索 
			}
		}
	}
	if (k == 1)
		cout << ans / 2;//特判，如果是1的话，向右，向下都扫了一遍，一共是两遍，所以除以2 
	else
		cout << ans;//记着加else，否则k==1时会输出两个结果 
	
	return 0;
}