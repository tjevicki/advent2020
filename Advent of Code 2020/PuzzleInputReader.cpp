#include "PuzzleInputReader.h"

#include <iostream>
#include <fstream>

using namespace std;

PuzzleInputReader::PuzzleInputReader(string fileName)
{
	fileReadStream = ifstream(fileName);
}

PuzzleInputReader::~PuzzleInputReader()
{
	fileReadStream.close();
}

string * PuzzleInputReader::readInput()
{
	return new string;
}