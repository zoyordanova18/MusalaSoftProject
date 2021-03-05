#pragma once
#include <iostream>
#include <fstream>

extern std::fstream participantsFile;

enum class ROLES
{
	BACK_END,
	FRONT_END,
	SCRUM_MASTER,
	QA
};

struct PARTICIPANT
{
	int studentId;
	int teamId;
	ROLES role;
};

struct PARTICIPANT_SERVICE
{
	static bool open(const char* fileName = "participants.txt");
	static void close();
	static bool add(PARTICIPANT student);
	static void removePt(int, int);
};

