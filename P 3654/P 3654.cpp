#include <iostream>
using namespace std;

int r, c, k, ans = 0, q;
int s[101][101];
void right(int i, int j, int r) 
{//x���꣬y���꣬ѭ������ 
	if (r == k) 
	{//���ѭ��������k��� 
		ans++;//��++ 
		return;//�������� 
	}
	if (s[i][j + 1] == 1)
		right(i, j + 1, r + 1);//��������ǿյģ���ô����ѭ��������++�� 
}
void under(int i, int j, int r)
{//���ϱ���ͬ��ֻ�Ǹ��˸ķ��� 
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
	cin >> r >> c >> k;//���� 
	char a[2];
	for (int i = 1;i <= r;i++) 
	{//����(�����жϣ����������ͷ�0������վ����1) 
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
	{ //����ÿһ���㶼ɨһ�� 
		for (int j = 1;j <= c;j++) 
		{
			if (s[i][j] == 1) 
			{
				right(i, j, 1);//���ҽ�������
				under(i, j, 1);//���½������� 
			}
		}
	}
	if (k == 1)
		cout << ans / 2;//���У������1�Ļ������ң����¶�ɨ��һ�飬һ�������飬���Գ���2 
	else
		cout << ans;//���ż�else������k==1ʱ������������ 
	
	return 0;
}