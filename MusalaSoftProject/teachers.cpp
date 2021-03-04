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
	TEACHER teacher;
	vector<TEACHER> teachers;

	teachersFile.seekg(0, ios::beg);

	while (!teachersFile.eof())
	{
		if (teachersFile.read((byte*)&teacher, sizeof(TEACHER)))
		{
			teachers.push_back(teacher);
		}
	}

	return teachers;

}

string TEACHER::toString(TEACHER& teacher)
{
	stringstream s;
	s << teacher.id << " | " << teacher.firstName << ", " << teacher.lastName << endl;
	return s.str();
}

void TEACHER::showAll()
{
	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	for (size_t i = 0; i < teachers.size(); i++)
	{
		cout << "Id		|" << teachers[i].id << endl;
		cout << "Name   |" << teachers[i].firstName << endl;
		cout << "Surname|" << teachers[i].lastName << endl;
		cout << "Email  |" << teachers[i].email << endl;
	}

}

void TEACHER_SERVICE::editFirstName(int id, const char* teacherName)
{
	TEACHER teacher;

	teachersFile.seekg(0, ios::beg);

	while (!teachersFile.eof())
	{
		teachersFile.read((byte*)&teacher, sizeof(TEACHER));

		if (teacher.id == id)
		{
			int res = strcpy_s(teacher.firstName, sizeof(teacher.firstName), teacherName);

			if (res != 0)
			{
				throw exception("Cannot copy strings!");
			}

			teachersFile.seekg(sizeof(TEACHER), ios::cur);
			if (teachersFile.write((byte*)&teacher, sizeof(TEACHER)))
			{
				return;
			}
			else
			{
				throw exception("A wild error appeard!");
			}
		}
	}
	throw exception("Invalid ID");
}

void TEACHER_SERVICE::editLastName(int id, const char* teacherSurname)
{
	TEACHER teacher;

	teachersFile.seekg(0, ios::beg);

	while (!teachersFile.eof())
	{
		teachersFile.read((byte*)&teacher, sizeof(TEACHER));

		if (teacher.id == id)
		{
			int res = strcpy_s(teacher.lastName, sizeof(teacher.lastName), teacherSurname);

			teachersFile.seekg(-132, ios::cur);
			//cout << teachersFile.tellp() << endl;
			if (teachersFile.write((byte*)&teacher, sizeof(TEACHER)))
			{
				return;
			}
			else
			{
				throw exception("A wild error appeard!");
			}

		}


	}
	throw exception("Invalid ID");
	// closeFile();
	//return false;
}



