#include<iostream>
using namespace std;

class COMPLEX
{
	private:
		double re;
		double im;
	public:
	
		COMPLEX()
		{
			cout<<"default ctor called:"<<this<<endl;
			re=0;im=0;
		}
		COMPLEX(double r,double i)
		{
			cout<<"parameterized ctor called:"<<this<<endl;
			re=r;
			im=i;
		}
		void showComplex()
		{
			cout<<re<<"+"<<im<<"i"<<endl;
		}
		~COMPLEX(){cout<<"dtor called:"<<this<<endl;}
};

int main()
{
	COMPLEX *c1=new COMPLEX;
	COMPLEX *c2=new COMPLEX(2,3);
	c1->showComplex();
	c2->showComplex();
	
	delete c1;
	delete c2;
}