#include <iostream>
#include <fstream>
#include <string>
#include "Day01.h"

using namespace std;

Day01::Day01() 
{
	ifstream fileReadStream("day01_input");

	string lineBuffer = "";

	numbersCount = 0;
	while (getline(fileReadStream, lineBuffer))
	{
		numbers[numbersCount] = stoi(lineBuffer);
		numbersCount++;
	}
}

void Day01::findSumComponents(int &component1, int &component2) 
{
	for (int i = 0; i < numbersCount; i++)
	{
		int numberToTest = numbers[i];

		for (int j = 0; j < numbersCount; j++)
		{
			int numberToAdd = numbers[j];

			if (i == j)
			{
				continue;
			}

			if (numberToTest + numberToAdd == 2020)
			{
				component1 = numberToTest;
				component2 = numberToAdd;

				return;
			}
		}
	}
}

void Day01::findSumComponents(int &component1, int &component2, int &component3)
{
	for (int i = 0; i < numbersCount; i++)
	{
		int potentialComponent1 = numbers[i];

		for (int j = 0; j < numbersCount; j++)
		{
			if (i == j)
			{
				continue;
			}

			int potentialComponent2 = numbers[j];

			for (int k = 0; k < numbersCount; k++)
			{
				if (k == i || k == j)
				{
					continue;
				}

				int potentialComponent3 = numbers[k];

				if (potentialComponent1 + potentialComponent2 + potentialComponent3 == 2020)
				{
					component1 = potentialComponent1;
					component2 = potentialComponent2;
					component3 = potentialComponent3;

					return;
				}
			}
		}
	}
}

int Day01::calculateProductOf2SumComponents()
{
	int sumComponent1 = 0;
	int sumComponent2 = 0;
	findSumComponents(sumComponent1, sumComponent2);

	return sumComponent1 * sumComponent2;
}

long Day01::calculateProductOf3SumComponents()
{
	int sumComponent1 = 0;
	int sumComponent2 = 0;
	int sumComponent3 = 0;
	findSumComponents(sumComponent1, sumComponent2, sumComponent3);

	return sumComponent1 * sumComponent2 * sumComponent3;
}
