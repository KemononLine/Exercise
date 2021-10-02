#include <iostream>
#include <algorithm>
using namespace std;
int Swap1(int a[], int num);

int main()
{
	int n, a[10010],ans;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	ans = Swap1(a,n);
	cout << ans;
}

int Swap1(int a[],int num)
{
	int n = 0;
	int temp;
	while (1)
	{
		int flag = 1;
		for (int i = 0;i < num-1;i++)
		{
			if (a[i + 1] < a[i])
			{
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				n++;
			}
		}
		for (int i = 0;i < num-1;i++)
		{
			if (a[i] > a[i + 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	return n;
}