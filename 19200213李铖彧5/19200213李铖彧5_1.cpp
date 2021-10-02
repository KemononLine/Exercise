/*
#include<iostream>
#include<fstream>
#include <cassert>
#include <ctime>
using namespace std;

class Matrix;

class Matrix
{
	int* m;
	int szl, szr;
public:
	void set(int, int);
	void display();
	void remove()
	{
		delete[] m;
	}

	int sizeL();
	int sizeR();
	int& elem(int, int);
	int& operator[](int);

	Matrix multiply1(Matrix& m, Matrix& m2);
};
int Matrix::sizeL()
{
	return szl;
}
int Matrix::sizeR()
{
	return szr;
}
void Matrix::set(int i, int j)
{
	szl = i;
	szr = j;
	if (i <= 0 || j <= 0)
	{
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	m = new int[i * j];
	assert(m);
}

void Matrix::display()
{

}

int& Matrix::elem(int i, int j) 	//引用返回的目的是返回值可以作左值
{
	if (i < 0 || szl <= i || j < 0 || szr <= j)
	{
		cerr << "Matrix index out of range.\n";
		exit(1);
	}
	return m[i * szr + j];
}

int& Matrix::operator[](int)
{

}

Matrix Matrix:: multiply1(Matrix& m, Matrix& m2) 	//矩阵乘矩阵
{
	if (m.szr != m2.szl)
	{
		cerr << "bad multiply Matrix with Matrix.\n";
		exit(1);
	}
	Matrix ans;
	ans.set(m.szl,m2.szr);       					//创建一个存放结果的空矩阵
	for (int i = 0; i < m.szl*m2.szr; i++)
	{
		ans[i] = 0;
		for (int j = 0; j < m.szl*m2.szr; j++)
			ans[i] += m.m[i * m.szr + j] * v.v[j];
	}
	return ans;
}

void main()
{
	ifstream in("in.txt");
	if (!in)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	int x, y;
	in >> x >> y;
	Matrix ma;
	ma.set(x, y);
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			in >> ma.elem(i, j);
	in >> x;
	Vector ve;
	ve.set(x);
	for (int i = 0; i < x; ++i)
		in >> ve[i];
	Vector vx;
	double t_start = clock();
	for (int i = 0;i < 10000000;i++)
		vx = multiply(ma, ve);
	cout << clock() - t_start << endl;
	vx.display();
	t_start = clock();
	for (int i = 0;i < 10000000;i++)
		vx = multiply1(ma, ve);
	cout << clock() - t_start << endl;
	vx.display();
	ma.remove();
	ve.remove();
	vx.remove();
}
*/
#include<iostream>
#include<fstream>
#include <cassert>
#include <ctime>
using namespace std;

class Vector;
class Matrix;

class Matrix
{
	int* m;
	int szl, szr;
public:
	void set(int, int);
	void remove()
	{
		delete[] m;
	}
	int sizeL();
	int sizeR();
	int& elem(int, int);
	
	Matrix()
	{
		szl = 0;
		szr = 0;
		m = NULL;
	}
	Matrix(Matrix& me)
	{
		set(me.sizeL(), me.sizeR());
		for (int i = 0;i < szl;i++)
			for (int j = 0;j < szr;j++)
				m[i * szr + j] = me.m[i * szr + j];
	}
	~Matrix()
	{
		delete[] m;
	}
	Matrix& operator =(Matrix& me)
	{
		if (this != &me)
		{
			if (szl != 0 && szr != 0)
				delete[]m;
			set(me.sizeL(), me.sizeR());
			for (int i = 0;i < szl;i++)
				for (int j = 0;j < szr;j++)
				{
					m[i * szr + j] = me.elem(i, j);
				}
		}
		return *this;
	}
	Matrix& operator = (const Matrix mm)
	{
		int i, j;
		if (this != &mm)
		{
			if (szl != 0 && szr != 0)
				delete[]m;
			set(mm.szl, mm.szr);
			for (i = 0;i < szl;i++)
				for (j = 0;j < szr;j++)
					m[szr * i + j] = mm.m[szr * i + j];
		}
		return *this;
	}

	void display()
	{
		for (int i = 0;i < szl;i++)
		{
			for (int j = 0;j < szr;j++) printf("%5d", m[i * szr + j]);
			cout << endl;
		}
	}
};

int Matrix::sizeL()
{
	return szl;
}
int Matrix::sizeR()
{
	return szr;
}
void Matrix::set(int i, int j)
{
	szl = i;
	szr = j;
	if (i <= 0 || j <= 0)
	{
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	m = new int[i * j];
	assert(m);
}
int& Matrix::elem(int i, int j) 	
{
	if (i < 0 || szl <= i || j < 0 || szr <= j)
	{
		cerr << "Matrix index out of range.\n";
		exit(1);
	}
	return m[i * szr + j];
}

Matrix multiply(Matrix& a, Matrix& b)
{
	if (a.sizeR() != b.sizeL())
	{
		cerr << "bad multiply Matrix with Matrix.\n";
		exit(1);
	}
	int i, j, k;
	Matrix r;
	r.set(a.sizeL(), b.sizeR());
	for (i = 0;i < r.sizeL();i++) for (j = 0;j < r.sizeR();j++) r.elem(i, j) = 0;
	for (i = 0; i < r.sizeL(); i++)
	{
		for (j = 0; j < r.sizeR(); j++)
		{
			for (k = 0;k < a.sizeR();k++) r.elem(i, j) += a.elem(i, k) * b.elem(k, j);
		}
	}
	return r;
}

void main()
{
	ifstream in("data.txt");
	if (!in)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	int x1, y1,x2,y2;
	in >> x1 >> y1;											//给矩阵ma赋值
	Matrix m1;
	m1.set(x1, y1);
	for (int i = 0; i < x1; ++i)
		for (int j = 0; j < y1; ++j)
			in >> m1.elem(i, j);
	
	in >> x2 >> y2;											//给矩阵mb赋值
	Matrix m2;
	m2.set(x2, y2);
	for (int i = 0; i < x2; ++i)
		for (int j = 0; j < y2; ++j)
			in >> m2.elem(i, j);
	Matrix m3;											//储存矩阵相乘结果的矩阵mc
	m3 = multiply(m1, m2);
	m3.display();
}


