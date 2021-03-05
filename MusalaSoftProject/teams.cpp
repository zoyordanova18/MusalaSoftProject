#include "teams.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

fstream teamsFile;

string getTodaysDate()
{
	time_t t = time(NULL);
	tm tPtr{ 0 };
	errno_t err = localtime_s(&tPtr, &t);

	int day, month, year;
	string dayString, monthString, yearString;

	day = (tPtr.tm_mday);
	month = (tPtr.tm_mon) + 1;
	year = (tPtr.tm_year) + 1900;

	dayString = to_string(day);
	dayString = dayString.size() == 1 ? "0" + dayString : dayString;
	monthString = to_string(month);
	monthString = monthString.size() == 1 ? "0" + monthString : monthString;
	yearString = to_string(year);

	string date =  yearString + '-' + monthString + '-' + dayString;

	const char* cDate = date.c_str();

	return cDate;
}

bool TEAM_SERVICE::open(const char* fileName)
{
	/*studentsFile.open(fileName, ios::in | ios::out | ios::_Noreplace);

	if (studentsFile.is_open() == false)
	{
		studentsFile.open(fileName, ios::out);
		studentsFile.close();
	}*/

	teamsFile.open(fileName, ios::ate | ios::binary | ios::in | ios::out);
	return teamsFile.is_open();
}

void TEAM_SERVICE::close()
{
	teamsFile.close();
}

uint32_t TEAM_SERVICE::generateId()
{
	int id = -1;
	TEAM team;

	teamsFile.seekg(0, ios::beg);

	while (teamsFile)
	{
		if (teamsFile.read((byte*)&team, sizeof(TEAM)))
		{
			id = team.id;
		}
	}

	if (id == -1 || teamsFile.eof()) {
		teamsFile.clear();
	}

	id++;

	return id;
}

bool TEAM_SERVICE::add(TEAM team)
{
	team.id = generateId();
	strcpy_s(team.dateOfSetup, getTodaysDate().c_str());

	teamsFile.seekp(0, ios::end);

	if (teamsFile.write((byte*)&team, sizeof(TEAM)))
	{
		return true;
	}

	return false;
}


