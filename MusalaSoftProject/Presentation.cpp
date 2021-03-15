#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "Presentation.h"
#include "presentationTeacher.h"
#include "students.h"
#include "presentationStudent.h"
#include "helpers.h"
#include <string_view>
#include "teachers.h"

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

void showStudentMenuHeading()
{
	string str = "\r\n"
		"  ____    _____    _"
		"   _   ____  U _____"
		" u_   _     _____   "
		"     __  __  U _____"
		" u_   _       _   _ "
		" \r\n"
		" / __\"| u|_ \" _|U "
		"|\"|u| | |  _\"\\ \\"
		"| ___\"|/ \\ |\"|   "
		"|_ \" _|     U|\' \\"
		"/ \'|u\\| ___\"|/ \\"
		" |\"|   U |\"|u| | "
		"\r\n"
		"<\\___ \\/   | |   "
		"\\| |\\| |/| | | | |"
		"  _|\"<|  \\| |>    "
		"| |       \\| |\\/| "
		"|/ |  _|\"<|  \\| |>"
		"   \\| |\\| | \r\n"
		" u___) |  /| |\\   |"
		" |_| |U| |_| |\\| |_"
		"__U| |\\  |u   /| |"
		"\\       | |  | |  |"
		" |___U| |\\  |u    |"
		" |_| | \r\n"
		" |____/>>u |_|U  <<"
		"\\___/  |____/ u|___"
		"__||_| \\_|   u |_|U"
		"       |_|  |_|  |__"
		"___||_| \\_|    <<\\"
		"___/  \r\n"
		"  )(  (__)// \\\\_(_"
		"_) )(    |||_   <<  "
		" >>||   \\\\,-._// "
		"\\\\_     <<,-,,-.  "
		" <<   >>||   \\\\,-."
		"(__) )(   \r\n"
		" (__)   (__) (__)   "
		"(__)  (__)_) (__) (_"
		"_|_\")  (_/(__) (__)"
		"     (./  \\.) (__) "
		"(__|_\")  (_/     (_"
		"_)  \r\n";

	cout << str;
}

void showMessage(const char* message)
{
	cout << message;
}

void showMenuOptions(vector<MENU_OPTION>& options)
{
	cout << endl;

	for (size_t i = 0; i < options.size(); i++)
	{
		cout << options.at(i).number;
		cout << options.at(i).text;
		cout << endl;
	}
}

void exitProgram()
{
	showMessage("\nThank you for using out application!\n");
	exit(0);
}

void handleUserChoice(vector<MENU_OPTION>& options)
{
	char choice;
	bool isInputValid = false;

	showMessage("\nEnter your choice: ");
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
		{'3', ".Teams", showTeamsMenu},
		{'4', ".Exit", exitProgram}
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
	showStudentMenuHeading();

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

	showMessage("\nEnter your choice: ");
	cin >> choice;

	/*while (!isInputValid) {

		cout << "Enter your choice: ";
		isInputValid = safeCin<char>(choice);
	}*/

	STUDENT student;
	int mock = 0;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(mock);
		}
	}
}

void showStudentsTableHeader()
{
	cout << endl;
	string headerLine(91, '-');
	cout << headerLine << endl;
	cout << "| " << setw(5) << left << "Id" << " | ";
	cout << setw(15) << left << "First Name" << " | ";
	cout << setw(15) << left << "Last Name" << " | ";
	cout << setw(5) << left << "Class" << " | ";
	cout << setw(35) << left << "Email" << " | " << endl;
	cout << headerLine << endl;
}

void showStudentInTable(STUDENT student)
{
	string lastNameStr = student.lastName;

	if (lastNameStr.find('!') == string::npos)
	{
		cout << "| " << setw(5) << left << student.id << " | ";
		cout << setw(15) << left << student.firstName << " | ";
		cout << setw(15) << left << student.lastName << " | ";
		cout << setw(5) << left << student.studentClass << " | ";
		cout << setw(35) << left << student.email << " | " << left;
	}
	else
	{
		lastNameStr.pop_back();

		cout << "| " << setw(5) << left;
		setColor(RED);
		cout << student.id;
		setColor(WHITE);
		cout << " | ";
		cout << setw(15) << left;
		setColor(RED);
		cout << student.firstName; 
		setColor(WHITE);
		cout << " | ";
		cout << setw(15) << left; 
		setColor(RED);
		cout << lastNameStr; 
		setColor(WHITE);
		cout << " | ";
		cout << setw(5) << left; 
		setColor(RED);
		cout << student.studentClass;
		setColor(WHITE);
		cout << " | ";
		cout << setw(35) << left;
		setColor(RED);
		cout << student.email;
		setColor(WHITE);
		cout << " | " << left;
	}
}

