#include "students.h"
#include "presentation.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

fstream studentsFile;

bool STUDENT_SERVICE::open(const char* fileName)
{
	studentsFile.open(fileName, ios::in | ios::out | ios::_Nocreate);

	if (studentsFile.is_open() == false)
	{
		studentsFile.open(fileName, ios::out);
	}
	
	studentsFile.close();

	studentsFile.open(fileName, ios::ate | ios::binary | ios::in | ios::out);
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

	int a = studentsFile.tellg();

	if (studentsFile.write((byte_*)&student, sizeof(STUDENT)))
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
		if (studentsFile.read((byte_*)&student, sizeof(STUDENT)))
		{
			id = student.id;
		}
	}

	if (id == -1 || studentsFile.eof()) {
		studentsFile.clear();
	}

	id++;

	return id;
}

vector<STUDENT> STUDENT_SERVICE::getAll()
{
	STUDENT student;
	vector<STUDENT> students;

	studentsFile.seekg(0, ios::end);
	streampos fileSize = studentsFile.tellg();
	size_t fs = fileSize;
	studentsFile.seekg(0, ios::beg);
	int fov = studentsFile.tellg();

	//while (!studentsFile.eof())
	while (studentsFile.tellg() < fileSize)
	{
		if (studentsFile.read((byte_*)&student, sizeof(STUDENT)))
		{
			students.push_back(student);
		}
		else
		{
			throw("A wild error appeard!");
		}
	}

	//studentsFile.clear();

	return students;
}

string STUDENT::toString(STUDENT& product)
{
	stringstream s;
	s << product.id << " | " << product.firstName << ", " << product.lastName << endl;
	return s.str();
}

void STUDENT::showAll()
{
	vector<STUDENT> students = STUDENT_SERVICE::getAll();

	showStudentsTableHeader();
	for (size_t i = 0; i < students.size(); i++)
	{
		showStudentInTable(students[i]);
		cout << endl;
	}
}

void STUDENT_SERVICE::editFirstName(int id, const char* studentName)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	int a = studentsFile.tellg();

	while (!studentsFile.eof())
	{
		studentsFile.read((byte_*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.firstName, sizeof(student.firstName), studentName);

			if (res != 0)
			{
				throw exception("Cannot copy strings!");
			}

			studentsFile.seekg(-132, ios::cur);
			if (studentsFile.write((byte_*)&student, sizeof(STUDENT)))
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

void STUDENT_SERVICE::editLastName(int id, const char* studentSurname)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);
	bool bb = studentsFile.bad();
	bool fb = studentsFile.fail();

	int tellg = studentsFile.tellg();

	while (!studentsFile.eof())
	{
		studentsFile.read((byte_*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.lastName, sizeof(student.lastName), studentSurname);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte_*)&student, sizeof(STUDENT)))
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

void STUDENT_SERVICE::editEmail(int id, const char* studentEmail)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		studentsFile.read((byte_*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.email, sizeof(student.email), studentEmail);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte_*)&student, sizeof(STUDENT)))
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

void STUDENT_SERVICE::editClass(int id, const char* studentClass)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		studentsFile.read((byte_*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.studentClass, sizeof(student.studentClass), studentClass);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte_*)&student, sizeof(STUDENT)))
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

void STUDENT_SERVICE::softDeleteStudent(int id)
{
	vector<STUDENT> students = getAll();
	STUDENT student = findStudentById(students, id);

	string vanishedLastName = student.lastName;
	vanishedLastName += "!";

	editLastName(id, vanishedLastName.c_str());
}

STUDENT findStudentById(const vector<STUDENT>& students, int id)
{
	STUDENT noStudentFound = { -3, "No students found" };

	if (students.size() != 0)
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			if (id == students[i].id)
			{
				return students[i];
			}
		}
	}

	return noStudentFound;
}

bool isStudentDeleted(STUDENT student)
{
	string studentStr = student.lastName;
	if (studentStr.find('!') != string::npos)
	{
		return false;
	}

	return true;
}


