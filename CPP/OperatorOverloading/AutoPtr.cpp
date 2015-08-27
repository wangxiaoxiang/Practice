#include <iostream>
#include <memory>

using namespace std;

class A 
{
    
	public:
	    A()
		{
			 cout<<"A() invoked"<<endl;
		}
		~A()
		{
		cout<<"~A() invoked"<<endl;
		}
};
int main(int argc, char** argv)
{
	A* a = new A();
	auto_ptr<A> autoA(a);
	return 0;
}
