#include<iostream>
using namespace std;

class Base
{
	int m_a;
	public:
	Base(int a=0):m_a(a){}
	void display(){cout<<m_a<<" ";}
};

class Derived:public Base
{
	int m_b;
	public:
	Derived(int a=0,int b=0):Base(a),m_b(b){}
	void display(){Base::display(); cout<<m_b<<endl;}
};

int main()
{
	Base bobj(10);
	Derived dobj(100,200);
	
	bobj.display();
	cout<<endl;
	dobj.display();
	
	cout<<"\nPointer"<<endl;
	Base *bptr=&bobj;
	bptr->display();
	cout<<endl;
	bptr=&dobj;			
	bptr->display();	
	
	cout<<"\nReference"<<endl;
	Base &bref1=bobj;
	bref1.display();
	cout<<endl;
	Base &bref2=dobj;
	bref2.display();	
	
	cout<<"\nPointer"<<endl;
	Derived *dptr=&dobj;
	dptr->display();
	
	cout<<"\nReference"<<endl;
	Derived &dref1=dobj;
	dref1.display();
	cout<<endl;

}