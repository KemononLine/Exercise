#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
//compare�ȽϺ�������ȷ���0�����ڷ���1��С�ڷ���-1
int compare(string str1, string str2)
{
    if (str1.length() > str2.length()) return 1;
    else if (str1.length() < str2.length())  return -1;
    else return str1.compare(str2);
}
//�߾��ȼӷ�
//ֻ���������������
string add(string str1, string str2)//�߾��ȼӷ�
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    //ǰ�油0��Ū�ɳ�����ͬ
    if (len1 < len2)
    {
        for (int i = 1;i <= len2 - len1;i++)
            str1 = "0" + str1;
    }
    else
    {
        for (int i = 1;i <= len1 - len2;i++)
            str2 = "0" + str2;
    }
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1;i >= 0;i--)
    {
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0)  str = char(cf + '0') + str;
    return str;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout<<add(str1, str2);
    return 0;
}

