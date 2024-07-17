#include<iostream>
using namespace std;

class staticDemo
{
	int m_a=1000;
	static int m_b;
	public:
	const static int m_c=50;
	void setA(int a)
	{
		m_a=a;
	}
	void setB(int b)
	{
		m_b=b;
	}
	int getA() const
	{
		return m_a;
	}
	int getB() const
	{
		return m_b;
	}

	staticDemo(int a)
	{
		m_a=a;
	}
	staticDemo(){}
};
int staticDemo:: m_b;
int main()
{
	staticDemo obj1;
	staticDemo obj2;
	
	obj1.setA(10);
	obj1.setB(20);
	obj2.setA(100);
	obj2.setB(200);
	
	cout<<obj1.getA()<<" "<<obj1.getB()<<endl;
	cout<<obj2.getA()<<" "<<obj2.getB()<<endl;
	
	cout<<staticDemo::m_c<<endl;
	
	cout<<endl<<endl;
	staticDemo obj3;
	cout<<obj3.getA()<<" "<<obj3.getB()<<endl;
	cout<<staticDemo::m_c<<endl;
	
	cout<<endl<<endl;
	staticDemo obj4(10);
	cout<<obj4.getA()<<" "<<obj4.getB()<<endl;
	cout<<staticDemo::m_c<<endl;
}