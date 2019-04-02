#include "Subset.h"
#include"HeaderEx12.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//Ex 1 
	// Да се дефинира двумерен динамичен масив, който има размерност 2 реда
	// и n стълба, с помощта на който ще представяме функция върху множество с n елемента
	unsigned cols;
	cout << "Cols: ";
	cin >> cols;

	int **arr = nullptr;
	arr = new int*[2];
	for (size_t i = 0; i < 2; i++)
		arr[i] = new int[cols];

	fillArray(2, cols, arr);

	cout << "Your matrix is: \n";
	PrintArray(2, cols, arr);

	cout << "Injection: ";
	Injection(cols, arr) ? cout << "YES!\n" : cout << "NO!\n";

	cout << "Surjection: ";
	Surjection(cols, arr) ? cout << "YES!\n" : cout << "NO!\n";

	cout << "Permutation: ";
	Permutation(cols, arr) ? cout << "YES!\n" : cout << "NO!\n";

	if (Permutation(cols, arr) && AllDigitsAreTheSame(arr, cols))
	{
		cout << "Number of permutations: ";
		PermutationsCounter(cols, arr);

		FixedPoints(cols, arr);
		Identity(cols, arr);

		int* arrOfLenght = new int;

		cout << endl;
		IndependentCycles(cols, arr, arrOfLenght);
		cout << endl;

		char* inputSequence = new char;
		cout << "Please enter your independent Cycle \nExample: (11,22,33)(44)\n";
		cin >> inputSequence;

		IndepCycleToMatrix(inputSequence);
	}
	else {
		cout << "Something went wrong!\n";
		if (!AllDigitsAreTheSame(arr, cols))
			cout << "Check your input numbers!\n";
	}

	delete[]  arr;
}


