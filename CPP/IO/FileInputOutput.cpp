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
	ofstream ofs1("test.txt");
	if (!ofs1)
	{
		printError(__FILE__,__LINE__,"Cannot open output file");
	}
	ofs1<<"呵呵"<<" "<<3.1415926<<" "<<"Apple"<<'\n';
	ofs1.close();

	ofstream ofs2("test.txt",ios::app);
	if (!ofs2)
	{
		printError(__FILE__,__LINE__,"Cannot open output file");
	}
	ofs2<<"Append a apple\n";
	ofs2.close();

	ifstream ifs1("test.txt");
	if (!ifs1)
	{
		printError(__FILE__,__LINE__,"Cannot open input file");
	}

	string str1;
	ifs1>>str1;
	cout<<"str1:"<<str1<<endl;

	return 0;
}
