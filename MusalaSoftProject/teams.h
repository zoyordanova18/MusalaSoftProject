#pragma once
#include "define.h"

enum class TEAM_STATUS
{
	IN_USE,
	NOT_ACTIVE,
	ARCHIVED
};

struct DATE
{
	int day;
	int month;
	int Year;
};

struct TEAMS
{
	int id = 0;
	char name[MAX_DESCRIPTION_LENGTH];
	DATE dateOfSetup;
	TEAM_STATUS status;
	int teacherId;
};


