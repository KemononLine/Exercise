#include <iostream>
using namespace std;

int n, s, d,nn;
int ans[1002];

int isPrime(int num);

int main()
{
	cin >> n;
	nn = n;
	while (n)
	{
		n--;
		cin >> d;
		int i, num1 = 0, num2 = 0;
		if (d % 2 == 0)
		{
			for (i = 1 + d;; i++)
				if (isPrime(i))
				{
					num1 = i;
					break;
				}
			for (i += d;; i++)
				if (isPrime(i))
				{
					num2 = i;
					break;
				}
		}
		else
		{
			num1 = 2;
			num2 = 2 + d;
		}			
		ans[n] = num1 * num2;
	}
	for (int i = nn - 1;i >= 0;i--)
		cout << ans[i] << endl;

	return 0;
}

int isPrime(int num)
{
	int i;
	for (i = 2; num >= i * i; i++)
		if (num % i == 0)
			return 0;
	return 1;
}