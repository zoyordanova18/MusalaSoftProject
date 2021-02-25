#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "define.h"

#pragma pack(1)
struct STUDENT
{
	int id = 0;
	char firstName[MAX_CHAR_ARRAY_LENGTH]{};
	char lastName[MAX_CHAR_ARRAY_LENGTH]{};
	char studentClass[MAX_ST_CLASS_LENGTH];
	char email[MAX_CHAR_ARRAY_LENGTH]{};

	std::string toString(STUDENT&);


};

struct STUDENT_SERVICE
{
	std::fstream studentsFile;

	bool open();
	void close();
	bool add(STUDENT student);
	uint32_t generateId();
	std::vector <STUDENT> getAll();
	bool editFirstName(int, const char*);
};
