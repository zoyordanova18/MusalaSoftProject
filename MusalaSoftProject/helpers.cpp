#include "helpers.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <functional>
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

bool isEmailValid(std::string email)
{
		regex pattern
		("(([a-z]+)([._a-z0-9])([a-z0-9]+)).{1,64}(@)([a-z]+)([.a-z])([a-z])+",
			regex_constants::icase);

	return regex_match(email, pattern);
}

bool isStudentClassValid(std::string studentClass)
{
	regex pattern
	("([1-9]|1[0-2])[a-z]", regex_constants::icase);

	return regex_match(studentClass, pattern);
}

bool setColor(uint16_t newColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut != INVALID_HANDLE_VALUE)
	{
		return SetConsoleTextAttribute(hStdOut, newColor);
	}

	return false;
}

template<class T>
vector<T> findRecords(vector<T> records, function<bool(const T&)> const& lambda)
{
	vector<T> results;

	auto forEachPredicate = [&](const T& record)
	{
		if (lambda(record))
		{
			results.push_back(record);
		}
	};

	for_each(records.begin(), records.end(), forEachPredicate);

	return results;
}