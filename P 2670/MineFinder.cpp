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
bool a[105][105];//һ�ŵ�ͼ������Ϊһ������Ϊ��
int main()
{
	memset(a,0,sizeof(a));//��ͼ�ʼ���
	int n,m;
	char tmp;
	cin>>n>>m;
	for(int i=1;i<=n;i++)//�����ͼ
	{
		for(int j=1;j<=m;j++)
		{
			cin>>tmp;//����ÿһ����
			if(tmp=='*') a[i][j]=1;//����ǵ��׾ͽ��������Ϊһ
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1) printf("*"); //����ǵ��ײ����������
			else
			{
				printf("%d",a[i+1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i-1][j+1]+a[i-1][j]+a[i-1][j-1]);
				//���Աߵ��׼��������
			}
		}
		printf("\n");
	}
	return 0;//���Ľ�����������
}
*/
