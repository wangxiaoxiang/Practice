#include<iostream>

using namespace std;

class Complex
{
public:
	Complex(double m_a = 0.0f,double m_b = 0.0f):m_a(m_a),m_b(m_b){};
	
	void setA(double a)
	{
		this->m_a = a;
	}
	void setB(double b)
	{
		this->m_b = b;
	}
	double getA() const
	{
		return this->m_a;
	}
	double getB() const
	{
		return this->m_b;
	}

	const Complex operator + (const Complex&) const;
	const Complex operator - (const Complex&) const;
	const Complex operator * (const Complex&) const;
	const Complex operator / (const Complex&) const;

private:
	friend istream& operator >> (istream& is, Complex&);
	friend ostream& operator << (ostream& os, const Complex&);
	double m_a,m_b;
};


const Complex Complex::operator + (const Complex& t) const 
{
	Complex com;
	com.setA(this->getA() + t.getA());
	com.setB(this->getB() + t.getB());
	return com;
}


const Complex Complex::operator - (const Complex& t) const 
{

	Complex com;
	com.setA(this->getA() - t.getA());
	com.setB(this->getB() - t.getB());
	return com;
}

const Complex Complex::operator * (const Complex& t) const 
{
	Complex com;
	com.setA(this->getA() * t.getA());
	com.setB(this->getB() * t.getB());
	return com;
}

const Complex Complex::operator / (const Complex& t) const 
{
	Complex com;
	com.setA(this->getA() / t.getA());
	com.setB(this->getB() / t.getB());
	return com;
}

istream& operator >> (istream& is, Complex& c)
{
	is>>c.m_a>>c.m_b;
	return is;
}

ostream& operator << (ostream& os, const Complex& c)
{
	os<<"m_a:"<<c.m_a<<"\tm_b:"<<c.m_b;
	return os;
}

void test_operator()
{
	Complex a(1,1);
	Complex b(2,2);
	cout<<"a   |"<<a<<endl;
	cout<<"b   |"<<b<<endl;
	cout<<"a+b |"<<a+b<<endl;
    cout<<"a-b |"<<a-b<<endl;
	cout<<"a*b |"<<a*b<<endl;
	cout<<"a/b |"<<a/b<<endl;
	cout<<endl<<endl;

	cin>>a;
	cin>>b;
	cout<<"a   |"<<a<<endl;
	cout<<"b   |"<<b<<endl;
	cout<<"a+b |"<<a+b<<endl;
    cout<<"a-b |"<<a-b<<endl;
	cout<<"a*b |"<<a*b<<endl;
	cout<<"a/b |"<<a/b<<endl;
	/*
	//Result
	a   |m_a:1	m_b:1
	b   |m_a:2	m_b:2
	a+b |m_a:3	m_b:3
	a-b |m_a:-1	m_b:-1
	a*b |m_a:2	m_b:2
	a/b |m_a:0.5	m_b:0.5
	
	3 4
	5 6
	a   |m_a:3	m_b:4
	b   |m_a:5	m_b:6
	a+b |m_a:8	m_b:10
	a-b |m_a:-2	m_b:-2
	a*b |m_a:15	m_b:24
	a/b |m_a:0.6	m_b:0.666667
	*/
}

int main(int argc,char** argv)
{
	test_operator();
	return 0;
}
