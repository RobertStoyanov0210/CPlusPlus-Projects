#include <iostream>
#include "Point.h"
#include <exception>

using namespace std;

int main() {

	cout << "------------------------Point------------------------" << endl;
	Point a(0, 0, 0);
	Point b(1, 2, 3);

	cout << "Point a: \n" << a << "Point b: \n" << b;

	if (a == b)
		cout << "They match!\n\n";
	else
		cout << "They don't match!\n\n";



	cout << "------------------------Vectorv------------------------" << endl;
	Vector v1(a, b);
	cout << "V1 created with 2 points: \n" << v1 << endl;

	Vector v2(1, 2, 3);
	cout << "V2 created with parameters: \n" << v2 << "length of v2: " << v2.lengthOfV() << endl << endl;

	cout << "v1 + v2: \n" << v1 + v2 << endl;
	cout << "v1 - v2: \n" << v1 - v2 << endl;
	cout << "v1 * v2: \n" << v1 * v2 << endl;
	cout << "scalar between v1 and v2: " << v1 * v2 << endl;

	Vector v3(1, 2, 3);
	cout << "V3: \n" << v3 << "\nDirection of V3: \n" << v3.dirOfV() << endl;

	Vector t1(1, 2, 1);
	Vector t2(1, 3, 3);

	cout << "t1 ^ t2: \n" << (t1 ^ t2) << endl;

	//// try catch of direction TEST
	//Vector v0(0, 0, 0);
	//cout << v0.dirOfV();

	// Pependicularity & parallel vectors TEST
	Vector vv(1, 2, 3);
	Vector vv2(2, 4, 6);
	cout << "Perpendicularity between vv and vv2: " << boolalpha << Vector::perpendicularity(vv, vv2) << endl;
	cout << "Paralel vectors vv and vv2: " << boolalpha << Vector::parallel(vv, vv2) << endl;

	//cross product between 3 vectors TEST
	Vector cP(1, 2, 3);
	Vector cP1(2, 4, 6);
	Vector cP2(-2, 1, 0);
	cout << "Cross product: " << cP(cP1, cP2) << endl << endl << endl;



	cout << "------------------------Triangle------------------------" << endl;
	Point aT(0, 0, 0);
	Point bT(5, 0, 0);
	Point cT(0, 5, 0);
	Triangle t(aT, bT, cT);

	cout << t;
	return -1;
}
