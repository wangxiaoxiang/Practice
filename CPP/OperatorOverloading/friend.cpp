#include<iostream>

using namespace std;

class Complex
{
public:
	Complex(double m_a,double m_b):m_a(m_a),m_b(m_b){};
private:
	friend istream& operator >> (istream& is, Complex&);
	friend ostream& operator << (ostream& os, const Complex&);
	double m_a,m_b;
};

istream& operator >> (istream& is, Complex& c)
{
	is>>c.m_a>>c.m_b;
	return is;
}

ostream& operator << (ostream& os, const Complex& c)
{
	os<<"a:"<<c.m_a<<"  b:"<<c.m_b;
	return os;
}

class Sum
{
public:
	Sum(const Complex& c1,const Complex& c2):c1(c1),c2(c2)
	{
		Complex cs(c1.m_a+c2.m_a,c1.m_b+c2.m_b);
		this->cs = cs;
	};
	void show()
	{
		cout<<"sum:"<<cs<<endl;
	}
private:
	Complex cs;
	Complex c1;
	Complex c2;
}

void test_operator()
{
	Complex a(0,0);
	Complex b(0,0);
	cout<<"a |"<<a<<endl;
	cout<<"b |"<<b<<endl;
	Sum sum(a,b);
	sum.show();

	cin>>a;
	cin>>b;
	cout<<"a |"<<a<<endl;
	cout<<"b |"<<b<<endl;
	Sum sum2(a,b);
	sum2.show();
	/*
	//Result
	a |re:0  im:0
	b |re:0  im:0
	1 1
	2 2
	a |re:1  im:1
	b |re:2  im:2
	*/
}

int main(int argc,char** argv)
{
	test_operator();
	return 0;
}
