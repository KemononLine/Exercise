/********************************************************************
File name    :  f0309.cpp
Description  :  普通函数作为友元函数 矩阵*向量
********************************************************************/
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
	friend Vector multiply1(Matrix& m, Vector& v);
public:
	void set(int, int);
	void remove()
	{
		delete[] m;
	}

	int sizeL();
	int sizeR();
	int& elem(int, int);
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
int& Matrix::elem(int i, int j) 	//引用返回的目的是返回值可以作左值
{
	if (i < 0 || szl <= i || j < 0 || szr <= j)
	{
		cerr << "Matrix index out of range.\n";
		exit(1);
	}
	return m[i * szr + j];
}

class Vector
{
	int* v;             				//指向一个数组,表示向量
	int sz;
public:
	friend Vector multiply1(Matrix& m, Vector& v);
	friend Matrix;
	void remove()
	{
		delete[] v;
	}
	int size()
	{
		return sz;
	}
	
	void set(int);
	void display();
	int& operator[](int);
};	
void Vector::set(int s)
{
	sz = s;
	if (s <= 0)
	{
		cerr << "bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
	assert(v);
}
int& Vector::operator[](int i)  	//引用返回的目的是返回值可以作左值
{
	if (i < 0 || i >= sz)
	{
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	return v[i];
}
void Vector::display()
{
	for (int i = 0; i < sz; ++i)
		cout << v[i] << " ";
	cout << "\n";
}

Vector multiply(Matrix& m, Vector& v)	//矩阵乘向量
{
	if (m.sizeR() != v.size())
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;                   		//创建一个存放结果的空向量
	r.set(m.sizeL());       //不能够写m.szl
	for (int i = 0; i < m.sizeL(); i++)
	{
		r[i] = 0;       //r.elem(i)=0;
		for (int j = 0; j < m.sizeR(); j++)
			r[i] += m.elem(i, j) * v[j];//r.elem(i)+=m.elem(i,j)*v.elem(j);
	}
	return r;
}

Vector multiply1(Matrix&m,Vector& v) 	//矩阵乘向量
{
	if (m.szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r;
	r.set(m.szl);       					//创建一个存放结果的空向量
	for (int i = 0; i < m.szl; i++)
	{
		r[i] = 0;
		for (int j = 0; j <m.szr; j++)
			r[i] += m.m[i * m.szr + j] * v.v[j];
	}
	return r;
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
