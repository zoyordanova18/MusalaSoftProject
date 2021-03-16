#include <iostream>
#include <vector>
#include <windows.h>
#include <functional>
#include <regex>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include "helpers.h"
#include "teams.h"
#include "teachers.h"
#include "students.h"
using namespace std;

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

bool isNameValid(std::string name)
{
	regex pattern
		("[a-z-A-Z]+", regex_constants::icase);

	return regex_match(name, pattern);
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

std::string enumRoleToString(ROLES role)
{
	switch (role)
	{
	case ROLES::BACK_END:
		return "Back-End";

	case ROLES::FRONT_END:
		return "Front-End";

	case ROLES::QA:
		return "QA";

	case ROLES::SCRUM_MASTER:
		return "Scrum Master";
	}
}

std::string enumStatusToString(TEAM_STATUS status)
{
	switch (status)
	{
	case TEAM_STATUS::IN_USE:
		return "In Use";

	case TEAM_STATUS::NOT_ACTIVE:
		return "Not Active";

	case TEAM_STATUS::ARCHIVED:
		return "Archive";
	}
}

void consoleSetup()
{
	TCHAR conTitle[64];

	HRESULT hr = StringCchPrintf(conTitle, 64, TEXT("Foo School"));
	if (!(SUCCEEDED(hr) && SetConsoleTitle(conTitle)))
	{
		throw exception("A wild error appeard!");
	}

	HWND window = GetConsoleWindow();

	if (window != NULL && ShowWindow(window, SW_MAXIMIZE))
	{
		SendMessage(window, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	}
	else
	{
		throw exception("A wild error appeard!");
	}
}

void saveCsvFile(std::string csv)
{
	ofstream csvFile("data.csv", ios::out, ios::trunc);

	if (csvFile.is_open())
	{
		csvFile << csv;
		csvFile.close();
		system("\"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE\" data.csv");
		return;
	}
	
	csvFile.close();
	throw exception("A Wild Appeard!");
}

vector<string> descriptionToVector(string description, int lineLength)
{
	vector<string> result;

	while (description.size() > 0)
	{
		result.push_back(description.substr(0, 30));
		description.erase(0, 30);
	}

	return result;
}

vector<string> participantsToVector(map<string, string> participants)
{
	vector<string> result;

	for (auto it = participants.cbegin(); it != participants.cend(); it++)
	{
		result.push_back((*it).first + ": " + (*it).second);
	}

	return result;
}

void removeSpaces(string& str)
{
	string::iterator currentChar = str.begin();

	while (currentChar < str.end())
	{
		if (*currentChar == ' ')
		{
			str.erase(currentChar, currentChar + 1);
		}
		else
		{
			currentChar++;
		}
	}
}

bool isStringDeleted(std::string msg)
{
	return (msg.find('!') != string::npos);
}

bool isInputInRange(size_t size, int input)
{
	if (input <= size and input > 0)
	{
		return true;
	}

	return false;
}

void openAllFiles()
{
	bool isOpen = STUDENT_SERVICE::open();
	bool isOpenT = TEACHER_SERVICE::open();
	bool isOpenTeam = TEAM_SERVICE::open();
	bool isOpenP = PARTICIPANT_SERVICE::open();
}

void closeAllFiles()
{
	STUDENT_SERVICE::close();
	TEACHER_SERVICE::close();
	TEAM_SERVICE::close();
	PARTICIPANT_SERVICE::close();
}

bool isStringTooLong(string str, int max)
{
	return (str.size() > max);
}

