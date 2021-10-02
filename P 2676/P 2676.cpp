#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int num, height,ans,sum=0;
	int a[20002];
	cin >> num >> height;
	for (int i = 0;i < num;i++)
	{
		cin >> a[i];
	}
	sort(a, a + num, greater<int>());
	for (int i = 0;i < num;i++)
	{
		sum += a[i];
		if (sum >= height)
		{
			ans = i + 1;
			cout << ans;
			break;
		}
	}

	return 0;
}

