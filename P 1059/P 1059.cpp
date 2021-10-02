#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int>s;
	int a[105];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	cout << s.size() << endl;
	while (!s.empty())
	{
		cout << *s.begin() << " ";
		s.erase(s.begin());
	}
	return 0;
}