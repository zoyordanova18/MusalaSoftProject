#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

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

std::map<std::string, std::string> getParticipantNameAndRole(std::vector<PARTICIPANT>, int teamId);


struct PARTICIPANT_SERVICE
{
	static bool open(const char* fileName = "participants.txt");
	static void close();
	static bool add(PARTICIPANT participant);
	static void removePt(int, int);
	static std::vector<PARTICIPANT> getAllParticipantsFromTeam(int teamId);
	static std::vector<PARTICIPANT> getAll();
};

