#pragma once

#include "students.h"
#include "teachers.h"

//typedef unsigned char byte;
typedef void (*MENU_HANDLER)();
typedef void (*MENU_HANDLER_INT)(int&);

struct MENU_OPTION
{
    char number;
    const char* text;
    MENU_HANDLER handler;
};

struct MENU_OPTION_INT
{
    char number;
    const char* text;
    MENU_HANDLER_INT handler;
};

void showMainMenuHeading();

void showSchoolArt();

void showMessage(const char*);

void showMenuOptions(std::vector<MENU_OPTION>&);

void handleUserChoice(std::vector<MENU_OPTION>&);

std::vector<MENU_OPTION> initializeMainMenuOptions();

std::vector<MENU_OPTION> initializeTeamMenuOptions();

void showMainMenu();

void showStudentMenu();

void showTeamsMenu();

void showMenuOptionsInt(std::vector<MENU_OPTION_INT>&);

void handleUserChoiceInt(std::vector<MENU_OPTION_INT>&);

void showStudentsTableHeader();

void showStudentInTable(STUDENT student);

void showTeachersTableHeader();

void showTeacherInTable(TEACHER teacher);