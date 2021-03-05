#pragma once
#include "define.h"
#include <fstream>

extern std::fstream teamsFile;

enum class TEAM_STATUS
{
	IN_USE,
	NOT_ACTIVE,
	ARCHIVED
};

struct TEAM
{
	int id = 0;
	char name[MAX_CHAR_ARRAY_LENGTH];
	char description[MAX_DESCRIPTION_LENGTH];
	char dateOfSetup[MAX_CHAR_ARRAY_LENGTH];
	TEAM_STATUS status;
	int teacherId;
};

struct TEAM_SERVICE
{
	static bool open(const char* fileName = "teams.txt");
	static void close();
	static uint32_t generateId();
	static bool add(TEAM team);
};


std::string getTodaysDate();

