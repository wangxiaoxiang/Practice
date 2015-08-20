#include<iostream>

using namespace std;

class Complex
{
    	double re,im;
public:
	Complex(double re,double im):re(re),im(im){};
	friend istream& operator >> (istream& is, Complex&);
	friend ostream& operator << (ostream& os, const Complex&);
};

istream& operator >> (istream& is, Complex& c)
{
	is>>c.re>>c.im;
	return is;
}

ostream& operator << (ostream& os, const Complex& c)
{
	os<<"re:"<<c.re<<"  im:"<<c.im;
	return os;
}

void test_io_operator()
{
	Complex a(0,0);
	Complex b(0,0);
	cout<<"a |"<<a<<endl;
	cout<<"b |"<<b<<endl;
	cin>>a;
	cin>>b;
	cout<<"a |"<<a<<endl;
	cout<<"b |"<<b<<endl;
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
	test_io_operator();
	return 0;
}
