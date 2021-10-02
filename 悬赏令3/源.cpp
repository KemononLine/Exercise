#include <iostream>
#include <algorithm>
using namespace std;

void BinarySearch(long long a[]);
long long Sum(long long x);

long long n, m, sum, mid, ans;
long long a[1000001];

void BinarySearch(long long a[])
{
	long long left = 0;
	long long right = a[n - 1];
	while (right > left)
	{
		mid = (right + left) / 2;
		if (Sum(mid) < m)
			right = mid - 1;
		else
			left = mid + 1;
	}
	ans = mid;
	cout << ans << endl;
}
long long Sum(long long x)
{
	sum = 0;
	int i;
	for (i = 0;i<n; i++)
		if (a[i] >= x)
			break;
	while(i<n)
	{
		sum += a[i] - x;
		i++;
	}
	return sum;
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++)
		cin >> a[i];
}

int main()
{
	Input();
	sort(a, a + n);
	BinarySearch(a);

	return 0;
}