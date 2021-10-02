#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int aa, bb, cc,x,y,z,flag=0;
	cin >> x >> y >> z;
	int t = x * y * z;
	x = t / x;
	y = t / y;
	z = t / z;
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	do
	{
		aa = a[0] * 100 + a[1] * 10 + a[2];
		bb = a[3] * 100 + a[4] * 10 + a[5];
		cc = a[6] * 100 + a[7] * 10 + a[8];
		if (aa*x==bb*y&&aa*x==cc*z)
		{
			cout << aa << " " << bb << " " << cc << endl;
			flag = 1;
		}
	} while (next_permutation(a, a + 9));
	if (flag == 0)
		cout << "No!!!" << endl;
	
	return 0;

}