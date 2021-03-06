#include<iostream>
#include<string>

using namespace std;

class Human
{
private:
	string* m_name;
	int* m_age;
public:
	Human(const string* name,const int* age)
	{
		string* _name = new string();
		*_name = *name;
		this->m_name = _name;

		int*  _age = new int;
		*_age = *age;
		this->m_age = _age;
		cout<<"Human() invoked"<<endl;
	}
	~Human()
	{
		delete m_name;
		delete m_age;
		cout<<"~Human() invoked"<<endl;
	}
	const string* name() const
	{
		return this->m_name;
	}
	const string description() const
	{
		string _description = "name::"+*(this->m_name)
								+"\nage::"+to_string(*(this->m_age));
		return _description;
	}
};

class Staff:public Human
{
public:
	Staff(const string* name,const int* age):Human(name,age)
	{
		cout<<"Staff() invoked"<<endl;
	}
	const string description() const
	{
		string _description = Human::description();
		return _description;
	}
};

int main(int argc,char** argv)
{
	string name = "GoTT";
	string no = "NO.1";
	int age = 25;
	Staff* GoTT = new Staff(&name,&age);
	cout<<GoTT->description()<<endl;
	delete GoTT;
	
	return 0;
}