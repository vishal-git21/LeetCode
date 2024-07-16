#include<iostream>
using namespace std;

class Shape
{
	public:
	virtual double area()=0;
};

class Rectangle:public Shape
{
	double length;
	double breadth;
	public:
	Rectangle(double l,double b){length=l; breadth=b;}
	double area()
	{
		return length*breadth;
	}
};

class Circle:public Shape
{
	double radius;
	public:
	Circle(double r){radius=r;}
	double area()
	{
		return 3.142*radius*radius;
	}
};

int main()
{
	Rectangle r(2,3);
	cout<<"Area of rectangle="<<r.area()<<endl;
	
	Circle c(1);
	cout<<"Area of circle="<<c.area()<<endl;
}