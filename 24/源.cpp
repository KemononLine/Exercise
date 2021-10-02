#include <iostream>
using namespace std;
int n, a[200005], cnt = 0;
int main()
{

	cin >> n;
	cin >> a[0];
	for (int i = 1;i < n;i++)
	{
		cin >> a[i];
		for (int j = i - 1;j >= 0;j--)
		{
			if (a[j] > a[i] && a[j] == a[i] + 1)
			{
				a[i] += 1;
				break;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			if (a[j] < a[i])
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}