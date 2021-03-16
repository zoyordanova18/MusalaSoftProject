#pragma once
#include "define.h"
#include <fstream>
#include <vector>

extern std::fstream teamsFile;

enum class TEAM_STATUS
{
	IN_USE,
	NOT_ACTIVE,
	ARCHIVED
};

// For storing team details
struct TEAM
{
	int id = 0;
	char name[MAX_CHAR_ARRAY_LENGTH];
	char description[MAX_DESCRIPTION_LENGTH];
	char dateOfSetup[MAX_CHAR_ARRAY_LENGTH];
	TEAM_STATUS status;
	int teacherId;
};

void showAllTeams();

// Methods used for working with elements of struct TEAM type
struct TEAM_SERVICE
{
	static std::vector<TEAM> getAll();
	static bool open(const char* fileName = "teams.txt");
	static void close();
	static uint32_t generateId();
	static bool add(TEAM team);
	void editTeacher(int teamId, int teacherId);
	void editDescription(int teamId, std::string description);
};


// Gets system data for initializing team creation date
std::string getTodaysDate();


