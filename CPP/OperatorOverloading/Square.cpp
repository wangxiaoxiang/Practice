#include<iostream>

using namespace std;

class Square
{
public:
	//函数运算符
	int operator() (int n) const
	{
		cout<<"Square::(int) invoked"<<endl;
		return n*n;
	}

	double operator() (double n) const
	{
		cout<<"Square::(double) invoked"<<endl;
		return n*n;
	}
};

int main(int argc, char** argv)
{

	Square square;
	cout<<square(100)<<endl;
	cout<<square(100.0f)<<endl;

	return 0;
}
