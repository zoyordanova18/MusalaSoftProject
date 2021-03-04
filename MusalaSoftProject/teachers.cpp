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

bool TEACHER_SERVICE::add(TEACHER teacher)
{
	teacher.id = generateId();

	teachersFile.seekp(0, ios::end);

	if (teachersFile.write((byte*)&teacher, sizeof(TEACHER)))
	{
		return true;
	}

	return false;
}

uint32_t TEACHER_SERVICE::generateId()
{
	int id = -1;
	TEACHER teacher;

	teachersFile.seekg(0, ios::beg);

	while (teachersFile)
	{
		if (teachersFile.read((byte*)&teacher, sizeof(TEACHER)))
		{
			id = teacher.id;
		}
	}

	if (id == -1 || teachersFile.eof()) {
		teachersFile.clear();
	}

	id++;

	return id;
}

vector<TEACHER> TEACHER_SERVICE::getAll()
{
	TEACHER student;
	vector<TEACHER> students;

	teachersFile.seekg(0, ios::beg);

	while (!teachersFile.eof())
	{
		if (teachersFile.read((byte*)&student, sizeof(TEACHER)))
		{
			students.push_back(student);
		}
	}

	return students;

}

