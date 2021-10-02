#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int fun(int a[], int n)
{
	int t, s, ans = n;
	for (int i = 0;i < n;i++)
	{
		for (t = a[i];t > 0;t /= 10)
		{
			s = t % 10;
			if (s == 2 || s == 4)
			{
				for (int j = i;j < n - 1;j++)
					a[j] = a[j + 1];
				ans--;
				i--;
				break;
			}
		}

	}
	return ans;
}
int main()
{
	int array[100], count = 0;
	ifstream in("D:\\NNUCS\\MyProjects\\19200213李铖彧1_1\\data.txt");
	if (!in)
	{
		cout << "无法打开文件!" << endl;
		exit(0);
	}
	while (in >> array[count])
	{
		count++;
	}
	count = fun(array, count);
	for (int i = 0;i < count;i++)
	{
		cout << setw(5) << array[i];
		if ((i + 1) % 8 == 0)
			cout << "\n";

	}
	in.close();

	ofstream fout("D:\\NNUCS\\MyProjects\\19200213李铖彧1_1\\result.txt");
	if (!fout)
	{
		cout << "无法输出!\n";
		exit(0);
	}
	for (int i = 0;i < count;i++)
	{
		fout << setw(5) << array[i];
		if ((i + 1) % 8 == 0)
			fout << "\n";

	}
	fout.close();

	return 0;
}