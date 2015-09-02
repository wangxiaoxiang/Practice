#include<iostream>

using namespace std;

class A
{
public:
	int m_x;
	A():m_x(-100)
	{
		
	}
	void show()
	{
		cout<<"A::show()"<<endl;
	}
};

class B:public A
{
public:
	int m_x;
	B():m_x(100)
	{
		
	}
	void show(int n)
	{
		cout<<"B:show(int)\t"<<n<<endl;
	}
	
	void run()
	{
		// error: too few arguments to function call, single argument 'n' was not specified
		// show();
		show(m_x);//使用本类的m_x和show(int)方法。
		show(A::m_x);//使用基类的m_x和本类的show(int)方法。
		A::show();//调用基类的show()方法。
	}
};

int main(int argc,char** argv)
{
	B b;
	b.run();
	//error: too few arguments to function call, expected 1,have 0; did you mean 'A::show'?
	//note: 'A::show' declared here
	// b.show();
	b.show(b.m_x);
	b.show(b.A::m_x);
	b.A::show();
	
	return 0;
}