#include "HeaderEx12.h"
#include <iostream>
#include <ctype.h>

// Да се дефинира функция на C++ която получава като аргумент пермутация, представена като
// произведение от независими цикли и я отпечатва в табличен вид в конзолата

int currentNumberOfDigits = 0;

void IndepCycleToMatrix(char* arr) {
	int cnt = 0;
	//char* existingChars = new char;
	bool foundNewSequence = false;
	char firstDigit = ' ';


	while (arr[cnt] != '\0')
	{
		if (arr[cnt] != '(' && arr[cnt] != ')' && arr[cnt] != ',' && !isdigit(arr[cnt])) {
			std::cout << "Invalid input!";
		}

		cnt++;
	}

	FillMatrix(arr, cnt);
}

bool InputIsValid(int** existingChars, int size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		int currentElement = existingChars[0][i];
		for (size_t j = i + 1; j < size; j++)
		{
			int otherElement = existingChars[0][j];
			if (currentElement == otherElement)
				return false;
		}
	}

	return true;
}

void FillMatrix(char* arr, int size) {
	int **matrix = new int*[2];

	for (size_t i = 0; i < 2; i++)
		matrix[i] = new int[size];


	bool foundNewSequence = false;
	int currentStateIndexOfMatrix = 0;
	int startIndexValue = ' ';

	for (size_t i = 0; i < size; i++)
	{
		if (isdigit(arr[i]) && foundNewSequence) {
			matrix[0][currentStateIndexOfMatrix] = GetCurrentNumber(arr, size, i);
			i += currentNumberOfDigits - 1;

			if (i + 2 >= size) {
				matrix[1][currentStateIndexOfMatrix] = startIndexValue;
			}
			else {
				matrix[1][currentStateIndexOfMatrix] = GetCurrentNumber(arr, size, i + 2);
				i++;
			}

			currentStateIndexOfMatrix++;
		}

		if (isdigit(arr[i]) && !foundNewSequence) {
			int currentNumber = GetCurrentNumber(arr, size, i);
			i += currentNumberOfDigits - 1;

			startIndexValue = currentNumber;

			matrix[0][currentStateIndexOfMatrix] = currentNumber;

			if (i + 2 >= size) {
				matrix[1][currentStateIndexOfMatrix] = startIndexValue;
			}
			else {
				matrix[1][currentStateIndexOfMatrix] = GetCurrentNumber(arr, size, i + 2);
				i++;
			}

			currentStateIndexOfMatrix++;

			foundNewSequence = true;
		}

		if (arr[i] == ')') {
			foundNewSequence = false;
			matrix[1][currentStateIndexOfMatrix - 1] = startIndexValue;
		}
	}


	PrintMatrix(matrix, currentStateIndexOfMatrix);

	if (!InputIsValid(matrix, currentStateIndexOfMatrix)) {
		std::cout << "Invalid input!";
	}
}

void PrintMatrix(int** matrix, int size)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < size; j++)
			std::cout << matrix[i][j] << " ";

		std::cout << "\n";
	}
}

int GetCurrentNumber(char* arr, int size, int currentIndex) {
	if (!isdigit(arr[currentIndex])) {
		currentNumberOfDigits = 1;
		return 0;
	}

	int currentNumber = 0;
	int tempIndex = currentIndex;

	while (isdigit(arr[tempIndex]))
		tempIndex++;


	int foundDiff = tempIndex - currentIndex;

	currentNumberOfDigits = foundDiff;

	for (int i = foundDiff - 1; i >= 0; i--)
	{
		currentNumber += (arr[currentIndex] - '0') * pow(10, i);
		currentIndex++;
	}

	return currentNumber;
}
