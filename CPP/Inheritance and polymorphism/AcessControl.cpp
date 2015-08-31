#include<iostream>

using namespace std;

class A
{
private:
	int m_pri;
protected:
	int m_pro;
public:
	int m_pub;
	A(int pri = 0,int pro = 0,int pub = 0):m_pri(pri),m_pro(pro),m_pub(pub)
	{
		cout<<"init A"<<endl;	
	}
	
	~A()
	{
		cout<<"deinit A"<<endl;	
	}
	
	void show()
	{
		cout<<"pri::"<<this->m_pri<<endl;
		cout<<"pro::"<<this->m_pro<<endl;
		cout<<"pub::"<<this->m_pub<<endl;
	}
};

class PriB:private A
{
public:
	PriB(int pri = 0,int pro = 0,int pub = 0):A(pri,pro,pub)
	{
		cout<<"init PriB"<<endl;	
	}
	void PriB_show()
	{
		//error:'m_pri' is a private member of 'A'
		// cout<<"pri::"<<this->m_pri<<endl;
		cout<<"pro::"<<this->m_pro<<endl;
		cout<<"pub::"<<this->m_pub<<endl;
	}
};

class ProC:protected A
{
public:
	ProC(int pri = 0,int pro = 0,int pub = 0):A(pri,pro,pub)
	{
		cout<<"init ProC"<<endl;	
	}
	void ProC_show()
	{
		// error: 'm_pri' is a private member of 'A'
		//cout<<"pri::"<<this->m_pri<<endl;
		cout<<"pro::"<<this->m_pro<<endl;
		cout<<"pub::"<<this->m_pub<<endl;
	}
};

class PubD:public A
{
public:
	PubD(int pri = 0,int pro = 0,int pub = 0):A(pri,pro,pub)
	{
		cout<<"init PubD"<<endl;	
	}
	void PubD_show()
	{
		//error: 'm_pri' is a private member of 'A'
		//cout<<"pri::"<<this->m_pri<<endl;
		cout<<"pro::"<<this->m_pro<<endl;
		cout<<"pub::"<<this->m_pub<<endl;
	}
	friend ostream& operator<<(ostream& os,PubD& d)
	{
		//error: 'm_pri' is a private member of 'A'
		//os<<"friend::pri::"<<d.m_pri<<endl;
		os<<"friend::pro::"<<d.m_pro<<endl;
		os<<"friend::pub::"<<d.m_pub<<endl;
		return os;
	}
};

int main(int argc,char** argv)
{
	PriB pb;
	pb.PriB_show();
	//error: 'show' is a private member of 'A'
	// pb.show();
	
	ProC pc;
	pc.ProC_show();
	//error: 'show' is a protected member of 'A'
	// pc.show();
	
	PubD pd;
	pd.PubD_show();
	//OK
	pd.show();
	
	cout<<pd<<endl;
	return 0;
}