#pragma once

#include <string>

using namespace std;

class PasswordWithRules
{
	private:
		int rule1;
		int rule2;
		char character;
		string password;

	public:
		PasswordWithRules();
		PasswordWithRules(int minOccurrences, int maxOccurrences, char character, string password);
		bool isPasswordValidForSledRental();
		bool isPasswordValidForToboggan();
};

