#pragma once

#include "students.h"

//typedef unsigned char byte;
typedef void (*MENU_HANDLER)();

void showMainMenuHeading();

void showSchoolArt();

void mainMenu();

void editStudentMenu();

void editTeacherMenu();