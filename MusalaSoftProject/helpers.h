#pragma once
#include <iostream>
#include <functional>
#include <vector>


template <class T>
bool safeCin(T& input)
{
	if (!(std::cin >> input))
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		return false;
	}

	return true;
};


bool isEmailValid(std::string email);

bool isStudentClassValid(std::string studentClass);

bool setColor(uint16_t newColor);

template<class T>
std::vector<T> findRecords(std::vector<T> records, std::function<bool(const T&)> const& lambda)
{
	std::vector<T> results;

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