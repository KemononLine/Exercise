#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student();
	Student(string ID, string name, char sex, string birthday, string stu_class, string teacher, string result);
	Student(const Student& obj);

	~Student(void);
	void Set(string ID, string name, char sex, string birthday, string stu_class, string teacher, string result);
	void Show();


private:
	string ID;
	string name;
	char sex;
	string birthday;
	string stu_class;
	string teacher;
	string result;

};

Student::Student(void)
{}

Student::Student(string ID, string name, char sex, string birthday, string stu_class, string teacher, string result)
{}

Student::Student(const Student& obj)
{
	ID = obj.ID;
	name = obj.name;
	sex = obj.sex;
	birthday = obj.birthday;
	stu_class = obj.stu_class;
	teacher = obj.teacher;
	result = obj.result;
}

void Student::Set(string ID, string name, char sex, string birthday, string stu_class, string teacher, string result)
{
	this->ID = ID;
	this->name = name;
	this->birthday = birthday;
	this->sex = sex;
	this->stu_class = stu_class;
	this->teacher = teacher;
	this->result = result;
}

void Student::Show()
{
	cout << "学生" << name << "的基本信息：" << endl;
	cout << "\t学号：" << ID << endl;
	cout << "\t姓名：" << name << endl;
	cout << "\t出生：" << birthday<< endl;
	cout << "\t性别：" << sex << endl;
	cout << "\t选课：" << stu_class << endl;
	cout << "\t教师：" << teacher << endl;
	cout << "\t成绩：" << result << endl;
}

Student::~Student()
{}