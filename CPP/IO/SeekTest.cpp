#include<iostream>
#include<fstream>
#include<errno.h>
#include<string.h>

using namespace std;

void PrintError(const char* fileName,const int numberOfLine,const string& errorMessage)
{
	cerr<<"Error file:"<<fileName<<",Line:"<<numberOfLine<<",message:"<<errorMessage<<endl;
	exit(-1);
}

int main(int argc,char** argv)
{
	fstream fs("seek.txt",ios::in|ios::out);
	if (!fs)
	{
		PrintError(__FILE__,__LINE__,"Open file error!");
	}

	fs<<1990<<" "<<25.1<<"8.20"<<" "<<"wangxiaoxiang.github.com"<<endl;

	cout<<fs.tellg()<<endl;
	cout<<fs.tellp()<<endl;

	//fs.seekg(ios::beg);
	fs.seekg(0);

	cout<<fs.tellg()<<endl;
	cout<<fs.tellp()<<endl;
	
	int n;
	string str;
	
	fs >> n;

	fs.seekg(12,ios::cur);

	fs >> str;

	cout<<n<<" "<<str<<endl;

	fs.close();


	return 0;
}
