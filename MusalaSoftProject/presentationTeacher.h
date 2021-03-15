#pragma once
#include "students.h"
#include "Presentation.h"
#include "teachers.h"

std::vector<MENU_OPTION> initializeTeacherMenuOptions();

void inputFirstName(TEACHER&);

void inputLastName(TEACHER&);

void inputEmail(TEACHER&);

void showTeacherMenu();

void showAddTeacherMenu();

std::vector<MENU_OPTION_INT> initializeTeacherEditMenuOptions();

void editTeacherFirstNameMenu(int&);

void showEditTeacherMenu();

void editTeacherLastNameMenu(int&);

void editTeacherEmailMenu(int&);

void deleteTeacherMenu();

void showAllTeachersMenu();