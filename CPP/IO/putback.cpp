#include<iostream>
#include<sstream>

using namespace std;

int main(int argc,char** argv)
{
  stringstream s1("Yellow");
  s1.get();
  if (s1.putback('Y'))
    cout<<s1.rdbuf()<<endl;
  else
    cout<<"putback failed"<<endl;

  istringstream s2("Hello,world!!!");
  s2.get();
  if (s2.putback('Y'))
    cout<<s2.rdbuf()<<endl;
  else
    cout<<"putback failed"<<endl;

  s2.clear();

  if (s2.putback('H'))
    cout<<s2.rdbuf()<<endl;
  else
    cout<<"putback failed"<<endl;
  return 0;
}
