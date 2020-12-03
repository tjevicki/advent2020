#pragma once

#include <vector>
#include "PasswordWithRules.h"

class Day02 
{
	private:
		PasswordWithRules decodeLine(string line);
		std::vector<PasswordWithRules> readRulesAndPasswordsFromFile();

	public:
		Day02();
		int numberOfValidSledRentalPasswords();
		int numberOfValidTobogganPasswords();
};
