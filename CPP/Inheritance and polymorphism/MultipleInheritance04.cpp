#include<iostream>
using namespace std;

class A
{
	char m_a[2];
};

class B
{
	int m_b;
};

class C:public A,public B
{
	
};

int main(int argc,char** argv)
{
	A* pa;
	B* pb;
	C* pc = new C;
	
	// 通用类型转换可能(因编译器而异)做指针计算，
	// pb比pa和pc向下偏移两个整型(m_a[2])
	pa = (A*) (pc);
	pb = (B*) (pc);
	cout << "pa = " << pa
		 << ", pb = " << pb
		 <<", pc = " << pc 
		 << endl;
			
	
	// 静态类型转换做指针计算，pb比pa和pc向下偏移两个整型(m_a[2])
	pa = static_cast<A*> (pc);
	pb = static_cast<B*> (pc);
	cout << "static_cast : pa = " << pa
		 << ", pb = " << pb
		 <<", pc = " << pc 
		 << endl;
	//重解释类型转换不做指针计算，pb、pa和pc的值完全一样
	pa = reinterpret_cast<A*> (pc);
	pb = reinterpret_cast<B*> (pc);
	cout << "reinterpret_cast : pa = " << pa
		 << ", pb = " << pb
		 <<", pc = " << pc 
		 << endl;
	return 0;
}