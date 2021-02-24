#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "define.h"

struct STUDENT
{
	int id = 0;
	char firstName[MAX_CHAR_ARRAY_LENGTH]{};
	char lastName[MAX_CHAR_ARRAY_LENGTH]{};
	char studentClass[MAX_ST_CLASS_LENGTH];
	char email[MAX_CHAR_ARRAY_LENGTH]{};

	std::fstream studentsFile;

	bool open();
	void close();
	bool add();
	uint32_t generateId();
	void showAll();
	std::string toString(STUDENT&);

	
};
