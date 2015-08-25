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
	//自增自减操作符
	//前++
	Complex& operator ++ (void);
	//前--
	Complex& operator -- (void);
	//后++
	Complex  operator ++ (int);
	//后--
	Complex  operator -- (int);
	//单目操作符
	/*返回值*/       
	const Complex operator - (void) const
	{
		return Complex(-this->getA(),-this->getB());
	}
	//双目操作符
	const Complex operator + (const Complex&) const;
	const Complex operator - (const Complex&) const;
	const Complex operator * (const Complex&) const;
	const Complex operator / (const Complex&) const;

private:
	friend istream& operator >> (istream& is, Complex&);
	friend ostream& operator << (ostream& os, const Complex&);
	double m_a,m_b;
};


Complex& Complex::operator ++ (void)
{
	++m_a;
	++m_b;
	return *this;
}

Complex& Complex::operator -- (void)
{
	
	--m_a;
	--m_b;
	return *this;
}

Complex  Complex::operator ++ (int)
{
	Complex old = *this;
	m_a++;
	m_b++;
	return old;
}

Complex  Complex::operator -- (int)
{
	
	Complex old = *this;
	m_a--;
	m_b--;
	return old;
}

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

void test_complex_a_b(Complex& a,Complex& b)
{
	
	cout<<"a   |"<<a<<endl;
	cout<<"b   |"<<b<<endl;
	cout<<"-a  |"<<-a<<endl;
	cout<<"-b  |"<<-b<<endl;
	cout<<"a+b |"<<a+b<<endl;
    cout<<"a-b |"<<a-b<<endl;
	cout<<"a*b |"<<a*b<<endl;
	cout<<"a/b |"<<a/b<<endl;
	cout<<"++a |"<<++a<<endl;
	cout<<"--a |"<<--a<<endl;
	cout<<"a++ |"<<a++<<endl;
	cout<<"a-- |"<<a--<<endl;
	cout<<"a   |"<<a<<endl;
	cout<<"b   |"<<b<<endl;
}

void test_operator()
{
	Complex a(1,1);
	Complex b(2,2);
	test_complex_a_b(a,b);
	cout<<endl<<endl;

	cin>>a;
	cin>>b;
	test_complex_a_b(a,b);
}
int main(int argc,char** argv)
{
	test_operator();
	return 0;
}
