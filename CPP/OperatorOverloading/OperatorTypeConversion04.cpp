//g++ -std=c++11 OperatorTypeConversion04.cpp
#include<iostream>
using namespace std;


class Point3D;

//////////////////////////////////////////////////////////////////////////////
//Point2D interface
class Point2D
{
private:
	double m_x;
	double m_y;
public:
	Point2D(double x = 0,double y = 0):m_x(x),m_y(y){};
	void setX(double& x);
	const double& getX() const;
	void setY(double& y);
	const double& getY() const;
	
	friend istream& operator >> (istream& is, Point2D& point);
	friend ostream& operator << (ostream& os, const Point2D& point);

	explicit operator Point3D(void);
};

//////////////////////////////////////////////////////////////////////////////
//Point3D interface
class Point3D
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Point3D(double x = 0, double y = 0, double z = 0):m_x(x),m_y(y),m_z(z){};
	
	void setX(double& x);
	const double& getX() const;
	void setY(double& y);
	const double& getY() const;
	void setZ(double& z);
	const double& getZ() const;

	
	friend ostream& operator << (ostream& os, const Point3D& point);
};

//////////////////////////////////////////////////////////////////////////////
//Point2D implemention

Point2D::operator Point3D(void)
{
	return Point3D(this->getX(),this->getY(),0.0f);
}

istream& operator >> (istream& is, Point2D& point)
{
	double x,y;

	cout<<"x:";is>>x;

	cout<<"\n";
	
	cout<<"y:";is>>y;

	cout<<"\n";
	
	point.setX(x);
	point.setY(y);

	return is; 
}

ostream& operator << (ostream& os, const Point2D& point)
{
	os<<"Point2D->"<<"(x:"<<point.getX()<<",y:"<<point.getY()<<")";
	return os;
}

void Point2D::setX(double& x)
{
	this->m_x = x;
}

const double& Point2D::getX() const
{
	return this->m_x;
}

void Point2D::setY(double& y)
{
	this->m_y = y;
}

const double& Point2D::getY() const
{
	return this->m_y;
}

//////////////////////////////////////////////////////////////////////////////
//Point3D implemention

void Point3D::setX(double& x)
{
	this->m_x = x;
}

const double& Point3D::getX() const
{
	return this->m_x;
}

void Point3D::setY(double& y)
{
	this->m_y = y;
}

const double& Point3D::getY() const
{
	return this->m_y;
}

void Point3D::setZ(double& z)
{
	this->m_z = z;
}

const double& Point3D::getZ() const
{
	return this->m_z;
}

ostream& operator << (ostream& os, const Point3D& point)
{
	os<<"Point3D->"<<"(x:"<<point.getX()<<",y:"<<point.getY()<<",z:"<<point.getZ()<<")";
	return os;
}


//////////////////////////////////////////////////////////////////////////////
//Tools function

void printPoint3D(const Point3D& point)
{
	cout<<point<<endl;
}


int main(int argc, char** argv)
{
	Point2D p1(100.0f,100.0f);
	
	//类型转换
//#error 如果你没有重载`operator Point3D(void)`,会自动调用构造方法转型。但是构造转型用explicit修饰,无法隐式转换类型。
	printPoint3D(p1);
	printPoint3D(static_cast<Point3D> (p1));
	return 0;
}
