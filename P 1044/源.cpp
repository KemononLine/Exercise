#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,cnt=0;
	cin >> n;
	int a[20];
	for (int i = 0;i < n;i++)
		a[i] = i + 1;
	do
	{
		for (int i = 0;i < n;i++)
		{
			if (a[i] - a[i + 1] >= 2)
				break;
			else
			{
				cnt++;
				break;
			}
		}
	} while (next_permutation(a, a+n));
	cout << cnt;

	return 0;
}