#pragma once
#pragma once
#include <vector>
#include "teams.h"
#include "Presentation.h"

std::vector<MENU_OPTION> initializeTeamMenuOptions();

//std::vector<MENU_OPTION_INT> initializeEditMenuOptions();

void showAddTeamMenu();

//void showEditMenu();

void inputTeamName(TEAM&);

void inputTeamDescription(TEAM&);

//void deleteTeamMenu();

//void returnToTeamMenu(int&);

//void showAllTeamsMenu();

void chooseTeacher(TEAM&);

std::vector<MENU_OPTION_STATUS> initializeTeamStatusMenuOptions();

void activeStatusMenu(TEAM&);

void inactiveStatusMenu(TEAM&);

void chooseTeamStatus(TEAM&);

void archivedStatusMenu(TEAM&);
