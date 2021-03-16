#pragma once

#include "students.h"
#include "teachers.h"
#include "helpers.h"
#include "teams.h"
#include "participants.h"

// Pointers to functions for handling menu functions
typedef void (*MENU_HANDLER)();
typedef void (*MENU_HANDLER_INT)(int&);
typedef void (*MENU_HANDLER_STATUS)(TEAM&);

struct MENU_OPTION
{
    int number;
    const char* text;
    MENU_HANDLER handler;
};

struct MENU_OPTION_INT
{
    int number;
    const char* text;
    MENU_HANDLER_INT handler;
};

struct MENU_OPTION_STATUS
{
    int number;
    const char* text;
    MENU_HANDLER_STATUS handler;
};

void showMainMenuHeading();

void showSchoolArt();

void showMessage(const char*);

void showMenuOptions(std::vector<MENU_OPTION>&);

// Calls the function corresponding to the user choice
void handleUserChoice(std::vector<MENU_OPTION>&);

std::vector<MENU_OPTION> initializeMainMenuOptions();

std::vector<MENU_OPTION> initializeTeamMenuOptions();

void showMainMenu();

void showStudentMenu();

void showTeamsMenu();

void showMenuOptionsInt(std::vector<MENU_OPTION_INT>&);

// Calls the function corresponding to the user choice 
void handleUserChoiceInt(std::vector<MENU_OPTION_INT>&);

void showStudentsTableHeader();

void showStudentInTable(STUDENT student);

void showTeachersTableHeader();

void showTeacherInTable(TEACHER teacher);

void exitProgram();

void showMenuOptionsStatus(std::vector<MENU_OPTION_STATUS>&);

void handleUserChoiceStatus(std::vector<MENU_OPTION_STATUS>&);

void showStudentMenuHeading();

void showTeamTableHeader();

void printRowInTeamTable(TEAM team,
                         std::vector<std::string> description,
                         std::vector<std::string> participants);

bool isInputInRange(std::size_t, int);

void showTeacherMenuHeading();

void showTeamsMenuHeading();

void showAddStudentMenuHeading();

void showAddTeacherMenuHeading();

void showAddTeamMenuHeading();

void showEditStudentMenuHeading();

void showEditTeacherMenuHeading();

void showDeleteStudentMenuHeading();

void showDeleteTeacherMenuHeading();

void addParticipantMenuHeading();
