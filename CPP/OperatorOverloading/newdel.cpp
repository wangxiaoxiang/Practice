//g++ -std=c++11 newdel.cpp
#include <iostream>
using namespace std;

void* operator new(size_t size)
{
    cout<<"new("<<size<<") invoked"<<endl;
    
    return malloc(size);
}

void* operator new[](size_t size)
{
    cout<<"new[]("<<size<<") invoked"<<endl;
    
    return malloc(size);
}
//在C++11中如果noexcept修饰的函数抛出了异常，编译器可以选择直接调用std::terminate()函数来终止程序的运行。
void operator delete (void* p) noexcept
{
    cout << "delete(" << p << ") invoked" << endl;
    
    free(p);
}

void operator delete[] (void* p) noexcept
{
    cout << "delete[](" << p << ") invoked" << endl;
    free (p);
}

class A
{
    double a,b,c;
public:
    A()
    {
        cout<<"A() invoked"<<endl;
    }
    ~A()
    {
        cout<<"~A() invoked"<<endl;
    }
};

class B
{
    int a,b,c;
public:
    B()
    {
        cout<<"B() invoked"<<endl;
    }
    B(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        cout<<"B(int, int, int) invoked"<<endl;
    }
    ~B()
    {
        cout<<"~B() invoked"<<endl;
    }
    
    static void* operator new(size_t size)
    {
        cout << "B::new(" << size << ") invoked" << endl;
        return malloc (size);
    }
    static void operator delete(void* p)
    {
        cout << "B::delete(" << p << ") invoked" << endl;
        free (p);
    }
};


int main(int argc,char** argv)
{
    int *n = new int;
    delete n;
    
    cout<<"---------------------------------------------"<<endl;
    A* a = new A();
    delete a;
    A* aa = new A[5]();
    delete [] aa;
    
    cout<<"---------------------------------------------"<<endl;
    B* b = new B();
    delete b;
    
    B* ba = new B[10]();
    delete [] ba;
    
    return 0;
}
