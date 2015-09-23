//Copyright (c) 2015 汪潇翔 All Rights Reserved.

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char const *argv[]) {
  istringstream s("Hello world");
  char a = s.peek();
  char b = s.get();
  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
  cout<<"s="<<s.rdbuf()<<endl;
  return 0;
}
