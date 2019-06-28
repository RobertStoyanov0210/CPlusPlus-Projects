#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#define PI 3.14
using namespace std;

class Point
{
protected: double x, y, z;

public:
	Point() {};
	Point(double x, double y, double z) : x(x), y(y), z(z) {};
	Point(double x, double y) {};
	Point(const Point& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; };
	~Point() {};
	virtual ostream& ins(ostream & out) const;

	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setZ(int z) { this->z = z; }

	friend bool operator==(const Point&, const Point&);
	Point& operator=(const Point &);
};

ostream& operator << (ostream &, const Point &);
Point operator-(const Point &, const Point &);

class VectorLenghtException : public exception {
	string _msg;
public:
	VectorLenghtException(const char* msg) :exception(msg) {}
};

class Vector :public Point {
	//int i = 0, j = 0, k = 0;
public:
	Vector(double x = 0, double y = 0, double z = 0) :Point() { this->x = x; this->y = y; this->z = z; }
	Vector(Point & begin, Point & end) :Point() {
		setX(end.getX() - begin.getX());
		setY(end.getY() - begin.getY());
		setZ(end.getZ() - begin.getZ());
	}

	virtual ostream& ins(ostream &) const;

	double lengthOfV();
	Vector dirOfV();
	bool nullV();
	static bool perpendicularity(Vector&, Vector&);
	static bool parallel(Vector &, Vector &);
	double operator()(Vector &, Vector&);


	friend Vector operator+ (const Vector &, const Vector &);
	friend Vector operator- (const Vector &, const Vector &);
	friend Vector operator* (const Vector &, double);
	friend double operator* (const Vector&, const Vector&);
	Vector operator^ (const Vector &);
	Vector& operator= (const Vector &);
};


class Triangle :public Point {
	string typeOfT;
	Point a, b, c;
	double sideA = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getY() - c.getY(), 2) + pow(b.getZ() - c.getZ(), 2)),
		sideB = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2) + pow(a.getZ() - c.getZ(), 2)),
		sideC = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2) + pow(a.getZ() - b.getZ(), 2));

	double alpha = round(acos((pow(sideB,2) +pow(sideC,2)  - pow(sideA,2)) / (2 * sideB * sideC))*(180 / PI)),
		beta = round(acos((pow(sideA,2) + pow(sideC, 2) - pow(sideB, 2)) / (2 * sideA * sideC)) * (180 / PI)),
		gamma = round(180 - alpha - beta);
public:
	Triangle(Point a, Point b, Point c) :a(a), b(b), c(c) {	};
	Triangle(const Triangle& t) {};
	~Triangle() {};

	Point getA() const { return a; }
	Point getB() const { return b; }
	Point getC() const { return c; }


	friend ostream& operator << (ostream &, Triangle &);
	string typeOfTriangle();
	double semiperimeter(double);
	double perimeter();
	double area(double);
	static Point Centroid(const Triangle&);
};
#endif
