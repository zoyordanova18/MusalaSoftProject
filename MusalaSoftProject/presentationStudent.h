#pragma once
#include <vector>
#include "students.h"

typedef void (*MENU_HANDLER_STUDENT)(int&);

struct MENU_OPTION_STUDENT
{
    char number;
    const char* text;
    MENU_HANDLER_STUDENT handler;
};

std::vector<MENU_OPTION_STUDENT> initializeEditMenuOptions();

void showMenuOptionsStudent(std::vector<MENU_OPTION_STUDENT>&);

void handleUserChoiceStudent(std::vector<MENU_OPTION_STUDENT>&);

void showStudentAddMenu();

void showEditMenu();

void inputFirstName(STUDENT&);

void inputLastName(STUDENT&);

void inputStudentClass(STUDENT&);

void inputEmail(STUDENT&);

void editFirstNameMenu(int&);

void editLastNameMenu(int&);

void editStudentClassMenu(int&);

void editStudentEmailMenu(int&);







