#pragma once

#include "students.h"

//typedef unsigned char byte;
typedef void (*MENU_HANDLER)();
typedef void (*MENU_HANDLER_STUDENT)(int&);

struct MENU_OPTION
{
    char number;
    const char* text;
    MENU_HANDLER handler;
};

struct MENU_OPTION_STUDENT
{
    char number;
    const char* text;
    MENU_HANDLER_STUDENT handler;
};

void showMainMenuHeading();

void showSchoolArt();

void showMessage(const char*);

void showMenuOptions(std::vector<MENU_OPTION>&);

void handleUserChoice(std::vector<MENU_OPTION>&);

std::vector<MENU_OPTION> initializeMainMenuOptions();

std::vector<MENU_OPTION> initializeStudentMenuOptions();

std::vector<MENU_OPTION> initializeTeamMenuOptions();

std::vector<MENU_OPTION_STUDENT> initializeEditMenuOptions();

void showStudentAddMenu();

void showEditMenu();

void inputFirstName(STUDENT&);

void inputLastName(STUDENT&);

void inputStudentClass(STUDENT&);

void inputEmail(STUDENT&);

void showMainMenu();

void showStudentMenu();

void showTeamsMenu();

void handleUserChoiceStudent(std::vector<MENU_OPTION_STUDENT>&);

void editFirstNameMenu(int&);

void editLastNameMenu(int&);

void editStudentClassMenu(int&);

void editStudentEmailMenu(int&);