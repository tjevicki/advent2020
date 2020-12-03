#pragma once
class Day01
{
	private:
		int numbers[1000];
		int numbersCount;

		int sumComponent1;
		int sumComponent2;

		void findSumComponents(int &component1, int &component2);
		void findSumComponents(int &component1, int &component2, int &component3);

	public:
		Day01();
		int calculateProductOf2SumComponents();
		long calculateProductOf3SumComponents();
};

