#include <iostream>
#include <string>
#include "presentationTeam.h"
#include "Presentation.h"

using namespace std;

vector<MENU_OPTION> initializeTeamMenuOptions()
{
	vector<MENU_OPTION> options =
	{
		{1, ".Add team", showAddTeamMenu},
		{2, ".Edit team", showEditTeamMenu},
		{3, ".Add Participant", showAddParticipantMenu},
		{4, ".View all teams", showAllTeamsMenu},
		{5, ".Return to main menu", showMainMenu}
	};

	return options;
}

void showAddTeamMenu()
{
	TEAM team;

	inputTeamName(team);

	inputTeamDescription(team);

	chooseTeacher(team);

	chooseTeamStatus(team);

	TEAM_SERVICE::add(team);

	showMessage("The team is successfully registered in the system.\n");

	cout << endl;
	showTeamsMenu();
}

void inputTeamName(TEAM& team)
{
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		showMessage("\nTeam name: ");
		string teamNameStr;
		isInputValid = safeCin<string>(teamNameStr);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_TEAMNAME_MESSAGE;
		}
		strcpy_s(team.name, teamNameStr.c_str());
	}

	cout << endl;
}

void inputTeamDescription(TEAM& team)
{
	showMessage("\nTeam description: ");
	string descr;

	cin.ignore();
	getline(cin, descr);

	strcpy_s(team.description, descr.c_str());
	cout << endl;
}

void chooseTeacher(TEAM& team)
{
	int id;
	TEACHER::showAll();
	showMessage("\nPlease choose a teacher as a mentor for the team\n");

	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		showMessage("\nEnter ID: ");
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_ID_MESSAGE;
		}
	}

	team.teacherId = id;
	cout << endl;
}

void chooseTeamStatus(TEAM& team)
{
	vector<MENU_OPTION_STATUS> menu = initializeTeamStatusMenuOptions();

	showMessage("\nPlease choose a status for the team\n\n");

	showMenuOptionsStatus(menu);
	handleUserChoiceStatus(menu, team);
}

vector<MENU_OPTION_STATUS> initializeTeamStatusMenuOptions()
{
	vector<MENU_OPTION_STATUS> menu =
	{
		{1, ".Active", setTeamStatusToActive},
		{2, ".Not active", setTeamStatusToInactive},
		{3, ".Archived", setTeamStatusToArchived}
	};

	return menu;
}

void showMenuOptionsStatus(vector<MENU_OPTION_STATUS>& options)
{
	for (size_t i = 0; i < options.size(); i++)
	{
		cout << options.at(i).number;
		cout << options.at(i).text;
		cout << endl;
	}
}

void handleUserChoiceStatus(vector<MENU_OPTION_STATUS>& options, TEAM& teams)
{
	int choice;
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		setColor(WHITE);
		cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			setColor(RED);
			cout << INVALID_MENU_OPTION_MESSAGE;
		}
	}

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(teams);
		}
	}
}

void setTeamStatusToActive(TEAM& team)
{
	team.status = TEAM_STATUS::IN_USE;
}

void setTeamStatusToInactive(TEAM& team)
{
	team.status = TEAM_STATUS::NOT_ACTIVE;
}

void setTeamStatusToArchived(TEAM& team)
{
	team.status = TEAM_STATUS::ARCHIVED;
}

void showAllTeamsMenu()
{
	try
	{
		showAllTeams();
		showTeamsMenu();
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
}

vector<MENU_OPTION_INT> initializeTeamEditMenuOptions()
{
	vector<MENU_OPTION_INT> options =
	{
	   {1, ". Participant", editTeamParticipantMenu},
	   {2, ". Teacher",editTeamTeacherMenu },
	   {3, ". Description ", editTeamDescriptionMenu},
	   {4, ". Status ", editTeamStatusMenu}
	};

	return options;
}

void editTeamParticipantMenu(int& id)
{
	PARTICIPANT participant;
	PARTICIPANT_SERVICE chosen;
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		showAllTeams();
		showMessage("\nEnter Team ID: ");
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_ID_MESSAGE;
		}
	}

	isInputValid = false;

	int studentId;
	while (!isInputValid)
	{
		system("cls");
		setColor(WHITE);
		showTeamById(id);
		showMessage("\nStudent ID: ");
		isInputValid = safeCin<int>(studentId);

		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
	}

	isInputValid = false;
	int newStudentId;
	while (!isInputValid)
	{
		system("cls");
		setColor(WHITE);
		STUDENT::showAll();
		showMessage("\nNew student ID: ");
		isInputValid = safeCin<int>(newStudentId);

		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
	}

	try
	{
		chosen.editParticipantInTeam(id, studentId, newStudentId);
		cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	showTeamsMenu();
}

