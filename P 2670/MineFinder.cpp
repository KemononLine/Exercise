#include <iostream>
using namespace std;
void main()
{
	int i, j;
	char str[100][100];
	cin >> i >> j;
	for (int mi = 0;mi < i;mi++)
		for (int mj = 0;mj < j;mj++)
			cin >> str[mi][mj];
	for (int mi = 0;mi < i;mi++)
	{
		for (int mj = 0;mj < j;mj++)
		{
			if (str[mi][mj] == '*')
				cout << "*";
			else
			{
				int count = 0;
				if (str[mi][mj - 1] == '*')
					count++;
				if (str[mi][mj + 1] == '*')
					count++;
				if (str[mi - 1][mj] == '*')
					count++;
				if (str[mi + 1][mj] == '*')
					count++;
				if (str[mi + 1][mj - 1] == '*')
					count++;
				if (str[mi - 1][mj - 1] == '*')
					count++;
				if (str[mi + 1][mj + 1] == '*')
					count++;
				if (str[mi - 1][mj + 1] == '*')
					count++;
				cout << count;
			}
		}
		cout << '\n';
	}

}

/*
#include<bits/stdc++.h>
using namespace std;
bool a[105][105];//一张地图，有雷为一，无雷为零
int main()
{
	memset(a,0,sizeof(a));//地图最开始清空
	int n,m;
	char tmp;
	cin>>n>>m;
	for(int i=1;i<=n;i++)//读入地图
	{
		for(int j=1;j<=m;j++)
		{
			cin>>tmp;//读入每一个点
			if(tmp=='*') a[i][j]=1;//如果是地雷就将这个点设为一
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1) printf("*"); //如果是地雷不用输出数字
			else
			{
				printf("%d",a[i+1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i-1][j+1]+a[i-1][j]+a[i-1][j-1]);
				//将旁边的雷加起来输出
			}
		}
		printf("\n");
	}
	return 0;//愉快的结束了主程序
}
*/
