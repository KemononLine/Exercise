#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
	String(const char* str = ""); 				          //普通构造函数
	String(const String& other); 				          //复制构造函数
	~String();									          //析构函数
	String& operator=(const String& other);	              //赋值函数
	void show()
	{
		cout << m_data << endl;
	}
private:
	char* m_data; 								         //用于保存字符串
};
String::String(const char* str)
{
	m_data = new char[1000];
	strcpy(m_data, str);
}
String::~String()
{
	delete[]m_data;
}
String::String(const String& other)
{
	m_data = new char[1000];
	strcpy(this->m_data, other.m_data);
}
String& String::operator=(const String& other)
{
	strcpy(this->m_data, other.m_data);
	return *this;
}
void main()
{
	String str1("aa"), str2;
	str1.show();
	str2 = str1;
	str2.show();
	String str3(str2);
	str3.show();
}