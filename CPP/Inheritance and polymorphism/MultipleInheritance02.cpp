#include<iostream>
using namespace std;

class Staff
{	
public:
	Staff(string& name)
	{
		this->m_name = name+"(Staff)";
	}
	string m_name;
};

class Leader
{
public:
	Leader(const string& name)
	{
		this->m_name = name+"(Leader)";
	}
	string m_name;
};

class HRLeader:public Leader,public Staff
{
public:
	HRLeader(string& name):Leader(name),Staff(name)
	{
		
	}
};

int main(int argc,char** argv)
{
	string name = "某某";
	HRLeader l1(name);
	//error
	// l1.m_name;
	cout<<l1.Leader::m_name<<endl;
	cout<<l1.Staff::m_name<<endl;
	return 0;
}