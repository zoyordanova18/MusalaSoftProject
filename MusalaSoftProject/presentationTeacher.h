#pragma once
#include "students.h"
#include "Presentation.h"
#include "teachers.h"

std::vector<MENU_OPTION> initializeTeacherMenuOptions();

void inputFirstName(TEACHER&);

std::vector<MENU_OPTION> initializeFilterTeacherMenuOptions();

void filterByIdTeacherMenu();

void showFilterTeacherMenu();

void inputLastName(TEACHER&);

void inputEmail(TEACHER&);

void showTeacherMenu();

void showAddTeacherMenu();

void showEditTeacherMenu();

void editTeacherFirstNameMenu(int&);

void editTeacherLastNameMenu(int&);

void editTeacherEmailMenu(int&);

void deleteTeacherMenu();

void showAllTeachersMenu();
