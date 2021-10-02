#include <iostream>
#include <string>
using namespace std;
class CTeacher
{
public:
	CTeacher(string nam, string s, string tit, string ad, string t);
	void display();
protected:
	string name; string sex; string title; string address; string tel;
};
CTeacher::CTeacher(string nam, string s, string tit, string ad, string t)
	: name(nam), sex(s), title(tit), address(ad), tel(t)
{ }
void CTeacher::display()
{
	cout << "Name:" << name << endl;
	cout << "Gender:" << sex << endl;
	cout << "Title:" << title << endl;
	cout << "Address:" << address << endl;
	cout << "Telphone:" << tel << endl;
}
class CAdministrator
{
public:
	CAdministrator(string nam, string s, string p, string ad, string t);
	void display();
protected:
	string name; string sex; string post; string address; string tel;
};
CAdministrator::CAdministrator(string nam, string s, string p, string ad, string t)
	: name(nam), sex(s), post(p), address(ad), tel(t)
{ }
void CAdministrator::display()
{
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
	cout << "post:" << post << endl;
	cout << "address:" << address << endl;
	cout << "tel:" << tel << endl;
}
class CTeacher_Administrator :public CTeacher, public CAdministrator
{
public:
	CTeacher_Administrator(string nam, string s, string t, string p, string ad, string tel, float w);
	void show();
protected:
	float wage;
};
CTeacher_Administrator::CTeacher_Administrator(string nam, string s, string t, string p, string ad, string tel, float w)
	:CTeacher(nam, s, t, ad, tel), CAdministrator(nam, s, p, ad, tel), wage(w)
{ }
void CTeacher_Administrator::show()
{
	CTeacher::display();
	cout << "职务:" << CAdministrator::post << endl;
	cout << "工资:" << wage << endl;
}
int main()
{
	CTeacher_Administrator a("zz", "man", "superior", "teacher", "ninghai road cal center", "13800000000", 5000);
	a.show();
	system("pause");
	return 0;
}