#include<iostream>
using namespace std;


class Animal
{
		
};

class Tiger
{
public:
	Tiger()
	{
		cout<<"new tiger"<<endl;
	}
	~Tiger()
	{
		cout<<"delete tiger"<<endl;
	}
	void say() const
	{
		
	};
};

class Lion
{
public:
	Lion()
	{
		cout<<"new lion"<<endl;
	}
	~Lion()
	{
		cout<<"delete lion"<<endl;
	}
	void say() const
	{
		
	};
};

class LionTiger:public Tiger,public Lion
{
	
};

int main(int argc,char** argv)
{
	LionTiger lionTiger;
	/*
	new tiger
	new lion
	delete lion
	delete tiger
	*/
	
	return 0;
}