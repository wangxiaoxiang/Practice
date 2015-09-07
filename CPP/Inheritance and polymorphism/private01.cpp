#include<iostream>

using namespace std;

class Operater
{
public:
	void dispatch(string& description) const
	{
		cout<<description<<endl;
		cout<<"调度中……"<<endl;
	}
};

class StaffHR:public Operater
{
public:
	void dispatch_staff_to(string& department) const
	{
		cout<<"准备调度。"<<endl;
		string description = "调度xxx到"+department+"部门";
		dispatch(description);
		cout<<"调度完成。"<<endl;
	}
};


int main(int argc,char** argv)
{
	StaffHR* hr_bj = new StaffHR();
	string department = "IT";
	hr_bj->dispatch_staff_to(department);
	
	cout<<"---------------------------------"<<endl;
	hr_bj->dispatch(department);
	delete hr_bj;
	return 0;
}