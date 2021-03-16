#pragma once
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "participants.h";
#include "teams.h";
#include "teachers.h"
#include "students.h"

// General functions for validating input
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

// Regex patterns for validation of different input fields
bool isEmailValid(std::string email);

bool isStudentClassValid(std::string studentClass);

bool isNameValid(std::string name);

// Function for changing the console output color
bool setColor(uint16_t newColor);

// General function for filtering data
template<class T>
std::vector<T> findRecords(std::vector<T> records,
	std::function<bool(const T&)> const& lambda)
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

// Function which changes default console mode to full screen
void consoleSetup();

//Conerting information to CSV file format
template<class T>
std::string vectorToCsv(std::vector<T> records,
	std::string header,
	std::function<std::string(const T&)> const& lambda)
{
	std::string result = header;

	for (size_t i = 0; i < records.size(); i++)
	{
		result += lambda(records[i]);
	}

	return result;
}

//Exporting the information in a CSV file
void saveCsvFile(std::string csv);

std::vector<std::string> descriptionToVector(std::string description,
	int lineLength);

std::vector<std::string> participantsToVector(
	std::map<std::string, std::string> participants);

void removeSpaces(std::string& str);

bool isStringDeleted(std::string);

bool isInputInRange(std::size_t, int);

void openAllFiles();

void closeAllFiles();

bool isStringTooLong(std::string str, int max);