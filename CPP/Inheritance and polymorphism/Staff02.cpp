#include<iostream>
#include<string>

using namespace std;

class Staff
{
private:
	string m_name;
	int m_age;
	string m_no;
public:
	Staff(string name,int age,string no):m_name(name),m_age(age),m_no(no){};
	~Staff()
	{
	//	cout<<"~Staff()"<<endl;
	}
	//setter getter
	void setName(string& name)
	{
		this->m_name = name;
	}
	const string& name() const
	{
		return this->m_name;
	}

	void setNo(string& no)
	{
		this->m_no = no;
	}

	const string& no() const
	{
		return this->m_no;
	}

	void setAge(int age)
	{
		this->m_age = age;
	}
	const int age() const
	{
		return this->m_age;
	}

	const string discription() const
	{
		string _discription = "Name:"+this->name()
								+"\nAge:"+to_string(this->age())
								+"\nNo:"+this->no();
		return _discription;
	}
	void work() const
	{
		cout<<this->name()<<"正在工作......"<<endl;
	}
};

class SoftwareEngineer:public Staff
{
private:
	string m_computer;
public:
	SoftwareEngineer(string name,int age,string no,string computer):Staff(name,age,no),m_computer(computer)
	{
	//	cout<<"新来了一只猴。"<<endl;
	};
	~SoftwareEngineer()
	{
	//	cout<<"一只码字猴以身死亡。"<<endl;
	}
	void setComputer(string& computer)
	{
		this->m_computer = computer;
	}
	const string& computer() const
	{
		return this->m_computer;
	}

	void work() const
	{
		cout<<this->name()<<"正在用["<<this->computer()<<"]电脑开发应用程序。"<<endl;
	}

	void findObjects() const
	{
		cout<<this->name()<<"正在找对象。"<<endl;
	}
};

class ProductManager:public Staff
{
private:
	/*
	情绪
	-1,心情不好。
	0 ,心情一般。
	1 ,心情很好。
	*/
	int m_mood;
public:
	ProductManager(string name,int age,string no,int mood = 0):Staff(name,age,no),m_mood(mood)
	{
	//	cout<<"前方出现产品经理一只，码字猴们请小心！"<<endl;
	};
	~ProductManager()
	{
	//	cout<<"一只产品经理已经阵亡。"<<endl;
	}

	void setMood(int mood)
	{
		this->m_mood = mood;
	}
	const int mood() const
	{
		return this->m_mood;
	}
	void work() const
	{
		switch(this->mood())
		{
			case -1:
				cout<<this->name()<<"心情不好，正在狂虐码字猴！"<<endl;
				break;
			case 0:
				cout<<this->name()<<"心情一般，不想虐码字猴！"<<endl;
				break;
			case 1:
				cout<<this->name()<<"心情愉悦，正在给码字猴糖吃！"<<endl;
				break;
			default:
				cout<<this->name()<<"心情不定，码字猴都已阵亡！"<<endl;
				break;
		}
	}
	void playingMonkey() const
	{
		cout<<this->name()<<"正在耍猴。"<<endl;
	}
};


int main(int argc, char** argv)
{
	Staff* zh = new Staff("zhang huan",20,"A1");
	SoftwareEngineer wxx("Xiaoxiang wang",25,"B1","Macbook pro 13\"");
	ProductManager ny("Yang",24,"C1",-1);
	

	Staff* staff_B1 = &wxx;
	Staff* staff_C1 = &ny;

	staff_B1->work();
	staff_C1->work();
	
	//不安全的类型转换
	//error:cannot initialize a variable of type 'SoftwareEngineer *' with an lvalue of type 'Staff *'
	//SoftwareEngineer* p_zh = zh;

	//使用静态造型（强制类型转换）虽然可以回避语法上限制，但是并不安全。
	//SoftwareEngineer* p_zh = static_cast<SoftwareEngineer*>(zh);
	//cout<<p_zh->name()<<endl;

}
