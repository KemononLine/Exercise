#include <iostream>
using namespace std;

int main()
{
	int a[100005], n, thisSum=0, maxSum = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		thisSum += a[i];
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	cout << maxSum;

	return 0;
}