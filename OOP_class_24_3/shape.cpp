//THis programm requires -std=c++11 to run perfectly.
#include <iostream>
#include <cmath>

using namespace std;

class Center
{
private:
	int x;
	int y;
public:
	Center(){}
	Center(int x, int y){
		this->x = x;
		this->y = y;
	}
	Center(const Center& a_cen)
	{
		this->x = a_cen.x;
		this->y = a_cen.y;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	double computeDis(const Center& rhs)
	{
		//cout << this->x - rhs.x << endl << this->y - rhs.y <<endl;
		//cout <<	sqrt((this->x - rhs.x)*(this->x - rhs.x) + (this->y - rhs.y)*(this->y - rhs.y));
		return sqrt((this->x - rhs.x)*(this->x - rhs.x) + (this->y - rhs.y)*(this->y - rhs.y));
	}

};
class Shape
{
protected:
	Center mycen;
public:
	Shape(){}
	Shape( int x, int y)
	{
		Center cen(x, y);
		mycen = cen;
	}
	double computeDIS(const Shape* anotherShape)
	{
		return this->mycen.computeDis(anotherShape->mycen);
	}
	/*void update(int x, int y)
	{
		Center cen(x, y);
		mycen = cen;
	}*/
	virtual double computeArea() = 0;
	virtual double computeCir() = 0;
	virtual ~Shape(){};
};

class Circle : public Shape
{
private:
	int radius;
public:
	Circle(){}
	Circle(int radius, int x, int y):Shape(x,y){
		this->radius = radius;
		//update(x,y);

	}
	double computeArea()
	{
		return this->radius*this->radius*3.14;
	}
	double computeCir()
	{
		return this->radius*2.0*3.14;
	}
};


class Square : public Shape
{
private:
	int side;
public:
	Square(){}
	Square(int side, int x, int y):Shape(x,y){
		this->side = side;
	}
	double computeArea()
	{
		return this->side*this->side;
	}
	double computeCir()
	{
		return 4.0*this->side;
	}
};
class Rectangular : public Shape
{
private:
	int h;
	int w;
public:
	Rectangular(){}
	Rectangular(int h,int w, int x, int y):Shape(x,y){
		this->h = h;
		this->w = w;
	}

	double computeArea()
	{
		return this->h*this->w;
	}
	double computeCir()
	{
		return (this->h+this->w)*2.0;
	}
};

int main()
{
	Shape* o = new Rectangular(3,2,1,1);
	Shape* b = new Circle(3,2,1);
	cout << o->computeArea() << endl;
	cout << o->computeCir() << endl;
	cout << b->computeArea() << endl;
	cout << b->computeCir()<< endl;
	cout <<o->computeDIS(b);
	delete o;
	delete b;


}