#include<iostream>

using namespace std;

class Human
{
public:
	Human()
	{
		cout<<"Human() invoked"<<endl;
	}
	~Human()
	{
		cout<<"~Human() invoked"<<endl;
	}
};

class Staff:public Human
{
public:
	Staff()
	{
		cout<<"Staff() invoked"<<endl;
	}
	~Staff()
	{
		cout<<"~Staff() invoked"<<endl;
	}
};

class SoftwareEngineer:public Staff
{
public:
	SoftwareEngineer()
	{
		cout<<"SoftwareEngineer() invoked"<<endl;
	}
	~SoftwareEngineer()
	{
		cout<<"~SoftwareEngineer() invoked"<<endl;
	}
};

int main(int argc,char** argv)
{
	SoftwareEngineer* GoTT = new SoftwareEngineer();
	delete GoTT;
	return 0;
}