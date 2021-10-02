#include <iostream>
class Cpoint
{
	int x;
	int y;
public:
	Cpoint(int x = 0,int  y = 0)
	{
		this->x = x;
		this->y = y;
	}
	Cpoint(const Cpoint& pt)
	{
		x = pt.x;
		y = pt.y;
	}
	~Cpoint()
	{}
	friend Cpoint& operator++(Cpoint&);
	friend Cpoint& operator++(Cpoint&,int);
	friend Cpoint& operator+(Cpoint&,int);
	friend std::istream& operator>>(std::istream&,Cpoint&);
	friend std::ostream& operator<<(std::ostream&,Cpoint&);
};
Cpoint& operator++(Cpoint& obj)
{
	++obj.x;
	++obj.y;
	return obj;
}
Cpoint& operator++(Cpoint& obj2, int)
{
	Cpoint temp(obj2);
	++obj2.x;
	++obj2.y;
	return temp;
}
Cpoint& operator+(Cpoint& obj3, int i)
{
	Cpoint temp(obj3);
	temp.x = obj3.x + i;
	temp.y = obj3.y + i;
	return temp;
}
std::istream& operator>>(std::istream& in, Cpoint& obj)
{
	in >> obj.x >> obj.y;
	return in;
}
std::ostream& operator<<(std::ostream& out, Cpoint& obj)
{
	out << obj.x <<","<< obj.y;
	return out;
}

void main()
{
	Cpoint pos1, pos2;
	std::cout << "Please input a position:	" << std::endl;
	std::cin >> pos1;
	std::cout << "pos1:	" << pos1 << std::endl;
	std::cout << "Front ++ pos1" << std::endl;
	pos2 = ++pos1;
	std::cout << pos1 << std::endl;
	std::cout << "The result of Front ++ is: " << pos2 << std::endl;
	std::cout << "Back ++ pos1" << std::endl;
	pos2 = pos1++;
	std::cout << pos1 << std::endl;
	std::cout << "The result of Back ++ is: " << pos2 << std::endl;
	std::cout << "Postion + pos1" << std::endl;
	pos2 = pos1 + 5;
	std::cout << pos1 << std::endl;
	std::cout << "The result of Postion + pos1 is: " << pos2 << std::endl;
}