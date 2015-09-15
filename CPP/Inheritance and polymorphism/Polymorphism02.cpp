#include<iostream>
#include<string>

using namespace std;

class Animal
{
public:
  virtual void howl() const
  {
    cout<<"Animal howl……"<<endl;
  }
};

class Wofl:public Animal
{
public:
  virtual void howl() const
  {
    cout<<"Wofl howl(wow wow),吓死宝宝了。"<<endl;
  }
};

class Cat:public Animal
{
public:
  virtual void howl() const
  {
    cout<<"Cat howl(miao miao)"<<endl;
  }
};

void AnimalHowl(const Animal& animal)
{
  animal.howl();
}

int main(int argv,char** argc)
{
  Wofl wofl;
  Cat cat;


  AnimalHowl(wofl);
  //output Wofl howl(howl howl),吓死宝宝了。

  AnimalHowl(cat);
  //output Cat howl(miao miao)
  return 0;
}
