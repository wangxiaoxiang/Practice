#include<iostream>
#include<string>

using namespace std;

class Animal
{
public:
  void howl() const
  {
    cout<<"Animal howl……"<<endl;
  }
};

class Wofl:public Animal
{
public:
  void howl() const
  {
    cout<<"Wofl howl(wow wow),吓死宝宝了。"<<endl;
  }
};

class Cat:public Animal
{
public:
  void howl() const
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
  //output Animal howl……

  AnimalHowl(cat);
  //output Animal howl……
  return 0;
}
