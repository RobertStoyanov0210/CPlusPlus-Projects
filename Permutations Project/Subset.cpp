#include "Subset.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>
// Ex 2 
//Да се дефинира функция за запълване на двумерен масив по зададено от потребителя множество от стойности
int fillArray(int rows, int cols, int **arr) {
	srand(time(NULL));
	int n;
	int rndOrByHand;
	//1st ROW
	for (size_t i = 0; i < cols; i++)
	{
		std::cout << "{" << 0 << " , " << i << "}: ";
		std::cin >> n;
		arr[0][i] = n;
	}
	//2nd ROW
	std::cout << "Please choose \'1\' for random gereration or \'2\' for index by index generation: ";
	std::cin >> rndOrByHand;
	if (rndOrByHand == 1)
		for (size_t i = 0; i < cols; i++)
		{
			// take rnd index from 1st row and index's number take place on 2nd row
			n = rand() % cols;
			arr[1][i] = arr[0][n];
		}

	else
		for (size_t i = 0; i < cols; i++)
		{
			std::cout << "{" << 1 << " , " << i << "}: ";
			std::cin >> n;
			arr[1][i] = n;
		}
	std::cout << std::endl;
	return **arr;
}
int PrintArray(int rows, int cols, int **arr) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < cols; j++)
			std::cout << arr[i][j] << " ";

		std::cout << "\n";
	}
	std::cout << "\n";
	return **arr;
}
// Ex 3
// Да се дефинира функция, която проверява дали записана в масив функция е инекция
bool Injection(int cols, int **arr) {
	bool isInjection = true;
	for (size_t i = 0; i < cols; i++) {
		for (size_t j = i + 1; j < cols; j++)
		{
			if (arr[1][i] == arr[1][j]) {
				isInjection = false;
				break;
			}
		}
		if (isInjection == false)
			break;
	}
	return isInjection;
}
// Ex 4 
// Проверява дали е сюрекция
bool Surjection(int cols, int **arr) {
	bool isSurj = true;
	for (size_t i = 0; i < cols; i++)
	{
		// here 0 == NULL so if there is a 0 than this function is not surjecion
		if (arr[1][i] <= 0)
			isSurj = false;
	}
	return isSurj;
}
// Ex 5
// Проверява дали е пермутация
bool Permutation(int cols, int **arr) {

	if (Injection(cols, arr) && Surjection(cols, arr))
		return true;
	else
		return false;
}
// Ex 6
// Намира брой на пермутациите на зададеното от потребителя множество
int PermutationsCounter(int cols, int **arr) {

	int factorial = 1;
	for (int i = 1; i <= cols; i++)
		factorial *= i;

	std::cout << factorial << "\n\n";
	return factorial;
}
// Ex 7
// Проверява дали записана в пасив пермутация има неподвижна точка
// Ex 8
// Намира брой на неподвижните точки
bool FixedPoints(int cols, int **arr) {
	bool sameDigits = false;
	int nOfFixedPoints = 0;
	for (size_t i = 0; i < cols; i++)
	{
		if (arr[0][i] == arr[1][i])
		{
			sameDigits = true;
			nOfFixedPoints++;
		}
	}
	if (sameDigits) {
		if (nOfFixedPoints > 1)
			std::cout << "There are " << nOfFixedPoints << " fixed points!\n";
		else
			std::cout << "There is a fixed point!\n";
		return true;
	}
	else {
		std::cout << "There are 0 fixed points!\n";
		return false;
	}
}
// Ex 9
// Проверява дали записана в масив пермутация е идентитет
int Identity(int cols, int**arr) {
	int counter = 0;
	for (size_t i = 0; i < cols; i++)
	{
		if (arr[0][i] == arr[1][i])
			counter++;

	}
	if (counter == cols)
	{
		std::cout << "Function is identity\n";
		return true;
	}
	else
	{
		std::cout << "Function is not identity\n";
		return false;
	}
}
// Ex 10
// Представя дадена пермутация във вид на независими цикли и ги отпечатва
//Ex 11
// Намира дължината на независимите цикли, като дължините се записват в едномерен масив
void IndependentCycles(int cols, int **arr, int *arrOfLenght) {
	unsigned  begin, pos, cnt = 0, cnt1 = 0, lenghtCounter = 1;
	bool allVisited = false;
	int* visited = new int[cols];
	for (size_t i = 0; i < cols; i++)
		visited[i] = 0;
	//all identity are 1 automatically
	for (size_t i = 0; i < cols; i++)
		if (arr[0][i] == arr[1][i])
			visited[i] = 1;
	//while there are not visited in visited do... 
	while (!allVisited)
	{
		for (size_t i = 0; i < cols; i++)
		{
			if (visited[i] == 1)
			{
				//'1' == cnt++;
				cnt++;
				//if everything is '1'
				if (cnt == cols)
				{
					allVisited = true;
					break;
				}
			}
			else
			{
				//begin is every first element in one bracket 
				begin = i;
				visited[i] = 1;
				break;
			}
		}
		// do this only if there are '0' in visited
		if (!allVisited)
		{
			// pos counts the second row
			pos = begin;
			std::cout << "( " << arr[0][begin] << " "; // cout the first digit

			//search the next number while != from the first
			while (arr[0][begin] != arr[1][pos]) {
				for (size_t i = 0; i < cols; i++) {
					if (arr[0][i] == arr[1][pos])
					{
						std::cout << arr[1][pos] << " "; // cout the number on the second row
						pos = i;
						visited[i] = 1;
						lenghtCounter++; // this counts the elements in each cycle
						break;
					}
				}
			}
			arrOfLenght[cnt1] = lenghtCounter;
			lenghtCounter = 1;
			cnt1++;
			std::cout << ") ";
		}
	}
	std::cout << "\n";
	for (size_t i = 0; i < cnt1; i++)
		std::cout << arrOfLenght[i] << " ";
	std::cout << "\n";
	delete[] visited;
}
bool AllDigitsAreTheSame(int** arr, int cols) {
	for (size_t i = 0; i < cols; i++)
	{
		bool consist = false;
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[0][i] == arr[1][j])
				consist = true;
		}
		if (!consist)
			return false;
	}
	return true;
}
