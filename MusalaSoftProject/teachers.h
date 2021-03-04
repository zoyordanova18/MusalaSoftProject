#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "define.h"

extern std::fstream teachersFile;


#pragma pack(1)
struct TEACHER
{
	int id = 0;
	char firstName[MAX_CHAR_ARRAY_LENGTH]{};
	char lastName[MAX_CHAR_ARRAY_LENGTH]{};
	char email[MAX_CHAR_ARRAY_LENGTH]{};

	std::string toString(TEACHER&);
	void showAll();
};

