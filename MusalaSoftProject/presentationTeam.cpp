#include <iostream>
#include "presentationTeam.h"
#include "Presentation.h"

using namespace std;

vector<MENU_OPTION> initializeTeamMenuOptions()
{
	vector<MENU_OPTION> options =
	{
		{'1', ".Add team", showAddTeamMenu},
		{'2', ".Edit team", showEditTeamMenu},
		{'3', ".Delete team", /*func*/},
		{'4', ".View all teams", showAllTeamsMenu},
		{'5', ".Return to main menu", showMainMenu}
	};

	return options;
}

/*vector<MENU_OPTION_INT> initializeTeamEditMenuOptions()
{
	vector<MENU_OPTION_INT> options =
	{
		{'1', ".First name", editFirstNameMenu},
		{'2', ".Last name", editLastNameMenu},
		{'3', ".Class", editStudentClassMenu},
		{'4', ".E-mail", editStudentEmailMenu},
		{'5', ".Return to student menu", returnToStudentMenu}
	};

	return options;
}*/

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

	/*while (!isInputValid) {

		showMessage("\nTeam name: ");
		isInputValid = safeCin<const char*>(team.name);
	}*/

	showMessage("\nName: ");
	cin >> team.name;
	cout << endl;
}

/*void returnToTeamMenu(int&)
{

}*/

/*void showAllTeamsMenu()
{
	TEAM::showAll();
	cout << endl;
	showStudentMenu();
}*/

void inputTeamDescription(TEAM& team)
{
	bool isInputValid = false;

	/*while (!isInputValid) {

		showMessage("\nTeam name: ");
		isInputValid = safeCin<const char*>(team.description);
	}*/

	showMessage("\nTeam description: ");
	cin >> team.description;
	cout << endl;
}

void chooseTeacher(TEAM& team)
{
	int id;
	TEACHER::showAll();
	showMessage("\nPlease choose a teacher as a mentor for the team\n");

	showMessage("\nEnter ID: ");
	cin >> id;
	cout << endl;
}

/*TEACHER chooseTeacherMenu(int& id)
{
	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (id == teachers.at(i).id)
		{
			return teachers.at(i);
		}
	}

}*/

void chooseTeamStatus(TEAM& team)
{
	vector<MENU_OPTION_STATUS> menu = initializeTeamStatusMenuOptions();

	showMessage("\nPlease choose a status for the team\n\n");

	showMenuOptionsStatus(menu);
	handleUserChoiceStatus(menu);
}

vector<MENU_OPTION_STATUS> initializeTeamStatusMenuOptions()
{
	vector<MENU_OPTION_STATUS> menu =
	{
		{'1', ".Active", setTeamStatusToActive},
		{'2', ".Not active", setTeamStatusToInactive},
		{'3', ".Archived", setTeamStatusToArchived}
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

void handleUserChoiceStatus(vector<MENU_OPTION_STATUS>& options)
{
	char choice;
	bool isInputValid = false;
	TEAM teams;

	cout << "\nEnter your choice: ";
	cin >> choice;

	/*while (!isInputValid) {

		cout << "Enter your choice: ";
		isInputValid = safeCin<char>(choice);
	}*/

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
	   {'1', ".Edit Participant", editTeamParticipantMenu},
	   {'2', ".Last name",/**/ },
	   {'3', ".E-mail", /**/}
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
		showMessage("\nEnter ID: ");
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
		setColor(WHITE);
		showMessage("\nStudent Id: ");
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
		setColor(WHITE);
		showMessage("\nNew Student Id: ");
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