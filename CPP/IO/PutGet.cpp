#include<iostream>
#include<fstream>
#include<errno.h>
#include<string.h>

using namespace std;

void PrintError(const char* fileName,const int numberOfLine,const string& errorMessage)
{
	cerr<<"[Error]-file:"<<fileName<<",Line:"<<numberOfLine<<",message:"<<errorMessage<<endl;
	exit(-1);
}

int main(int argc,char** argv)
{
	//out put
	ofstream ofs("put_get.txt",ios::in|ios::out);
	
	if (!ofs)
	{
		PrintError(__FILE__,__LINE__,"Open file error!");
	}
	
	for (char c=' '; c <= '~'; c++)
	{
		if (!ofs.put(c))
		{
			PrintError(__FILE__,__LINE__,"Cannot write file!!!");
		}
	}

	ofs.put('\n');
	ofs.close();
	
	//get
	ifstream ifs("put_get.txt");
	if(!ifs)
	{
		PrintError(__FILE__,__LINE__,"Cannot open file!");
	}
	char c;

	while((c = ifs.get()) != EOF)
	{
		cout<<c;
	}
	cout<<endl;

	if(!ifs.eof())
	{
		PrintError(__FILE__,__LINE__,"Cannot read file!");
	}
	
	//get2
	ifs.clear();
	ifs.seekg(0,ios::beg);
	while(ifs.get(c))
	{
		cout<<c;
	}
	cout<<endl;
	if(!ifs.eof())
	{
		PrintError(__FILE__,__LINE__,"Cannot input file!");
	}
	
	//get3
	ifs.clear();
	ifs.seekg(0,ios::beg);
	char sz[4];
	while(ifs.get(sz,sizeof(sz),'\n'))
	{
		cout<<sz;
		if(ifs.peek() == '\n')
		{
			ifs.ignore();
		}
	}
	cout<<endl;
	if(!ifs.eof())
	{
		PrintError(__FILE__,__LINE__,"Cannot input file!");
	}

	//getline();
	ifs.clear();
	ifs.seekg(0,ios::beg);
	char szLarge[128];
	while(ifs.getline(szLarge,sizeof(szLarge),'\n'))
	{
		cout<<szLarge<<endl;
	}
	cout<<endl;

	if(!ifs.eof())
	{
		PrintError(__FILE__,__LINE__,"Cannot read file!");
	}
	ifs.close();

	return 0;
}
