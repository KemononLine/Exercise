#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;

int Index(int a[100], int ans, int n);
{
	int count = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == ans)
			count++;
	}
	return count;
}

int main()
{
	ifstream fin("D:\\NNUCS\\MyProjects\\192002131_1Àîîñª\\data.txt", ios_base::in);
	if (!fin)
	{
		cout << "Can't open file: data.txt" << endl;
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
	int ans;
	cin >> ans;
	int k = -1;
	while (1)
	{
		k = Index(a, ans, count);
		if (k == -1)
			break;
		cout << k;
	}
	return 0;
}


