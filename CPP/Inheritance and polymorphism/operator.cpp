#include<iostream>
#include<cstdio>
using namespace std;

class Car
{
private:
	string m_model;
	int m_wheel;
public:
	Car(const string& model,int wheel):m_model(model),m_wheel(wheel)
	{
		
	}
	~Car()
	{
		
	}
	friend ostream& operator<<(ostream& os,const Car& car)
	{
		printf("Car::ostream& operator<<(ostream&,const Car&)\n");
		os<<car.m_model<<","<<car.m_wheel;
		return os;
	}
};

class Truck:Car
{
private:
	//t
	double m_maxCargoWeight;
public:
	Truck(const string& model,int wheel,double maxCargoWeight):Car(model,wheel),m_maxCargoWeight(maxCargoWeight)
	{
		
	}
	~Truck()
	{
		
	}
	friend ostream& operator<<(ostream& os,const Truck& truck)
	{
		printf("Truck::ostream& operator<<(ostream&,const Car&)\n");
		os<<(Car&)truck<<","<<truck.m_maxCargoWeight; //OK
		// os<<(Car)truck<<","<<truck.m_maxCargoWeight; //OK
		return os;
	}
};

int main(int argc,char** argv)
{
	Truck volvo("Volvo",10,50);
	cout<<volvo<<endl;
	/*result
	Truck::ostream& operator<<(ostream&,const Car&)
	Car::ostream& operator<<(ostream&,const Car&)
	Volvo,10,50
	*/
	return 0;
}
