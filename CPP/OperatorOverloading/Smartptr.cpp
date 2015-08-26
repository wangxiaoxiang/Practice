#include<iostream>

using namespace std;

template<class T>

class Smartptr
{
public:
	explicit Smartptr(T* p = NULL)
	{
		this->m_p = p;
	}
	
	Smartptr(Smartptr<T>& that)
	{
		m_p = that.release();
	}
	
	~Smartptr(void)
	{
		if(m_p)
		{
			delete m_p;
		}
	}

	Smartptr& operator = (Smartptr<T>& that)
	{
		if(&that != this)
		{
			reset (that.release ()); // 永远只有一个智能指针持有对象的地址
		}
		return *this;
	}

	T& operator * (void) const
	{
		return *m_p;
	}
	
	T* operator -> (void) const
	{
		return m_p;
	}

private:
	T* release(void)
	{
		T* p = m_p;
		m_p = NULL;
		return p;
	}

	void reset(T* p)
	{
		if (p != m_p)
		{
			delete m_p;
			m_p = p;
		}
	}

private:
	T* m_p;
};

//// ////////////////////////////////////////
//自动数组指针
template<class T>
class Smartptr<T[]> {
public:
    explicit Smartptr (T* p = NULL) {
        m_p = p;
    }
    
    Smartptr (Smartptr<T>& that) {
        m_p = that.release ();
    }
    
    ~Smartptr (void) {
        if (m_p)
            delete[] m_p;
    }
    
    Smartptr& operator= (Smartptr<T>& that) {
        if (&that != this)
            reset (that.release ());
        return *this;
    }
    
    T& operator[] (size_t i) const {
        return m_p[i];
    }
    
private:
    T* release (void) {
        T* p = m_p;
        m_p = NULL;
        return p;
    }
    
    void reset (T* p) {
        if (p != m_p) {
            delete[] m_p;
            m_p = p;
        }
    }
    
private:
    T* m_p;
};

//////////////////////////////////////////////////////
//User
class User {
public:
    User (const string& strName = "wxx", int nAge = 25) {
        cout << "User::User() invoked" << endl;
        m_strName = strName;
        m_nAge = nAge;
    }
    
    ~User (void) {
        cout << "User::~User() invoked" << endl;
    }
    
    void print (void) {
        cout << m_strName << ", " << m_nAge << endl;
    }
    
    friend ostream& operator<< (ostream& os, User& user) {
        return os << user.m_strName << ", " << user.m_nAge;
    }
    
private:
    string m_strName;
    int m_nAge;
};

int main(int argc,char** argv)
{
	cout<<"----------[User]---------"<<endl;
	User* pUser = new User ("Xiaoxiang", 25);
	Smartptr<User> ptr(pUser);
    ptr->print();

    cout<<"----------[string]---------"<<endl;
    string* pStr = new string("wxx");
    Smartptr<string> strPtr(pStr);
    cout<<*strPtr<<endl;
	
	cout<<"----------[Smartptr<User[]>]---------"<<endl;
	Smartptr<User[]> spa (new User[5]);
    for (size_t i = 0; i < 5; i++)
        cout << spa[i] << endl;
    
	return 0;
}
