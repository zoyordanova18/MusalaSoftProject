#pragma once

#include "students.h"
#include "Presentation.h"
#include "teachers.h"

std::vector<MENU_OPTION> initializeTeacherMenuOptions();

void inputFirstName(TEACHER&);

void inputLastName(TEACHER&);

void inputEmail(TEACHER&);

void showTeacherMenu();
