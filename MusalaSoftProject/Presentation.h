#pragma once

#include "students.h"
#include "teachers.h"
#include "helpers.h"
#include "teams.h"

//typedef unsigned char byte;
typedef void (*MENU_HANDLER)();
typedef void (*MENU_HANDLER_INT)(int&);
typedef void (*MENU_HANDLER_STATUS)(TEAM&);

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

struct MENU_OPTION_STATUS
{
    char number;
    const char* text;
    MENU_HANDLER_STATUS handler;
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

void exitProgram();

void showMenuOptionsStatus(std::vector<MENU_OPTION_STATUS>&);

void handleUserChoiceStatus(std::vector<MENU_OPTION_STATUS>&);

void showStudentMenuHeading();
