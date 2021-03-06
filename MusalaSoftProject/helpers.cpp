#include "helpers.h"
#include <iostream>
#include <regex>
using namespace std;



template <class T>
bool safeCin(T& input)
{
	if (!(cin >> input))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		return false;
	}

	return true;
}

bool isEmailValid(std::string username)
{
		regex pattern
		("(([a-z]+)([._a-z0-9])([a-z0-9]+)).{1,64}(@)([a-z]+)([.a-z])([a-z])+",
			regex_constants::icase);

	return regex_match(username, pattern);
}

bool isStudentClassValid(std::string studentClass)
{
	regex pattern
	("([1-9]|1[0-2])[a-z]", regex_constants::icase);

	return regex_match(studentClass, pattern);
}
