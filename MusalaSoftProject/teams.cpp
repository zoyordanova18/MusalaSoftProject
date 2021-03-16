#include "teams.h"
#include "participants.h"
#include "Presentation.h"
#include "helpers.h"
#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
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

	string date = yearString + '-' + monthString + '-' + dayString;

	const char* cDate = date.c_str();

	return cDate;
}

bool TEAM_SERVICE::open(const char* fileName)
{
	teamsFile.open(fileName, ios::in | ios::out | ios::_Nocreate);

	if (teamsFile.is_open() == false)
	{
		teamsFile.open(fileName, ios::out);
	}

	teamsFile.close();

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
		if (teamsFile.read((byte_*)&team, sizeof(TEAM)))
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

	if (teamsFile.write((byte_*)&team, sizeof(TEAM)))
	{
		return true;
	}

	return false;
}

vector<TEAM> TEAM_SERVICE::getAll()
{
	TEAM team;
	vector<TEAM> teams;

	teamsFile.seekg(0, ios::end);
	streampos fileSize = teamsFile.tellg();
	teamsFile.seekg(0, ios::beg);

	while (teamsFile.tellg() < fileSize)
	{
		if (teamsFile.read((byte_*)&team, sizeof(TEAM)))
		{
			teams.push_back(team);
		}
		else
		{
			throw("A wild error appeard!");
		}
	}

	return teams;
}

void TEAM_SERVICE::editTeacher(int teamId, int teacherId)
{

	TEAM team;

	teamsFile.seekg(0, ios::end);
	streampos fileSize = teamsFile.tellg();
	teamsFile.seekg(0, ios::beg);

	int t = teamsFile.tellg();

	while (teamsFile.tellg() < fileSize)
	{
		if (teamsFile.read((byte_*)&team, sizeof(TEAM)))
		{
			if (team.id == teamId)
			{

				team.teacherId = teacherId;

				teamsFile.seekg(-332, ios::cur);
				if (teamsFile.write((byte_*)&team, sizeof(TEAM)))
				{
					return;
				}
				else
				{
					throw exception("A wild error appeard!");
				}
			}
		}
	}

	throw exception("Invalid Id");
}

void TEAM_SERVICE::editDescription(int teamId, string description)
{

	TEAM team;

	teamsFile.seekg(0, ios::end);
	streampos fileSize = teamsFile.tellg();
	teamsFile.seekg(0, ios::beg);

	int t = teamsFile.tellg();

	while (teamsFile.tellg() < fileSize)
	{
		if (teamsFile.read((byte_*)&team, sizeof(TEAM)))
		{
			if (team.id == teamId)
			{

				int res = strcpy_s(team.description, description.c_str());

				teamsFile.seekg(-332, ios::cur);
				if (teamsFile.write((byte_*)&team, sizeof(TEAM)))
				{
					return;
				}
				else
				{
					throw exception("A wild error appeard!");
				}
			}
		}
	}

	throw exception("Invalid Id");
}


void showAllTeams()
{
	vector<PARTICIPANT> participantsIds = PARTICIPANT_SERVICE::getAll();
	vector<TEAM> teams = TEAM_SERVICE::getAll();

	map<string, string> participants;

	showTeamTableHeader();

	for (size_t i = 0; i < teams.size(); i++)
	{
		 participants = getParticipantNameAndRole(participantsIds, teams[i].id);
		 vector<string> parts = participantsToVector(participants);
		 vector<string> desc = descriptionToVector(teams[i].description, 30);

		 printRowInTeamTable(teams[i], desc, parts);
	}

}


