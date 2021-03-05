#include "participants.h"
#include "define.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

fstream participantsFile;

bool PARTICIPANT_SERVICE::open(const char* fileName)
{
	/*studentsFile.open(fileName, ios::in | ios::out | ios::_Noreplace);

	if (studentsFile.is_open() == false)
	{
		studentsFile.open(fileName, ios::out);
		studentsFile.close();
	}*/

	participantsFile.open(fileName, ios::ate | ios::binary | ios::in | ios::out);
	return participantsFile.is_open();
}

void PARTICIPANT_SERVICE::close()
{
	participantsFile.close();
}

bool PARTICIPANT_SERVICE::add(PARTICIPANT participant)
{
	participantsFile.seekp(0, ios::end);

	if (participantsFile.write((byte*)&participant, sizeof(PARTICIPANT)))
	{
		return true;
	}

	return false;
}

