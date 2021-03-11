#include <iostream>
#include <vector>
#include <iomanip>
#include "Presentation.h"
#include "presentationTeacher.h"
#include "students.h"
#include "presentationStudent.h"
#include "helpers.h"

using namespace std;

void showMainMenuHeading()
{
	cout << "  __  __       _                                    " << endl;
	cout << " |  \\/  |     (_)                                   " << endl;
	cout << " | \\  / | __ _ _ _ __    _ __ ___   ___ _ __  _   _ " << endl;
	cout << " | |\\/| |/ _` | | '_ \\  | '_ ` _ \\ / _ \\ '_ \\| | | | " << endl;
	cout << " | |  | | (_| | | | | | | | | | | |  __/ | | | |_| | " << endl;
	cout << " |_|  |_|\\__,_|_|_| |_| |_| |_| |_|\\___|_| |_|\\__,_| " << endl;
}

void showSchoolArt()
{
	cout << "         ___________________________" << endl;
	cout << "        //////////////|\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
	cout << "       '.---------------------------.'" << endl;
	cout << "        |                           |" << endl;
	cout << "        |  [] [] [] [] [] [] [] []  |" << endl;
	cout << "        |                           |" << endl;
	cout << "     _.-.          _ _2_ _          |" << endl;
	cout << "     >   ) ] [] [] ||_|||| [] [] [] |  ,'`\\" << endl;
	cout << "     `.,' _________||___||__________|  \\  <" << endl;
	cout << "      ||   /  _<> _      _    (_)<>\\    ||" << endl;
	cout << "      ''  /<>(_),:/      \\:. <>'  <>\\   ||" << endl;
	cout << "       __::::::::/ _ _ _  \\:::::::::::_" << endl;
	cout << "       __________           ___________" << endl;
	cout << "          ,.::. /           \\  _________" << endl;
	cout << "          `''''/             \\ \\:'-'-'-'-" << endl;
	cout << "         `''''/             \ \ \\:'-'-'-'-" << endl;
}

void showMessage(const char* message)
{
	cout << message;
}

void showMenuOptions(vector<MENU_OPTION>& options)
{
	for (size_t i = 0; i < options.size(); i++)
	{
		cout << options.at(i).number;
		cout << options.at(i).text;
		cout << endl;
	}
}

void handleUserChoice(vector<MENU_OPTION>& options)
{
	char choice;
	bool isInputValid = false;
	
	cin >> choice;

	/*while (!isInputValid) {

		cout << "Enter your choice: ";
		isInputValid = safeCin<char>(choice);
	}*/

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler();
		}
	}
}

vector<MENU_OPTION> initializeMainMenuOptions()
{
	vector<MENU_OPTION> options =
	{
		{'1', ".Students", showStudentMenu},
		{'2', ".Teachers", showTeacherMenu},
		{'3', ".Teams", showTeamsMenu}
	};

	return options;
}

vector<MENU_OPTION> initializeTeamMenuOptions()
{
	vector<MENU_OPTION> options =
	{
		{'1', ".Add team", /*func*/},
		{'2', ".Edit team", /*func*/},
		{'3', ".Delete team", /*func*/},
		{'4', ".View all teams", /*func*/},
	};

	return options;
}

void showMainMenu()
{
	STUDENT student;

	vector <MENU_OPTION> mainMenu = initializeMainMenuOptions();

	showMainMenuHeading();
	showSchoolArt();
	showMenuOptions(mainMenu);
	handleUserChoice(mainMenu);
}

void showStudentMenu()
{
	vector<MENU_OPTION> menu = initializeStudentMenuOptions();

	showMenuOptions(menu);
	handleUserChoice(menu);
}

void showTeamsMenu()
{
	vector<MENU_OPTION> menu = initializeTeamMenuOptions();

	showMenuOptions(menu);
	handleUserChoice(menu);
}

void showMenuOptionsInt(vector<MENU_OPTION_INT>& options)
{
	for (size_t i = 0; i < options.size(); i++)
	{
		cout << options.at(i).number;
		cout << options.at(i).text;
		cout << endl;
	}
}

void handleUserChoiceInt(vector<MENU_OPTION_INT>& options)
{
	char choice;
	bool isInputValid = false;

	cout << "Enter your choice: ";
	cin >> choice;

	/*while (!isInputValid) {

		cout << "Enter your choice: ";
		isInputValid = safeCin<char>(choice);
	}*/

	STUDENT student;
	int c = 0;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(c);
		}
	}
}

void showStudentsTableHeader()
{
	cout << endl;
	string headerLine(86, '-');
	cout << headerLine << endl;
	cout << "| " << setw(5) << left << "Id" << " | ";
	cout << setw(15) << left << "First Name" << " | ";
	cout << setw(15) << left << "Last Name" << " | ";
	cout << setw(5) << left << "Class" << " | ";
	cout << setw(30) << left << "Email" << " | " << endl;
	cout << headerLine << endl;
}

void showStudentInTable(STUDENT student)
{
	cout << "| " << setw(5) << left << student.id << " | ";
	cout << setw(15) << left << student.firstName << " | ";
	cout << setw(15) << left << student.lastName<< " | ";
	cout << setw(5) << left << student.studentClass << " | ";
	cout << setw(30) << left << student.email << " | " << left;
}

void showTeachersTableHeader()
{
	cout << endl;
	string headerLine(78, '-');
	cout << headerLine << endl;
	cout << "| " << setw(5) << left << "Id" << " | ";
	cout << setw(15) << left << "First Name" << " | ";
	cout << setw(15) << left << "Last Name" << " | ";
	cout << setw(30) << left << "Email" << " | " << endl;
	cout << headerLine << endl;
}

void showTeacherInTable(TEACHER teacher)
{
	cout << "| " << setw(5) << left << teacher.id << " | ";
	cout << setw(15) << left << teacher.firstName << " | ";
	cout << setw(15) << left << teacher.lastName << " | ";
	cout << setw(30) << left << teacher.email << " | " << left;
}

