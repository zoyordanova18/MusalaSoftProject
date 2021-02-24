#include "students.h"
#include <iostream>
#include <fstream>

using namespace std;

bool STUDENT::open()
{
	studentsFile.open("students.txt", ios::ate | ios::binary | ios::in | ios::out);
	return studentsFile.is_open();
}

void STUDENT::close()
{
	studentsFile.close();
}

bool STUDENT::add()
{
	id = generateId();

	studentsFile.seekp(0, ios::end);

	if (studentsFile.write((byte*)this, sizeof(STUDENT)))
	{
		return true;
	}

	return false;
}



uint32_t STUDENT::generateId()
{
	int id = -1;
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (studentsFile)
	{
		if (studentsFile.read((byte*)&student, sizeof(STUDENT)))
		{
			id = student.id;
		}
	}

	if (id == -1 || studentsFile.eof()) {
		studentsFile.clear();
	}

	return ++id;
}

void STUDENT::showAll()
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		if (studentsFile.read((byte*)&student, sizeof(STUDENT)))
		{
			cout << toString(student);
		}
	}

}


string STUDENT::toString(STUDENT& product)
{
	stringstream s;
	s << product.id << " | " << product.firstName << ", " << product.lastName << endl;
	return s.str();
}

