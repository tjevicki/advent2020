#include <string>

#include "PasswordWithRules.h"

PasswordWithRules::PasswordWithRules()
{

}

PasswordWithRules::PasswordWithRules(int minOccurrences, int maxOccurrences, char character, string password)
{
	this->rule1 = minOccurrences;
	this->rule2 = maxOccurrences;
	this->character = character;
	this->password = password;
}

bool PasswordWithRules::isPasswordValidForSledRental()
{
	int occurrences(0);
	for (int i(0); i < password.length(); i++)
	{
		if (password[i] == character)
		{
			occurrences++;
		}
	}

	return occurrences >= rule1 && occurrences <= rule2;
}

bool PasswordWithRules::isPasswordValidForToboggan()
{
	int position1 = rule1;
	int position2 = rule2;

	return (password[position1] == character && password[position2] != character) || (password[position1] != character && password[position2] == character);
}
