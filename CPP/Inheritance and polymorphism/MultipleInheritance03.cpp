#include<iostream>
using namespace std;


class Animal
{
public:
	void say() const
	{
		cout<<"say:"<<zoo_no<<endl;
	}
	string zoo_no;
	const string& no() const
	{
		return this->zoo_no;
	}	
};

class Dog:virtual public Animal
{
public:
	Dog(string zoo_no)
	{
		this->zoo_no = zoo_no;
		cout<<"new dog"<<endl;
	}
	~Dog()
	{
		cout<<"delete dog"<<endl;
	}
	
};

class Lion:virtual public Animal
{
public:
	Lion(string zoo_no)
	{
		this->zoo_no = zoo_no;
		cout<<"new lion"<<endl;
	}
	~Lion()
	{
		cout<<"delete lion"<<endl;
	}
};

class LionDog:public Dog,public Lion
{
public:
	LionDog(string zoo_no):Dog(zoo_no),Lion(zoo_no)
	{
		
	}
};

int main(int argc,char** argv)
{
	LionDog lionDog("no.f007228");
	cout<<lionDog.zoo_no<<endl;
	return 0;
}