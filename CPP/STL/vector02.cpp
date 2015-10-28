//g++ -std=c++11 vector02.cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
void PrintVector(const vector<string>& vec)
{
	vector<string>::iterator it = vec.begin();
	while(it != vec.end())
	{
		cout<<*it<<endl;
		it++;
	}
}
*/

int main(int argc,char** argv)
{
	vector<string> names(1,"汪潇翔");
	names.push_back("汪潇凯");
	
	vector<string>::iterator it = names.begin();
	while(it != names.end())
	{
		cout<<*it<<endl;
		it++;
	}
	//PrintVector(names);

	return 0;
}
