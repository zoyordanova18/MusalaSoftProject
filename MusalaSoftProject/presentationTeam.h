#pragma once
#pragma once
#include <vector>
#include "teams.h"
#include "Presentation.h"


std::vector<MENU_OPTION_STATUS> initializeTeamStatusMenuOptions();

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


std::vector<MENU_OPTION_INT> initializeTeamEditMenuOptions();

void setTeamStatusToActive(TEAM&);

void setTeamStatusToInactive(TEAM&);

void showAllTeamsMenu();

void chooseTeamStatus(TEAM&);

void setTeamStatusToArchived(TEAM&);

void editTeamTeacherMenu(int& id);

void showEditTeamMenu();

void editTeamParticipantMenu(int& id);

void handleUserChoiceStatus(std::vector<MENU_OPTION_STATUS>& options, TEAM& teams);

void editTeamDescriptionMenu(int& id);

void editTeamStatusMenu(int& id);

void setEditedStatus(int choice, TEAM_STATUS& status);

void showAddParticipantMenu(int& id);