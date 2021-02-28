#include "students.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

std::fstream studentsFile;

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
	//student.id = generateId();

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

	for (size_t i = 0; i < students.size(); i++)
	{
		cout << "Id		|" << students[i].id << endl;
		cout << "Name   |" << students[i].firstName<< endl;
		cout << "Surname|" << students[i].lastName << endl;
		cout << "Class  |" << students[i].studentClass << endl;
		cout << "Email  |" << students[i].email << endl;
	}
	
}

void STUDENT_SERVICE::editFirstName(int id, const char* studentName)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		studentsFile.read((byte*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.firstName, sizeof(student.firstName), studentName);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte*)&student, sizeof(STUDENT))) 
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

void STUDENT_SERVICE::editLastName(int id, const char* studentSurname)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		studentsFile.read((byte*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.lastName, sizeof(student.lastName), studentSurname);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte*)&student, sizeof(STUDENT)))
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
		studentsFile.read((byte*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.email, sizeof(student.email), studentEmail);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte*)&student, sizeof(STUDENT)))
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

void STUDENT_SERVICE::editClass(int id, const char* studentClass)
{
	STUDENT student;

	studentsFile.seekg(0, ios::beg);

	while (!studentsFile.eof())
	{
		studentsFile.read((byte*)&student, sizeof(STUDENT));

		if (student.id == id)
		{
			int res = strcpy_s(student.studentClass, sizeof(student.studentClass), studentClass);

			studentsFile.seekg(-132, ios::cur);
			//cout << studentsFile.tellp() << endl;
			if (studentsFile.write((byte*)&student, sizeof(STUDENT)))
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


