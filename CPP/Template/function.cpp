#include<iostream>

using namespace std;

template <typename T>

void TSwap(T& a,T& b)
{
  T c = a;
  a = b;
  b = c;
}

int main(int argc, char const *argv[]) {
  int a=1,b=2;
  TSwap(a,b);
  cout<<"a:"<<a<<'\t'<<"b:"<<b<<endl;

  float x=0.5,y=1.5;
  TSwap(x,y);
  cout<<"x:"<<x<<'\t'<<"y:"<<y<<endl;

  string s1 = "wxx", s2 = "xxw";
  TSwap(s1,s2);
  cout<<"s1:"<<s1<<'\t'<<"s2:"<<s2<<endl;
  return 0;
}
