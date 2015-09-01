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
	Human(const Human& human)
	{
		this->m_name = *(human.name());
		this->m_age = *(human.age());
		
	}
	Human& operator=(const Human& human)
	{
		if(this != &human){
			this->m_name = *(human.name());
			this->m_age = *(human.age());
		}
		return *this;
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
	Staff(const Staff& staff):Human(staff)
	{
		cout<<"Staff::Staff(const Staff&)"<<endl;
		string* _no = new string();
		*_no = *(staff.no());
		this->m_no = _no;
	}
	Staff& operator=(const Staff& staff)
	{
		cout<<"Staff::operator=(const Staff&)"<<endl;
		if(this != &staff)
		{
			Human::operator=(staff);
			string* _no = new string();
			*_no = *(staff.no());
			this->m_no = _no;
		}
		return *this;
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

string to_string(const Staff& staff)
{
	return staff.description();
}

int main(int argc,char** argv)
{
	Staff GoTT("GoTT",25,"NO.1");
	
	Staff GoTT2 = GoTT;
	cout<<to_string(GoTT)<<endl;
	cout<<"&GoTT\t"<<&GoTT<<endl;
	cout<<"&GoTT2\t"<<&GoTT2<<endl;
	cout<<"&GoTT.no\t"<<GoTT.no()<<endl;
	cout<<"&GoTT2.no\t"<<GoTT2.no()<<endl;
	cout<<"&GoTT.name\t"<<GoTT.name()<<endl;
	cout<<"&GoTT2.name\t"<<GoTT2.name()<<endl;
	
	return 0;
}