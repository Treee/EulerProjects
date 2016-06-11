// MultiplesOf3And5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SumMultiplesOf3And5.h"


int main()
{
	int maxValue;
	std::cout << "Enter a whole non negative number to find the sum of all its multiples of 3 and 5. \n";
	std::cin >> maxValue;
	SumMultiplesOf3And5 foo;
	foo.SumMultiples(maxValue);

	system("pause");
    return 0;
}


