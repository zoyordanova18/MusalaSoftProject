#pragma once
#include "define.h"

enum class TEAM_STATUS
{
	IN_USE,
	NOT_ACTIVE,
	ARCHIVED
};

struct TEAMS
{
	int id = 0;
	char name[MAX_DESCRIPTION_LENGTH];
	char dateOfSetup[MAX_CHAR_ARRAY_LENGTH];
	TEAM_STATUS status;
	int teacherId;
};


std::string getTodaysDate();