void editTeamTeacherMenu(int& id)
{
	TEAM team;
	TEAM_SERVICE chosen;
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		showAllTeams();
		showMessage("\nEnter team ID: ");
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_ID_MESSAGE;
		}
	}

	isInputValid = false;
	int newTeacherId;
	while (!isInputValid)
	{
		setColor(WHITE);
		system("cls");
		TEACHER::showAll();
		showMessage("\nNew teacher ID: ");
		isInputValid = safeCin<int>(newTeacherId);

		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
	}

	try
	{
		chosen.editTeacher(id,  newTeacherId);
		cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	showTeamsMenu();
}

void editTeamDescriptionMenu(int& id)
{
	TEAM team;
	TEAM_SERVICE chosen;
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		showAllTeams();
		showMessage("\nEnter team ID: ");
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_ID_MESSAGE;
		}
	}

	isInputValid = false;
	string description;
	while (!isInputValid)
	{
		setColor(WHITE);
		showMessage("\nNew description: ");
		cin.ignore();
		getline(cin, description);
		isInputValid = true;
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
	}

	try
	{
		chosen.editDescription(id, description);
		cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	showTeamsMenu();
}

void setEditedStatus(int choice, TEAM_STATUS& status)
{
	switch (choice)
	{
	case 1:
		status = TEAM_STATUS::IN_USE;
		break;
	case 2:
		status = TEAM_STATUS::NOT_ACTIVE;
		break;
	case 3:
		status = TEAM_STATUS::ARCHIVED;
		break;
	}
}

void editTeamStatusMenu(int& id)
{
	TEAM team;
	TEAM_SERVICE chosen;
	bool isInputValid = false;


	while (!isInputValid)
	{
		setColor(WHITE);
		showAllTeams();
		showMessage("\nEnter team ID: ");
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_ID_MESSAGE;
		}
	}

	isInputValid = false;
	cout << "1.In Use" << endl;
	cout << "2.Not Active" << endl;
	cout << "3.Archived" << endl;
	int choice;

	TEAM_STATUS status;

	while (!isInputValid)
	{
		setColor(WHITE);
		showMessage("\nChoose status: ");
		cin.ignore();
		isInputValid = safeCin<int>(choice);
		isInputValid = true;
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
		else
		{
			setEditedStatus(choice, status);
		}
	}

	try
	{
		chosen.editStatus(id, status);
		cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	showTeamsMenu();
}


void setRole(int choice, ROLES& status)
{
	switch (choice)
	{
	case 1:
		status = ROLES::SCRUM_MASTER;
		break;
	case 2:
		status = ROLES::BACK_END;
		break;
	case 3:
		status = ROLES::FRONT_END;
		break;
	case 4:
		status = ROLES::QA;
		break;
	}
}


void inputTeamId(PARTICIPANT& participant)
{
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		system("cls");
		showAllTeams();
		showMessage("\nTeam ID: ");
		int id;
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
		
		participant.teamId = id;
	}

	cout << endl;
}

void inputStudentId(PARTICIPANT& participant)
{
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		system("cls");
		STUDENT::showAll();
		showMessage("\nStudnet ID: ");
		int id;
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}

		participant.studentId = id;
	}

	cout << endl;
}

void inputRole(PARTICIPANT& participant)
{
	bool isInputValid = false;

	while (!isInputValid)
	{
		setColor(WHITE);
		system("cls");

		cout << "1. Scrum Master" << endl;
		cout << "2. Back-End" << endl;
		cout << "3. Front-End" << endl;
		cout << "4. QA" << endl;
		cout << "Choose Role: ";
		int choice;

		ROLES role;
		isInputValid = safeCin<int>(choice);

		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
			continue;
		}

		setRole(choice, role);
		participant.role = role;
		
	}

	cout << endl;
}


void showAddParticipantMenu()
{
	system("cls");

	addParticipantMenuHeading();

	PARTICIPANT participant;

	inputTeamId(participant);
	inputStudentId(participant);
	inputRole(participant);

	try
	{
		PARTICIPANT_SERVICE::add(participant);
		showMessage("The team was successfully registered in the tem.\n");
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	showTeamsMenu();
}

void showEditTeamMenu()
{
	int id = 0;
	PARTICIPANT participant;

	cout << "\nChoose what you want to edit\n\n";

	vector<MENU_OPTION_INT> options = initializeTeamEditMenuOptions();

	showMenuOptionsInt(options);

	handleUserChoiceInt(options);

	cout << endl;

	showTeamsMenu();
}