//  Copyright (c) 2015年 汪潇翔. All rights reserved.
//

#include<iostream>
#include<typeinfo>
#include<sstream>

using namespace std;

template <typename T,int Size>

class Stack
{
private:
    T _items[Size];
    size_t _count;
public:
    Stack(){};
    T pop() throw(const char*);
    void push(T item) throw(const char*);
    size_t count() const;
    string description() const;
};

template <typename T,int Size>
T Stack<T,Size>::pop() throw(const char*)
{
    if(_count == 0) throw "已经到底了!";
    size_t index = _count-1;
    T item  = _items[index];
    _items[index] = 0;
    _count--;
    return item;
}

template <typename T,int Size>
void Stack<T,Size>::push(T item) throw(const char*)
{
    if(_count == Size) throw "已经到顶了!";
    _items[_count++] = item;
}

template <typename T,int Size>
size_t Stack<T,Size>::count() const
{
    return this->_count;
}

template <typename T,int Size>
string Stack<T,Size>::description() const
{
    ostringstream os;  // could also use in("1 2")
    os<<typeid(this).name()<<"[count:"<<this->count()<<"]\t";
    for (size_t i = 0; i < Size; i++) {
        T item = _items[i];
        os<<item<<", ";
    }

    string _description = os.str();
    return _description;
}


int main(int argc, char const *argv[]) {
    Stack<int,10> stackInt;
    stackInt.push(1);
    stackInt.push(2);
    stackInt.push(3);
    stackInt.push(4);
    stackInt.push(5);
    stackInt.push(6);
    stackInt.push(7);
    stackInt.push(8);
    stackInt.push(9);
    stackInt.push(10);
    cout<<stackInt.description()<<endl;
    // PK5StackIiLi10EE[count:10]	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
    stackInt.pop();
    cout<<stackInt.description()<<endl;
    // PK5StackIiLi10EE[count:9]	1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    return 0;
}
