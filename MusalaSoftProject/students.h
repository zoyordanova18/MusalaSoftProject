#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "define.h"

extern std::fstream studentsFile;

// For storing student details
#pragma pack(1)
struct STUDENT
{
	int id = 0;
	char firstName[MAX_CHAR_ARRAY_LENGTH]{};
	char lastName[MAX_CHAR_ARRAY_LENGTH]{};
	char studentClass[MAX_ST_CLASS_LENGTH]{};
	char email[MAX_CHAR_ARRAY_LENGTH]{};

	std::string toString(STUDENT&);	
	static void showAll();
};

// Methods used for working with elements of struct STUDENT type
struct STUDENT_SERVICE
{
	static bool open(const char* fileName = "students.txt");
	static void close();
	static bool add(STUDENT student);
	static uint32_t generateId();
	static std::vector <STUDENT> getAll();
	static void editFirstName(int, const char*);
	static void editLastName(int, const char*);
	static void editEmail(int, const char*);
	static void editClass(int, const char*);
	static void softDeleteStudent(int);
};

STUDENT findStudentById(const std::vector<STUDENT>&, int);

bool isStudentDeleted(STUDENT);
