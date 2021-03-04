#include "teachers.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

fstream teachersFile;

bool TEACHER_SERVICE::open(const char* fileName)
{
	/*teachersFile.open(fileName, ios::in | ios::out | ios::_Noreplace);

	if (teachersFile.is_open() == false)
	{
		teachersFile.open(fileName, ios::out);
		teachersFile.close();
	}*/

	teachersFile.open(fileName, ios::ate | ios::binary | ios::in | ios::out);
	return teachersFile.is_open();
}

void TEACHER_SERVICE::close()
{
	teachersFile.close();
}
