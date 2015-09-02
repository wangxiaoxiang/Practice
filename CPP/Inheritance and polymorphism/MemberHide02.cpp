#include<iostream>

using namespace std;

class A
{
public:
	static int m_x;
	A(){}
	static void show()
	{
		cout<<"static A::show()"<<endl;
	}
};

int A::m_x = -100;

class B:public A
{
public:
	static int m_x;
	B(){}
	static void show(int n)
	{
		cout<<"static B:show(int)\t"<<n<<endl;
	}
	
	static void run()
	{
		// error: too few arguments to function call, single argument 'n' was not specified
		// show();
		show(m_x);//使用本类的m_x和show(int)方法。
		show(A::m_x);//使用基类的m_x和本类的show(int)方法。
		A::show();//调用基类的show()方法。
	}
};
int B::m_x = 100;

int main(int argc,char** argv)
{
	B::run();
	//error: too few arguments to function call, expected 1,have 0; did you mean 'A::show'?
	//note: 'A::show' declared here
	// B::show();
	B::A::show();
	B::show(B::m_x);
	B::show(B::A::m_x);
	
	
	return 0;
}