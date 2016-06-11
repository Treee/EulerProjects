#include "stdafx.h"
#include "SumMultiplesOf3And5.h"

int SumMultiplesOf3And5::SumMultiples(int maxValue)
{
	int sum = 0;
	std::cout << "The multiples of 3 and 5 are as follows up to: " << maxValue << "\n";

	for (int i = 0; i < maxValue; i++)
	{
		if (i % 3 != 0 && i % 5 != 0) continue;
		sum += i;
		std::cout << i << ", ";
	}
	std::cout << "\nThe sum of all the multiples of 3 and 5 up to " << maxValue << " is " << sum << ".\n";
	return sum;
}
