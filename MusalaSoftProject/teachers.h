#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "define.h"

extern std::fstream teachersFile;

// For storing teacher data
#pragma pack(1)
struct TEACHER
{
	int id = 0;
	char firstName[MAX_CHAR_ARRAY_LENGTH]{};
	char lastName[MAX_CHAR_ARRAY_LENGTH]{};
	char email[MAX_CHAR_ARRAY_LENGTH]{};

	std::string toString(TEACHER&);
	static void showAll();
};

// Methods used for working with elements of struct TEACHER type
struct TEACHER_SERVICE
{
	static bool open(const char* fileName = "teachers.txt");
	static void close();
	static bool add(TEACHER student);
	static uint32_t generateId();
	static std::vector <TEACHER> getAll();
	static void editFirstName(int, const char*);
	static void editLastName(int, const char*);
	static void editEmail(int, const char*);
	static void softDeleteTeacher(int);
};

TEACHER findTeacherById(const std::vector<TEACHER>& teachers, int id);



