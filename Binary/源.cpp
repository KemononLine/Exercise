#include <iostream>
using namespace std;
int main()
{
	int T, len;
	int s1[1002] = { 0 };
	int e1[1002] = { 0 };
	int s2[1002] = { 0 };
	int e2[1002] = { 0 };
	int s = 0, e = 0, ss = 0, ee = 0;
	string num;
	cin >> T;
	int TT = T;
	while (T)
	{
		int flag = 0;
		T--;
		cin >> len;
		cin >> num;
		for (int i = len / 2; len > i; i++)
		{
			if (num[i] == '0')
			{
				s1[T]=1;
				e1[T]=i+1;
				s2[T]=1;
				e2[T]=i;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;
		else if (len % 2 == 0 && num[len / 2 - 1] == '0')
		{
			s1[T]=len / 2;
			e1[T]=len;
			s2[T]=len / 2 + 1;
			e2[T]=len;
		}
		else if (len % 2 == 0 && num[len / 2 - 1] == '1')
		{
			s1[T] = len / 2;
			e1[T] = len-1;
			s2[T] = len / 2 + 1;
			e2[T] = len;
		}
		else if (len % 2 != 0)
		{
			s1[T] = len / 2;
			e1[T] = len - 1;
			s2[T] = len / 2 + 1;
			e2[T] = len;
		}
	}
	for (int i = TT - 1;i >= 0;i--)
		cout << s1[i] << " " << e1[i] << " " << s2[i] << " " << e2[i] << endl;

	return 0;
}
