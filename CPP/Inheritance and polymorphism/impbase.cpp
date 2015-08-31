#include<iostream>

using namespace std;

class Human
{
private:
	string m_name;
	int m_age;
public:
	Human()
	{
		this->m_name = "GoTT";
		this->m_age = 25;
		cout<<"Human() invoked"<<endl;
	}
	
	Human(string name,int age):m_name(name),m_age(age)
	{
		cout<<"Human(string,int) invoked"<<endl;
	}
	
	friend ostream& operator<<(ostream& os,Human& human)
	{
		return os<<"("<<human.m_name<<","<<human.m_age;
	}
};

class Staff:public Human
{
private:
	string m_no;
public:
	Staff()
	{
		this->m_no = "NO.1";
	}
};

int main(int argc,char** argv)
{
	Human GoTT;
	cout<<GoTT<<endl;
	
	Staff SGoTT;
	cout<<SGoTT<<endl;
	return 0;
}