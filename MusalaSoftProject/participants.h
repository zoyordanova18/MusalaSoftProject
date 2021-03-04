#pragma once

enum class ROLES
{
	BACK_END,
	FRONT_END,
	SCRUM_MASTER,
	QA
};

struct PARTICIPANTS
{
	int studentId;
	int teamId;
	ROLES role;
};

