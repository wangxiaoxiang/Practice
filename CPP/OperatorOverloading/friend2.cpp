#include<iostream>
#include<string>
using namespace std;

class Message;

class Sender
{
	int count;
public:
	Sender():count(0){};

	void send(Message& message);

	const Sender& operator << (const string& content);
};


class Message
{
	string title;
	string content;
public:
	Message(const string& title,const string& content):title(title),content(content){};
	const string& getTitle() const
	{
		return this->title;
	}
	const string& getContent() const
	{
		return this->content;
	}
	/*重载std::cin和std::cout。*/
    friend istream& operator >> (istream& is, Message& message);
	friend ostream& operator << (ostream& os, Message& message);
	friend Sender& operator << (Sender& sender,Message& message);
};

void Sender::send(Message& message)
{

		this->count++;
		cout<<"第"<<count<<"条消息"<<endl;
		cout<<"Sending message..."<<endl;
		cout<<message;
		//sleep(3);
		cout<<"Sent finish     [OK]"<<endl<<endl<<endl;
}

const Sender& Sender::operator << (const string& content)
{
	this->count++;
	cout<<"校验消息("<<content<<")"<<endl;
	cout<<"第"<<count<<"条消息"<<endl;
	cout<<"----------Message----------"<<endl;
	cout<<"Sending message..."<<endl;
	cout<<"T:"<<""<<endl;
	cout<<"C:"<<content<<endl<<endl;
	cout<<"Sent finish     [OK]"<<endl<<endl<<endl;
	return *this;
}


Sender& operator << (Sender& sender, Message& message)
{
	cout<<"校验消息("<<message.content<<")"<<endl;
	sender.send(message);
	return sender;
}



istream& operator >> (istream& is, Message& message)
{
	cout<<"Title:";
	is>>message.title;
	
	cout<<endl;
	
	cout<<"Content:";
	is>>message.content;
	return is;
}

ostream& operator << (ostream& os, Message& message)
{
	os<<"----------Message----------"<<endl;
	os<<"T:"<<message.title<<endl;
	os<<"C:"<<message.content<<endl;
	return os;
}

int main(int argv,char** argc)
{

	Sender sender;
	Message m1("haha","ni ma?");
	sender<<m1<<"呵呵";
	return 0;
}
