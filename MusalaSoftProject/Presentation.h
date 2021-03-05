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