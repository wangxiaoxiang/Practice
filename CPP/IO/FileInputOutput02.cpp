#include<iostream>
#include<fstream>
#include<errno.h>
#include<string.h>

using namespace std;

void printError(const char* fileName,const int numberOfLine,const string& errorMessage)
{
	cerr<<"Error file:"<<fileName<<",Line:"<<numberOfLine<<",message:"<<errorMessage<<endl;
	exit(-1);
}

int main(int argc,char** argv)
{
	fstream fs("file.txt",ios::in|ios::out);
	if (!fs)
	{
		printError(__FILE__,__LINE__,"Open file error!");
	}

	fs<<1990<<" "<<8.20<<" "<<"wangxiaoxiang.github.com"<<endl;

	cout<<fs.tellg()<<endl;
	cout<<fs.tellp()<<endl;

	fs.seekg(ios::beg);

	cout<<fs.tellg()<<endl;
	cout<<fs.tellp()<<endl;
	
	int n;
	double f;
	string str;

	fs>>n>>f>>str;
	cout<<"n:"<<n<<",f:"<<f<<",str:"<<str<<endl;


	return 0;
}
