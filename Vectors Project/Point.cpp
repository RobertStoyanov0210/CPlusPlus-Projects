#include "Point.h"
#include <string>
#include <math.h>
#include <iomanip> 
using namespace std;

// POINT FUNCTIONS
ostream& Point::ins(ostream & out) const {
	return out << "x: " << x << "\ny: " << y << "\nz: " << z << std::endl;
}

bool operator==(const Point & p1, const Point & p2) {
	if (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const Point& p) {
	return p.ins(out);
}

Point operator-(const Point & p1, const Point & p2) {
	return Point(p2.getX() - p1.getX(), p2.getY() - p1.getY(),
		p2.getZ() - p1.getZ());
}

Point& Point::operator=(const Point & r) {
	x = r.x;
	y = r.y;
	z = r.z;
	return *this;
}

// VECTOR FUNCTIONS 
Vector & Vector::operator=(const Vector & v) {
	setX(v.getX());
	setY(v.getY());
	setZ(v.getZ());
	return *this;
}
ostream& Vector::ins(ostream & out) const {
	return out << "x: " << x << "\ny: " << y << "\nz: " << z << std::endl;
}

double Vector::lengthOfV() { return sqrt((x*x) + (y*y) + (z*z)); }

Vector Vector::dirOfV() {
	try
	{
		double x1, y1, z1;
		if (nullV())
			throw VectorLenghtException("Vector is null!\n");
		x1 = x / lengthOfV();
		y1 = y / lengthOfV();
		z1 = z / lengthOfV();
		return Vector(x1, y1, z1);
	}
	catch (VectorLenghtException & v) {
		cout << v.what() << endl;
	}
}

bool Vector::nullV() { if (x == 0 && y == 0 && z == 0)return true;	return false; }

Vector operator+(const Vector & v1, const Vector & v2) {
	return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}
Vector operator-(const Vector & v1, const Vector & v2) {
	return Vector(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

Vector operator*(const Vector & v, double r) {
	return (v.getX() * r, v.getY() *r, v.getZ() *r);
}

double operator*(const Vector & a, const Vector & v) {
	return (a.getX()*v.getX() + a.getY()*v.getY() + a.getZ()*v.getZ());
}
Vector Vector::operator^(const Vector & v) {
	Vector u = *this;
	return Vector(u.getY()*v.getZ() - u.getZ()*v.getY(), u.getZ()*v.getX() - u.getX()*v.getZ(), u.getX()*v.getY() - u.getY()*v.getX());
}

bool Vector::perpendicularity(Vector & a, Vector & v) {
	try
	{
		if (a.nullV() || v.nullV())
			throw VectorLenghtException("Some of the vector is null!\n");

		if (a.getX()*v.getX() + a.getY()*v.getY() + a.getZ()*v.getZ() == 0)
			return true;

		return false;
	}
	catch (VectorLenghtException & v)
	{
		cout << v.what() << endl;
		exit(0);
	}
}

bool Vector::parallel(Vector & v1, Vector & v2) {
	try
	{
		if (v1.nullV() || v2.nullV())
			throw VectorLenghtException("Vector is null!");

		if (v1.getX() / v2.getX() == v1.getY() / v2.getY() & v1.getY() / v2.getY() == v1.getZ() / v2.getZ())
			return true;
		return false;
	}
	catch (VectorLenghtException & v)
	{
		cout << v.what() << endl;
		exit(0);
	}
}

double Vector::operator()(Vector & u, Vector & v) {
	return this->x*(u.getY()*v.getZ() - v.getY()*u.getZ())
		+ this->y*(u.getX()*v.getZ() - v.getX()*u.getZ())
		+ this->z*(u.getX()*v.getY() - v.getX()*u.getY());
}

// TRIANGLE FUNCTIONS
string Triangle::typeOfTriangle() {
	string typeOfTriangle;
	{
		if (alpha == 90 || beta == 90 || gamma == 90)
			typeOfTriangle = "Right";
		else if (alpha < 90 && beta < 90 && gamma < 90)
			typeOfTriangle = "Acute";
		else if (alpha > 90 || beta > 90 || gamma > 90)
			typeOfTriangle = "Obtuse";
		else
			typeOfTriangle = "";

	}
	if (sideA == sideB && sideA == sideC)
		typeOfTriangle += " Equilateral triangle";

	else if (sideA == sideB || sideA == sideC || sideB == sideC)
		typeOfTriangle += " Isosceles triangle";

	else
		typeOfTriangle += " Scalene triangle";

	return typeOfTriangle;

}

double Triangle::semiperimeter(double perimeter) { return perimeter / 2; }

double Triangle::perimeter() { return (sideA + sideB + sideC); }

double Triangle::area(double semi) { semi = semiperimeter(sideA + sideB + sideC); return sqrt(semi*(semi - sideA)*(semi - sideB)*(semi - sideC)); }

Point Triangle::Centroid(const Triangle& t) {
	double x = (t.getA().getX() + t.getB().getX() + t.getC().getX()) / 3,
		y = (t.getA().getY() + t.getB().getY() + t.getC().getY()) / 3,
		z = (t.getA().getZ() + t.getB().getZ() + t.getC().getZ()) / 3;
	return Point(x, y, z);
}

ostream & operator<<(ostream & o, Triangle & t) {
	return (o << setprecision(4)
		<< "Side a = " << t.sideA << endl
		<< "Side b = " << t.sideB << endl
		<< "Side c = " << t.sideC << endl
		<< "Angles:" << endl << t.alpha << endl << t.beta << endl << t.gamma << endl
		<< "Type: " << t.typeOfTriangle() << endl
		<< "Perimeter: " << t.perimeter() << endl)
		<< "Area: " << t.area(t.semiperimeter(t.perimeter())) << endl
		<< "Centroid: \n" << Triangle::Centroid(t);
}
