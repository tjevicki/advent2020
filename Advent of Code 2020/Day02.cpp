#include <fstream>
#include <iostream>

#include "Day02.h"

Day02::Day02()
{

}

PasswordWithRules Day02::decodeLine(string line)
{
	int minOccurrences, maxOccurrences;
	char character;
	string password;

	// Min occurences
	int cursor = line.find_first_of('-');
	minOccurrences = stoi(line.substr(0, cursor));
	line = line.substr(cursor + 1, line.length());

	// Max occurrences
	cursor = line.find_first_of(" ");
	maxOccurrences = stoi(line.substr(0, cursor));
	line = line.substr(cursor + 1, line.length());

	character = line[0];

	password = line.substr(2, line.length());

	return PasswordWithRules(minOccurrences, maxOccurrences, character, password);
}

vector<PasswordWithRules> Day02::readRulesAndPasswordsFromFile()
{
	ifstream fileReadStream("day02_input");

	string lineBuffer = "";

	string lines[1000];

	int linesCount = 0;
	while (getline(fileReadStream, lineBuffer))
	{
		lines[linesCount] = lineBuffer;
		linesCount++;
	}

	vector<PasswordWithRules> passwordsWithRules(linesCount);
	for (int i(0); i < linesCount; i++)
	{
		passwordsWithRules[i] = decodeLine(lines[i]);
	}

	return passwordsWithRules;
}

int Day02::numberOfValidSledRentalPasswords()
{
	vector<PasswordWithRules> rulesAndPasswords = readRulesAndPasswordsFromFile();

	int validCount(0);
	for (int i(0); i < rulesAndPasswords.size(); i++)
	{
		if (rulesAndPasswords[i].isPasswordValidForSledRental())
		{
			validCount++;
		}
	}

	return validCount;
}

int Day02::numberOfValidTobogganPasswords()
{
	vector<PasswordWithRules> rulesAndPasswords = readRulesAndPasswordsFromFile();

	int validCount(0);
	for (int i(0); i < rulesAndPasswords.size(); i++)
	{
		if (rulesAndPasswords[i].isPasswordValidForToboggan())
		{
			validCount++;
		}
	}

	return validCount;
}