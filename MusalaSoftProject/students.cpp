#include "students.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool STUDENT_SERVICE::open()
{
	studentsFile.open("students.txt", ios::ate | ios::binary | ios::in | ios::out);
	return studentsFile.is_open();
}

void STUDENT_SERVICE::close()
{
	studentsFile.close();
}

bool STUDENT_SERVICE::add(STUDENT student)
{
	student.id = generateId();

	studentsFile.seekp(0, ios::end);

	if (studentsFile.write((byte*)&student, sizeof(STUDENT)))
	{
		return true;
	}

	return false;
}

uint32_t STUDENT_SERVICE::generateId()
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

vector<STUDENT> STUDENT_SERVICE::getAll()
{
	STUDENT student;
	vector<STUDENT> students;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		if (studentsFile.read((byte*)&student, sizeof(STUDENT)))
		{
			students.push_back(student);
		}
	}

}

string STUDENT::toString(STUDENT& product)
{
	stringstream s;
	s << product.id << " | " << product.firstName << ", " << product.lastName << endl;
	return s.str();
}

bool STUDENT_SERVICE::editFirstName(int id, const char* itemName)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		studentsFile.read((byte*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.firstName, sizeof(student.firstName), itemName);

			studentsFile.seekg(-132, ios::cur);
			cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte*)&student, sizeof(STUDENT))) {
				cout << "Successfull write";
			}
			return true;
		}


	}

	// closeFile();
	return false;
}