void showTeachersTableHeader()
{
	cout << endl;
	string headerLine(83, '-');
	cout << headerLine << endl;
	cout << "| " << setw(5) << left << "Id" << " | ";
	cout << setw(15) << left << "First Name" << " | ";
	cout << setw(15) << left << "Last Name" << " | ";
	cout << setw(35) << left << "Email" << " | " << endl;
	cout << headerLine << endl;
}

void showTeacherInTable(TEACHER teacher)
{
	string lastNameStr = teacher.lastName;

	if (lastNameStr.find('!') == string::npos)
	{
		cout << "| " << setw(5) << left << teacher.id << " | ";
		cout << setw(15) << left << teacher.firstName << " | ";
		cout << setw(15) << left << teacher.lastName << " | ";
		cout << setw(35) << left << teacher.email << " | " << left;
	}
	else
	{
		lastNameStr.pop_back();

		cout << "| " << setw(5) << left;
		setColor(RED);
		cout << teacher.id;
		setColor(WHITE);
		cout << " | ";
		cout << setw(15) << left;
		setColor(RED);
		cout << teacher.firstName;
		setColor(WHITE);
		cout << " | ";
		cout << setw(15) << left;
		setColor(RED);
		cout << lastNameStr;
		setColor(WHITE);
		cout << setw(3) << left;
		cout << " | ";
		cout << setw(35) << left;
		setColor(RED);
		cout << teacher.email;
		setColor(WHITE);
		cout << " | " << left;
	}

	/*cout << "| " << setw(5) << left << teacher.id << " | ";
	cout << setw(15) << left << teacher.firstName << " | ";
	cout << setw(15) << left << teacher.lastName << " | ";
	cout << setw(30) << left << teacher.email << " | " << left;*/
}

void showTeamTableHeader()
{
	cout << endl;
	string headerLine(150, '-');
	cout << headerLine << endl;
	cout << "| " << setw(5) << left << "Id" << " | ";
	cout << setw(15) << left << "Name" << " | ";
	cout << setw(30) << left << "Description" << " | ";
	cout << setw(35) << left << "Participants" << " | ";
	cout << setw(10) << left << "Date Of Setup" << " | ";
	cout << setw(10) << left << "Status" << " | ";
	cout << setw(20) << left << "Teacher" << " | " << endl;
	cout << headerLine << endl;
}

void printRowInTeamTable(TEAM team,
	vector<string> description,
	vector<string> participants)
{

	string headerLine(150, '-');


	int rowsCount = max(description.size(), participants.size());
	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	string teamStatus = enumStatusToString(team.status);
	string teamId = to_string(team.id);
	string date = team.dateOfSetup;


	removeSpaces(date);

	TEACHER teamTeacher = findTeacherById(teachers, team.teacherId);
	stringstream teacher;
	teacher << teamTeacher.firstName << ' ' << teamTeacher.lastName;

	string teacherName = teacher.str();




	for (int i = 0; i < rowsCount; i++)
	{
		cout << "| " << setw(5) << left << teamId << " | ";
		cout << setw(15) << left << team.name << " | ";
		if (i < description.size())
		{
			cout << setw(30) << left << description[i] << " | ";
		}
		else
		{
			cout << "                               | ";
		}
		if (i < participants.size())
		{
			if (isStringDeleted(participants[i]))
			{
				participants[i].pop_back();
				setColor(RED);
				cout << setw(35) << left << participants[i];
				setColor(WHITE);
				cout << " | ";
			}
			else
			{
				cout << setw(35) << left << participants[i] << " | ";
			}
		}
		else
		{
			cout << "                                | ";
		}
		cout << setw(10) << left << date << "    | ";
		cout << setw(10) << left << teamStatus << " | ";

		if (isStringDeleted(teacherName))
		{
			teacherName.pop_back();
			setColor(RED);
			cout << setw(20) << left << teacherName;
			setColor(WHITE);
			cout << " | " << left << endl;
		}
		else
		{
			cout << setw(20) << left << teacherName <<
				" | " << left << endl;
		}


		teamId = "";
		strcpy_s(team.name, "");
		teamStatus = "";
		date = "";
		teacherName = "";
	}

	cout << headerLine << endl;
}

