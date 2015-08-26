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
	operator Point3D (void);
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
	Point3D(const Point2D& point):m_x(point.getX()),m_y(point.getY()),m_z(0.0f)
	{
		cout<<"通过构造函数Point3D(const Point2D& point)转型。"<<endl;
	};
	
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
	cout<<"Point2D::operator Point3D(void)被调用。\n";
	return Point3D(this->getX(),this->getY());
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

int main(int argc, char** argv)
{
	Point2D p1(100.0f,100.0f);
	Point3D p2(10.0f,10.0f,10.0f);
	cout<<"p1\t|"<<p1<<endl;
	cout<<"p2\t|"<<p2<<endl;
	//类型转换
	Point3D p1_3d = p1;
	cout<<"p1_3d\t|"<<p1_3d<<endl;
	//如果Point3D实现了`Point3D(const Point2D& point)的构造函数`，
	//使用static_cast转换类型时将会调用构造函数转型，否则调用`Point2D::operator Point3D(void)方法`。
	Point3D p1_2_3d = static_cast<Point3D> (p1);
	cout<<"p1_2_3d\t|"<<p1_2_3d<<endl;
	//使用构造函数转换类型
	Point3D p3(p1);
	cout<<"p3\t|"<<p3<<endl;
	return 0;
}
