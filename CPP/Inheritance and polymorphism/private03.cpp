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

//私有继承使Operater中的公有成员在StaffHR中变成私有。
class StaffHR:protected Operater
{
public:
	virtual void dispatch_staff_to(string& department) const
	{
		cout<<"\nStaffHR:准备调度。"<<endl;
		string description = "调度xxx到"+department+"部门";
		dispatch(description);
		cout<<"StaffHR:调度完成。\n"<<endl;
	}
};

class StaffHRLeader:public StaffHR
{
public:
	virtual void dispatch_staff_to(string& department) const
	{
		cout<<"\nStaffHRLeader:准备调度。"<<endl;
		string description = "调度xxx到"+department+"部门，升职加薪。迎娶白富美，走上人生巅峰。";
		dispatch(description);
		cout<<"StaffHRLeader:调度完成。\n"<<endl;
	}
};


int main(int argc,char** argv)
{
	StaffHR* hr_bj_leader = new StaffHRLeader();
	string department_it = "IT";
	hr_bj_leader->dispatch_staff_to(department_it);
	delete hr_bj_leader;
	
	StaffHR* hr_bj = new StaffHR();
	string department_sc = "市场";
	hr_bj->dispatch_staff_to(department_sc);
	delete hr_bj;
	return 0;
}