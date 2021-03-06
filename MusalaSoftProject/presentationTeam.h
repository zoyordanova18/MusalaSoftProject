#pragma once
#pragma once
#include <vector>
#include "teams.h"
#include "Presentation.h"
std::vector<MENU_OPTION_STATUS> initializeTeamStatusMenuOptions();

std::vector<MENU_OPTION> initializeTeamMenuOptions();

void filterByIdTeamMenu();

void filterByNameTeamMenu();

void showFilterTeamMenu();

void filterByTeacherTeamMenu();

std::vector<MENU_OPTION> initializeFilterTeamMenuOptions();

void showAddTeamMenu();

void inputTeamName(TEAM&);

void inputTeamDescription(TEAM&);

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

void inputTeamId(PARTICIPANT& participant);

void inputStudentId(PARTICIPANT& participant);

void inputRole(PARTICIPANT& participant);

void showAddParticipantMenu();

void showFilterTeamMenuHeading();