#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;

int main()
{
	ifstream fin("D:\\NNUCS\\MyProjects\\19200213李铖彧1_1\\data.txt", ios_base::in);
	if (!fin)
	{
		cout << "Can't open file: data.txt" << endl;
		exit(0);
	}
	ofstream fout("D:\\NNUCS\\MyProjects\\19200213李铖彧1_1\\result.txt", ios_base::out);
	if (!fout)
	{
		cout << "Can't open file: result.txt" << endl;
		exit(0);
	}
	int a[100];
	int count = 0;
	while (!fin.eof())
	{
		if (fin.peek() < 48 || fin.peek() > 57)
			fin.ignore();
		else
		{
			fin >> a[count];
			count++;
		}
		if (count >= 100)
			break;
	}
	for (int i = 0; i < count; i++)
	{
		cout << setw(5) << a[i]; //输出到屏幕
		if ((i + 1) % 8 == 0)
			cout << "\n";
		fout << setw(5) << a[i]; //输出到文件
		if ((i + 1) % 8 == 0)
			fout << "\n";
	}
	return 0;
}



