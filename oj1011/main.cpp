#include <iostream>
#include <iomanip>
using namespace std;

//ac

class MyComplex
{


public:
	 double x,y;
	MyComplex operator+(const MyComplex &obj)
	{
	MyComplex tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	return tmp;
	}
	MyComplex operator-(const MyComplex &obj)
	{
	MyComplex tmp;
	tmp.x = x - obj.x;
	tmp.y = y - obj.y;
	return tmp;
}
	MyComplex operator*(const MyComplex &obj)
	{
	MyComplex tmp;
	tmp.x = x * obj.x - y * obj.y;
	tmp.y = x * obj.y + y * obj.x;
	return tmp;
}
	MyComplex operator/(const MyComplex &obj)
	{
	MyComplex tmp;
	tmp.x = (x * obj.x + y * obj.y) / (obj.x * obj.x + obj.y * obj.y);
	tmp.y = (-x * obj.y + y * obj.x) / (obj.x * obj.x + obj.y * obj.y);
	return tmp;
}
MyComplex operator+=(const MyComplex &obj)
{
	x = x + obj.x;
	y = y + obj.y;
	return MyComplex{x,y};
}
MyComplex operator-=(const MyComplex &obj)
{
	x = x - obj.x;
	y = y - obj.y;
	return MyComplex{x,y};
}

MyComplex operator*=(const MyComplex &obj)
{
	float tx = x, ty = y;
	x = tx * obj.x - ty * obj.y;
	y = tx * obj.y + ty * obj.x;
	return MyComplex{x,y};
}

MyComplex operator/=(const MyComplex &obj)
{
	float tx = x, ty = y;
	x = (tx * obj.x + ty * obj.y) / (obj.x * obj.x + obj.y * obj.y);
	y = (-tx * obj.y + ty * obj.x) / (obj.x * obj.x + obj.y * obj.y);
	return MyComplex{x,y};
}

    //重载输入输出运算符，只能用友元函数
    friend ostream &operator<<(ostream &os,const MyComplex &c);
    friend istream &operator>>(istream &is,MyComplex &c);
};






ostream &operator<<(ostream &os, const MyComplex &c)
{
	os<<c.x<<" "<<c.y;
	return os;
}

istream &operator>>(istream &is, MyComplex &c)
{
	is>>c.x>>c.y;
	return is;
}

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;
cout.setf(ios::fixed);
cout<<setprecision(2);
  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}
