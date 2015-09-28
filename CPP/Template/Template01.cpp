#include<iostream>
#include<typeinfo>

using namespace std;


template <typename T>

class List
{
private:
  T _item;
public:
  List(T item):_item(item){};
  const char* type_name() const
  {
    return typeid(this->_item).name();
  }
};

int main(int argc, char const *argv[]) {
  List<int> list1(100);
  cout<<list1.type_name()<<endl;


  List<string> list2("汪潇翔");
  cout<<list2.type_name()<<endl;


  List<float> list_f(100.0f);
  cout<<list_f.type_name()<<endl;
  return 0;
}
