#pragma once
#include <iostream>
#include <fstream>

constexpr auto MAX_CHAR_ARRAY_LENGTH = 32;
constexpr auto MAX_ST_CLASS_LENGTH= 32;
constexpr auto MAX_DESCRIPTION_LENGTH= 256;

typedef char byte;

enum class TEAM_STATUS
{
	IN_USE,
	NOT_ACTIVE,
	ARCHIVED
};

enum class ROLES
{
	BACK_END,
	FRONT_END,
	SCRUM_MASTER,
	QA
};



struct TEACHER
{
	int id = 0;
	char firstName[MAX_CHAR_ARRAY_LENGTH]{};
	char lastName[MAX_CHAR_ARRAY_LENGTH]{};
	char email[MAX_CHAR_ARRAY_LENGTH]{};
};

struct TEAM
{
	int id = 0;
	char teamName[MAX_CHAR_ARRAY_LENGTH]{};
	char teamDescription[MAX_DESCRIPTION_LENGTH]{};
	char dateOfSetup[MAX_CHAR_ARRAY_LENGTH]{};
	TEAM_STATUS teamStatus;
};

struct PARTICIPANTS
{
	int studentId = 0;
	int teamId = 0;
	ROLES role;
};
