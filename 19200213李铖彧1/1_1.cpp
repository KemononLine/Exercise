#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmpd(string a, string b)
{
	return a < b;
}
bool cmpl(string a, string b)
{
	return a.length() < b.length();
}

int main()
{
	vector<string> words;
	int n, i;
	string s;
	cout << "�������ַ�������:";
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> s;
		words.push_back(s);
	}

	sort(words.begin(), words.end(), cmpd);
	cout << "�ֵ�����:" << endl;
	for (i = 0;i < words.size();i++)
		cout << words[i] << endl;

	sort(words.begin(), words.end(), cmpl);
	cout << "���ʳ�������:" << endl;
	for (i = 0;i < words.size();i++)
		cout << words[i] << endl;

	return 0;
}