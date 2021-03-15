#pragma once
#include <vector>
#include "students.h"
#include "Presentation.h"

std::vector<MENU_OPTION> initializeStudentMenuOptions();

std::vector<MENU_OPTION_INT> initializeEditMenuOptions();

void showAddStudentMenu();

void showEditStudentMenu();

void inputFirstName(STUDENT&);

void inputLastName(STUDENT&);

void inputStudentClass(STUDENT&);

void inputEmail(STUDENT&);

void editFirstNameMenu(int&);

void editLastNameMenu(int&);

void editStudentClassMenu(int&);

void editStudentEmailMenu(int&);

void deleteStudentMenu();

void returnToStudentMenu(int&);

// Calls the function for displaying all students
void showAllMenu();









