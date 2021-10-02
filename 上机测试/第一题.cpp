#include <iostream>
using namespace std;
class Fraction
{
private:
	int f_uper, f_lower;
public:
	Fraction(int = 1, int = 1);
	void set_uper(int);
	void set_lower(int);
	friend Fraction& operator++(Fraction&);
	friend Fraction operator++(Fraction&, int);
	friend Fraction operator+(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator/(const Fraction&, const Fraction&);
	friend bool operator>(const Fraction&, const Fraction&);
	friend bool operator<(const Fraction&, const Fraction&);
	friend bool operator==(const Fraction&, const Fraction&);

	friend std::istream& operator>>(std::istream&, Fraction&);
	friend std::ostream& operator<<(std::ostream&, Fraction&);
};

Fraction::Fraction(int up, int low)
{
	f_uper = up;
	f_lower = low;
}
inline void Fraction::set_uper(int up)
{
	f_uper = up;
}
inline void Fraction::set_lower(int low)
{
	f_lower = low;
}

Fraction& operator++(Fraction& obj)
{
	obj.f_uper += obj.f_lower;
	return obj;
}
Fraction operator++(Fraction& obj, int)
{
	Fraction temp(obj);
	obj.f_uper += obj.f_lower;
	return temp;
}
Fraction operator+(const Fraction& obj1, const Fraction& obj2)
{
	Fraction temp(obj1);
	temp.f_uper = temp.f_uper * obj2.f_lower + obj2.f_uper*temp.f_lower;
	temp.f_lower *= obj2.f_lower;
	int i;
	for (i = abs(temp.f_uper);i > 0;i--)
	{
		if (temp.f_uper % i == 0 && temp.f_lower % i == 0)
			break;
	}
	temp.f_uper /= i;
	temp.f_uper /= i;
	return temp;
}
Fraction operator-(const Fraction& obj1, const Fraction& obj2)
{
	Fraction temp(obj1);
	temp.f_lower *= obj2.f_lower;
	temp.f_uper = temp.f_uper * obj2.f_lower - obj2.f_uper * temp.f_lower;
	int i;
	for (i = abs(temp.f_uper);i > 0;i--)
	{
		if (temp.f_uper % i == 0 && temp.f_lower % i == 0)
			break;
	}
	temp.f_uper /= i;
	temp.f_uper /= i;
	return temp;
}
Fraction operator*(const Fraction& obj1, const Fraction& obj2)
{
	Fraction temp(obj1);
	temp.f_uper *= obj2.f_uper;
	temp.f_lower *= obj2.f_lower;
	int i;
	for (i = abs(temp.f_uper);i > 0;i--)
	{
		if (temp.f_uper % i == 0 && temp.f_lower % i == 0)
			break;
	}
	temp.f_uper /= i;
	temp.f_uper /= i;
	return temp;
}
Fraction operator/(const Fraction& obj1, const Fraction& obj2)
{
	Fraction temp(obj1);
	temp.f_uper *= obj2.f_lower;
	temp.f_lower *= obj2.f_uper;
	int i;
	for (i = abs(temp.f_uper);i > 0;i--)
	{
		if (temp.f_uper % i == 0 && temp.f_lower % i == 0)
			break;
	}
	temp.f_uper /= i;
	temp.f_uper /= i;
	return temp;
}
bool operator>(const Fraction& obj1, const Fraction& obj2)
{
	int mul1, mul2;
	mul1 = obj1.f_uper * obj2.f_lower;
	mul2 = obj2.f_uper * obj1.f_lower;
	if (mul1 > mul2)
		return true;
	else
		return false;
}
bool operator<(const Fraction& obj1, const Fraction& obj2)
{
	int mul1, mul2;
	mul1 = obj1.f_uper * obj2.f_lower;
	mul2 = obj2.f_uper * obj1.f_lower;
	if (mul1 < mul2)
		return true;
	else
		return false;
}
bool operator==(const Fraction& obj1, const Fraction& obj2)
{
	int mul1, mul2;
	mul1 = obj1.f_uper * obj2.f_lower;
	mul2 = obj2.f_uper * obj1.f_lower;
	if (mul1 == mul2)
		return true;
	else
		return false;
}
istream& operator>>(std::istream& in, Fraction& obj)
{
	in >> obj.f_uper >> obj.f_lower;
	return in;
}
ostream& operator<<(std::ostream& out, Fraction& obj)
{
	out << obj.f_uper << "/"<<obj.f_lower;
	return out;
}

void main()
{
	Fraction a, b, c;
	cout << "Please input a fraction:	" << endl;
	cin >> a;
	cout << "fraction a:	" << a << endl;
	cout << "front ++ a:	";
	b = ++a;
	cout << a << endl;
	cout << "the result of front ++a:		";
	cout << b << endl;
	cout << "back ++ a:	";
	b = a++;
	cout << a << endl;
	cout << "the result of back ++ a:		";
	cout << b << endl;
	c = a + b;
	cout << "a+b=	" << c << endl;
	c = a - b;
	cout << "a-b=	" << c << endl;
	c = a * b;
	cout << "a*b=	" << c << endl;
	c = a / b;
	cout << "a/b=	" << c << endl;
}
