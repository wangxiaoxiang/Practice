#include<iostream>
#include<string>
using namespace std;

class Human
{
private:
	string m_name;
	int m_age;
public:
	Human(const string& name,const int& age):m_name(name),m_age(age)
	{
		
	}
	const string description() const
	{
		string _description = "name:"+this->m_name
								+"\nage"+to_string(this->m_age);
		return _description;
	}
	const string* name() const
	{
		return &(this->m_name);
	}
	const int* age() const
	{
		return &(this->m_age);
	}
};

class Staff:public Human
{
private:
	string* m_no;
public:
	Staff(const string& name,const int& age,const string& no):Human(name,age)
	{
		string* _no = new string();
		*_no = no;
		this->m_no = _no;
	}
	~Staff()
	{
		delete m_no;
	}
	const string description() const
	{
		string _description = Human::description();
		_description += ("\nNo:"+*(this->m_no));
		return _description;
	}
	const string* no() const
	{
		return this->m_no;
	}
	friend ostream& operator<<(ostream& os,const Staff& staff)
	{
		os<<staff.description();
		return os;
	}
	
	
	
};

int main(int argc,char** argv)
{
	Staff GoTT("GoTT",25,"NO.1");
	
	
	Staff GoTT2 = GoTT;
	cout<<"&GoTT\t"<<&GoTT<<endl;
	cout<<"&GoTT2\t"<<&GoTT2<<endl;
	cout<<"&GoTT.age\t"<<GoTT.no()<<endl;
	cout<<"&GoTT2.age\t"<<GoTT2.no()<<endl;
#error a.out(29472,0x7fff7b4f1300) malloc: *** error for object 0x7fc270c04c30: pointer being freed was not allocated 
	//多删除了一次Staff中的m_no；
	return 0;
}