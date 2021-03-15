#include "participants.h"
#include "students.h"
#include "define.h"
#include "helpers.h"
#include "teams.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

fstream participantsFile;

bool PARTICIPANT_SERVICE::open(const char* fileName)
{
	participantsFile.open(fileName, ios::in | ios::out | ios::_Nocreate);

	if (participantsFile.is_open() == false)
	{
		participantsFile.open(fileName, ios::out);
	}

	participantsFile.close();

	participantsFile.open(fileName, ios::ate | ios::binary | ios::in 
														   | ios::out);
	return participantsFile.is_open();
}

void PARTICIPANT_SERVICE::close()
{
	participantsFile.close();
}

bool PARTICIPANT_SERVICE::add(PARTICIPANT participant)
{
	participantsFile.seekp(0, ios::end);

	if (participantsFile.write((byte_*)&participant, sizeof(PARTICIPANT)))
	{
		return true;
	}

	return false;
}

void PARTICIPANT_SERVICE::removePt(int studentId, int teamId)
{
	// India starts here

	ofstream temp("temp.txt", ios::binary);

	PARTICIPANT participant;

	participantsFile.seekg(0, ios::beg);

	vector<PARTICIPANT> participants;

	while (!participantsFile.eof())
	{
		participantsFile.read((byte_*)&participant, sizeof(PARTICIPANT));

		if (participant.studentId != studentId && participant.teamId != teamId)
		{
			participants.push_back(participant);
		}
	}

	for (size_t i = 0; i < participants.size() - 1; i++)
	{
		temp.write((byte_*)&participants[i], sizeof(PARTICIPANT));
	}

	//throw exception("Invalid ID");

	close();
	temp.close();

	remove("participants.txt");
	int rs = rename("temp.txt", "participants.txt");

	open();
}


vector<PARTICIPANT> PARTICIPANT_SERVICE::getAll()
{
	PARTICIPANT participant;
	vector<PARTICIPANT> participants;

	participantsFile.seekg(0, ios::end);
	streampos fileSize = participantsFile.tellg();
	participantsFile.seekg(0, ios::beg);

	while (participantsFile.tellg() < fileSize)
	{
		if (participantsFile.read((byte_*)&participant, sizeof(PARTICIPANT)))
		{
			participants.push_back(participant);
		}
		else
		{
			throw("A wild error appeard!");
		}
	}

	return participants;

}

map<string, string> getParticipantNameAndRole(vector<PARTICIPANT> participant,
																	int teamId)
{
	string firstNameStr, lastNameStr;
	vector<STUDENT> students = STUDENT_SERVICE::getAll();

	map<string, string> result;

	for (size_t i = 0; i < participant.size(); i++)
	{
		if (participant[i].teamId == teamId)
		{
			firstNameStr = findStudentById(students,
						   participant[i].studentId).firstName;
			lastNameStr = findStudentById(students, 
						   participant[i].studentId).lastName;

			result[enumRoleToString(participant[i].role)] = 
							firstNameStr + " " + lastNameStr;
		}
	}

	return result;
}

void PARTICIPANT_SERVICE::editParticipantInTeam(int teamId, int studentId,
															int newStudentId)
{
	PARTICIPANT participant;

	participantsFile.seekg(0, ios::end);
	streampos fileSize = participantsFile.tellg();
	participantsFile.seekg(0, ios::beg);

	int t = participantsFile.tellg();

	while (participantsFile.tellg() < fileSize)
	{
		if (participantsFile.read((byte_*)&participant, sizeof(PARTICIPANT)))
		{
			if (participant.teamId == teamId && participant.studentId == studentId)
			{
				participant.studentId = newStudentId;

				participantsFile.seekg(-12, ios::cur);
				if (participantsFile.write((byte_*)&participant, sizeof(PARTICIPANT)))
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