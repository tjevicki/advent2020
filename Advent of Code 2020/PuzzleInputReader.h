#include <string>
#include <fstream>

#pragma once

using namespace std;

class PuzzleInputReader
{
	private:
		ifstream fileReadStream;

	public:
		PuzzleInputReader(std::string fileName);
		~PuzzleInputReader();

		string * readInput();
};