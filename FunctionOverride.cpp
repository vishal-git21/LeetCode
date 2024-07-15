/* #include<iostream>
using namespace std;

class B
{
	public:
		void x(){cout<<"I'm B's x"<<endl;}
		void y(){cout<<"I'm B's y"<<endl;}
};

class D:public B
{
	public:
		void x(int a){cout<<"I'm D's overloaded x"<<endl;}
		void y(){cout<<"I'm D's y"<<endl;}
		void z(){cout<<"I'm new to D"<<endl;}
};

int main()
{
	B bobj;
	bobj.x();
	bobj.y();
	
	cout<<endl<<endl;
	D dobj;
//	dobj.x(2);		//Okay
//	dobj.x();		//Error
//	dobj.B::x();	//Okay
//	dobj.y();
//	dobj.B::y();
//	dobj.z();
} */

#include<iostream>
using namespace std;

class B
{
	public:
		void x(){cout<<"I'm B's x"<<endl;}
		void y(){cout<<"I'm B's y"<<endl;}
};

class D:public B
{
	public:
		using B::x;
		void x(int a){cout<<"I'm D's overloaded x"<<endl;}
		void y(){cout<<"I'm D's y"<<endl;}
		void z(){cout<<"I'm new to D"<<endl;}
};

int main()
{
	B bobj;
	bobj.x();
	bobj.y();
	
	cout<<endl<<endl;
	D dobj;
	dobj.x(2);
	dobj.x();		
}