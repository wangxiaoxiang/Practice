//g++ -srd=c++11 AcessControl02.cpp

#include<iostream>
#include<string>

using namespace std;

class A
{
private:
	int m_pri;
	int m_pub;
	int m_pro;
public:
	A(int pri = 0,int pro = 0,int pub = 0):m_pri(pri),m_pro(pro),m_pub(pub)
	{
		cout<<"init A"<<endl;	
	}
	
	~A()
	{
		cout<<"deinit A"<<endl;	
	}
	
	void setPri(int pri)
	{
		this->m_pri = pri;	
	}
	
	void setPro(int pro)
	{
		this->m_pro = pro;
	}
	
	void setPub(int pub)
	{
		this->m_pub = pub;
	}
	
	const int pri() const
	{
		return this->m_pri;
	}
	
	const int pro() const
	{
		return this->m_pro;
	}
	
	const int pub() const
	{
		return this->m_pub;
	}
	
	string description()
	{
		//MARK:C++11
		string _description = "m_pri::" + to_string(m_pri)
								+"\nm_pro::" + to_string(m_pro)
								+"\nm_pub::" + to_string(m_pub);
		return _description;
	}
};

class PubB:public A
{
public:
	PubB(int pri = 0,int pro = 0,int pub = 0):A(pri,pro,pub)
	{
		cout<<"init PubB"<<endl;	
	}
};

class PubC:public A
{
public:
	PubC(int pri = 0,int pro = 0,int pub = 0):A(pri,pro,pub)
	{
		cout<<"init PubC"<<endl;	
	}
};

class PubD:public A
{
public:
	PubD(int pri = 0,int pro = 0,int pub = 0):A(pri,pro,pub)
	{
		cout<<"init PubD"<<endl;	
	}
};

int main(int argc,char** argv)
{
	PubB pb(1,2,3);
	cout<<pb.description()<<endl;
	
	PubC pc(4,5,6);
	cout<<pc.description()<<endl;
	
	PubD pd(7,8,9);
	cout<<pd.description()<<endl;
	return 0;
}