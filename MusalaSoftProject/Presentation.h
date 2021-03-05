#pragma once

#include "students.h"

//typedef unsigned char byte;
typedef void (*MENU_HANDLER)();

struct MENU_OPTION
{
    char number;
    const char* text;
    MENU_HANDLER handler;
};

void showMainMenuHeading();

void showSchoolArt();

void showMessage(const char*);

void showMenuOptions(std::vector<MENU_OPTION>&);

void handleUserChoice(std::vector<MENU_OPTION>&);

std::vector<MENU_OPTION> initializeMainMenuOptions();

std::vector<MENU_OPTION> initializeStudentMenuOptions();

std::vector<MENU_OPTION> initializeTeacherMenuOptions();

std::vector<MENU_OPTION> initializeTeamMenuOptions();

std::vector<MENU_OPTION> initializeEditMenuOptions();

void showStudentAddMenu();

void showEditMenu(STUDENT);

void inputFirstName(STUDENT&);

void inputLastName(STUDENT&);

void inputStudentClass(STUDENT&);

void inputEmail(STUDENT&);

void showMainMenu();
