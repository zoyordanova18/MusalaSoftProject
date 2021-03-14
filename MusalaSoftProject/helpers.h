#pragma once
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "participants.h";
#include "teams.h";


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

bool isNameValid(std::string name);

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

std::string enumRoleToString(ROLES role);

std::string enumStatusToString(TEAM_STATUS status);

void consoleSetup();

template<class T>
std::string vectorToCsv(std::vector<T> records, std::string header, std::function<std::string(const T&)> const& lambda)
{
	std::string result = header;
	
	for (size_t i = 0; i < records.size(); i++)
	{
		result += lambda(records[i]);
	}

	return result;
}

void saveCsvFile(std::string csv);