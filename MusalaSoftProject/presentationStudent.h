#pragma once
#include <vector>
#include "students.h"
#include "Presentation.h"

std::vector<MENU_OPTION> initializeStudentMenuOptions();

std::vector<MENU_OPTION_INT> initializeEditMenuOptions();

void showExportToExcelMenu();

void showAddStudentMenu();

void showEditStudentMenu();

void returnToStudentMenu();

void filterByFirstNameMenu();

void showFilterStudentMenu();

void filterByEmailMenu();

void filterByClassMenu();

void filterByLastNameMenu();

void filterByIdMenu();

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

void showFilterStudentMenuHeading();









