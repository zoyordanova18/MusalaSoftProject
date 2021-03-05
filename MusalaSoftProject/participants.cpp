#include "participants.h"
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
