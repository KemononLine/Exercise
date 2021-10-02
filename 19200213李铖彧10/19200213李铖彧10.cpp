#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926535;
class Point
{
private:
	double x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double xv, double yv)
	{
		x = xv;
		y = yv;
	}
	Point(Point& pt)
	{
		x = pt.x;
		y = pt.y;
	}

	double Getx()
	{
		return x;
	}
	double Gety()
	{
		return y;
	}
	double Area()
	{
		return 0;
	}
	void Show()
	{
		cout << "x= " << x << '  ' << "y= " << y << endl;
	}
};

class Circle:public Point
{
	double radius;
public:
	Circle()
	{
		radius = 0;
	}
	Circle(double xv, double yv, double vv) :Point(xv, yv)
	{
		radius = vv;
	}
	Circle(Circle& cc,double xv,double yv):Point(xv,yv)
	{
		radius = cc.radius;
	}
	
	double Area()
	{
		return PI * radius * radius;
	}
	void Show()
	{
		cout << "x= " << Getx() << '\t' << "y= " << Gety() << '\t' << "radius= " << radius << endl;
	}
	int Position(Point& pt)
	{
		double distance = sqrt((Getx() - pt.Getx()) * (Getx() - pt.Getx()) + (Gety() - pt.Gety()) * (Gety() - pt.Gety()));
		double s = distance - radius;
		if (s == 0)
			return 0;
		else if (s < 0)
			return -1;
		else
			return 1;
	}
};

class Rectangle :public Point
{
	double width, length;
public:
	Rectangle()
	{
		width = 0;
		length = 0;
	}
	Rectangle(double xv, double yv, double wv, double lv) :Point(xv, yv)
	{
		width = wv;
		length = lv;
	}
	Rectangle(Rectangle& rr, double xv, double yv):Point (xv,yv)
	{
		width = rr.width;
		length = rr.length;
	}

	double Area()
	{
		return width * length;
	}
	void Show()
	{
		cout << "x= " << Getx() << '\t' << "y= " << Gety() << '\t';
		cout << "width= " << width << '\t' << "length= " << length << '\t' << endl;
	}
	int Position(Point& pt)
	{
		double s1, s2;
		s1 = (pt.Getx() - Getx());
		s2 = (pt.Gety() - Gety());
		if (((s1 == 0 || s1 == width) && s2 <= length) || ((s2 == 0 || s2 == length) && s1 <= width)) 
			return 0;
		else if (s1 < width && s2 < length) 
			return -1;
		else 
			return 1;
	}
};

int main()
{
	Circle cc1(3, 4, 5), cc2, cc3(cc1);
	Rectangle rt1(0, 0, 6, 8), rt2, rt3(rt1);
	Point p1(0, 0), p2(6, 8), p3(3, 3), p4(8, 4), p5(8, 8);
	cc1.Show(); 
	cc2.Show(); 
	rt1.Show(); 
	rt2.Show();
	cout << "点p1:";
	p1.Show();
	cout << "矩形rt3:" << '\t';
	rt3.Show();
	switch (rt3.Position(p1))
	{
		case 0:cout << "在矩形上" << endl;	break;
		case -1:cout << "在矩形内" << endl;	break;
		case 1:cout << "在矩形外" << endl;	break;
	}
	cout << "圆cc3:" << '\t';
	cc3.Show();
	switch (cc3.Position(p1))
	{
		case 0:cout << "在圆上" << endl;	break;
		case -1:cout << "在圆内" << endl;	break;
		case 1:cout << "在圆外" << endl;	break;
	}
	cout << "点p2:"; 
	p2.Show(); 
	cout << "矩形rt3:" << '\t';
	rt3.Show();
	switch (cc3.Position(p2))
	{
		case 0:cout << "在圆上" << endl;	break;
		case -1:cout << "在矩形内" << endl;	break;
		case 1:cout << "在矩形外" << endl;	break;
	}
	cout << "圆cc3:" << '\t'; 
	cc3.Show();
	switch (cc3.Position(p2))
	{
		case 0:cout << "在圆上" << endl;	break;
		case -1:cout << "在圆内" << endl;	break;
		case 1:cout << "在圆外" << endl;	break;
	}
	cout << "点p3:"; 
	p3.Show(); 
	cout << "矩形rt3:" << '\t'; 
	rt3.Show();
	switch (rt3.Position(p3))
	{
		case 0:cout << "在矩形上" << endl;	break;
		case -1:cout << "在矩形内" << endl;	break;
		case 1:cout << "在矩形外" << endl;	break;
	}
	cout << "圆cc3:" << '\t'; 
	cc3.Show(); 
	switch (cc3.Position(p3))
	{
		case 0:cout << "在圆上" << endl;	break;
		case -1:cout << "在圆内" << endl;	break;
		case 1:cout << "在圆外" << endl;	break;
	}
	cout << "点p4:";
	p4.Show();
	cout << "矩形rt3:" << '\t';
	rt3.Show();
	switch (rt3.Position(p4))
	{
		case 0:cout << "在矩形上" << endl;	break;
		case -1:cout << "在矩形内" << endl;	break;
		case 1:cout << "在矩形外" << endl;	break;
	}
	cout << "圆cc3:" << '\t';
	cc3.Show();
	switch (cc3.Position(p4))
	{
		case 0:cout << "在圆上" << endl;	break;
		case -1:cout << "在圆内" << endl;	break;
		case 1:cout << "在圆外" << endl;	break;
	}
	cout << "点p5:";
	p5.Show();
	cout << "矩形rt3:" << '\t';
	rt3.Show();
	switch (rt3.Position(p5))
	{
		case 0:cout << "在矩形上" << endl;	break;
		case -1:cout << "在矩形内" << endl;	break;
		case 1:cout << "在矩形外" << endl;	break;
	}
	cout << "圆cc3:" << '\t';
	cc3.Show();
	switch (cc3.Position(p5))
	{
		case 0:cout << "在圆上" << endl;	break;
		case -1:cout << "在圆内" << endl;	break;
		case 1:cout << "在圆外" << endl;	break;
	}

	return 0;
}