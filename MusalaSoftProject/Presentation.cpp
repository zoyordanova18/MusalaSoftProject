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
	string heading = "\r\n"
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

	cout << heading;
}

void showTeacherMenuHeading()
{
	string heading = "\r\n"
		" _____              "
		" _                  "
		"                    "
		"      \r\n"
		"|_   _|             "
		"| |                 "
		"                    "
		"      \r\n"
		"  | | ___  __ _  ___"
		"| |__   ___ _ __   _"
		" __ ___   ___ _ __  "
		"_   _ \r\n"
		"  | |/ _ \\/ _` |/ _"
		"_| \'_ \\ / _ \\ \'_"
		"_| | \'_ ` _ \\ / _ "
		"\\ \'_ \\| | | |\r\n"
		"  | |  __/ (_| | (__"
		"| | | |  __/ |    | "
		"| | | | |  __/ | | |"
		" |_| |\r\n"
		"  \\_/\\___|\\__,_|"
		"\\___|_| |_|\\___|_|"
		"    |_| |_| |_|\\___"
		"|_| |_|\\__,_|\r\n"
		"                    "
		"                    "
		"                    "
		"      \r\n"
		"                    "
		"                    "
		"                    "
		"      \r\n";

	cout << heading;
	
}

void showTeamsMenuHeading()
{
	string heading = "\r\n"
		" _____              "
		"                    "
		"                   "
		"\r\n"
		"|_   _|             "
		"                    "
		"                   "
		"\r\n"
		"  | | ___  __ _ _ __"
		" ___  ___   _ __ ___"
		"   ___ _ __  _   _ "
		"\r\n"
		"  | |/ _ \\/ _` | \'"
		"_ ` _ \\/ __| | \'_ "
		"` _ \\ / _ \\ \'_ \\"
		"| | | |\r\n"
		"  | |  __/ (_| | | |"
		" | | \\__ \\ | | | |"
		" | |  __/ | | | |_| "
		"|\r\n"
		"  \\_/\\___|\\__,_|_"
		"| |_| |_|___/ |_| |_"
		"| |_|\\___|_| |_|\\_"
		"_,_|\r\n"
		"                    "
		"                    "
		"                   "
		"\r\n"
		"                    "
		"                    "
		"                   "
		"\r\n";

	cout << heading;
}

void showAddStudentMenuHeading()
{
	string heading = "\r\n"
		"  ___      _     _  "
		"     _             _"
		"            _       "
		"                    "
		"     \r\n"
		" / _ \\    | |   | |"
		"     | |           |"
		" |          | |     "
		"                    "
		"      \r\n"
		"/ /_\\ \\ __| | __| "
		"|  ___| |_ _   _  __"
		"| | ___ _ __ | |_   "
		"_ __ ___   ___ _ __ "
		" _   _ \r\n"
		"|  _  |/ _` |/ _` | "
		"/ __| __| | | |/ _` "
		"|/ _ \\ \'_ \\| __| "
		"| \'_ ` _ \\ / _ \\ "
		"\'_ \\| | | |\r\n"
		"| | | | (_| | (_| | "
		"\\__ \\ |_| |_| | (_"
		"| |  __/ | | | |_  |"
		" | | | | |  __/ | | "
		"| |_| |\r\n"
		"\\_| |_/\\__,_|\\__,"
		"_| |___/\\__|\\__,_|"
		"\\__,_|\\___|_| |_|"
		"\\__| |_| |_| |_|\\_"
		"__|_| |_|\\__,_|\r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"     \r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"     \r\n";

	cout << heading;
}

void showAddTeacherMenuHeading()
{
	string heading = "\r\n"
		"  ___      _     _  "
		" _                  "
		"_                   "
		"                    "
		"     \r\n"
		" / _ \\    | |   | |"
		" | |                "
		"| |                 "
		"                    "
		"      \r\n"
		"/ /_\\ \\ __| | __| "
		"| | |_ ___  __ _  __"
		"_| |__   ___ _ __   "
		"_ __ ___   ___ _ __ "
		" _   _ \r\n"
		"|  _  |/ _` |/ _` | "
		"| __/ _ \\/ _` |/ __"
		"| \'_ \\ / _ \\ \'__"
		"| | \'_ ` _ \\ / _ "
		"\\ \'_ \\| | | |\r\n"
		"| | | | (_| | (_| | "
		"| ||  __/ (_| | (__|"
		" | | |  __/ |    | |"
		" | | | |  __/ | | | "
		"|_| |\r\n"
		"\\_| |_/\\__,_|\\__,"
		"_|  \\__\\___|\\__,_"
		"|\\___|_| |_|\\___|_"
		"|    |_| |_| |_|\\__"
		"_|_| |_|\\__,_|\r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"     \r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"     \r\n";

	cout << heading;
}

void showAddTeamMenuHeading()
{
	string heading = "\r\n"
		"  ___      _     _  "
		" _                  "
		"_                   "
		"                    "
		"     \r\n"
		" / _ \\    | |   | |"
		" | |                "
		"| |                 "
		"                    "
		"      \r\n"
		"/ /_\\ \\ __| | __| "
		"| | |_ ___  __ _  __"
		"_| |__   ___ _ __   "
		"_ __ ___   ___ _ __ "
		" _   _ \r\n"
		"|  _  |/ _` |/ _` | "
		"| __/ _ \\/ _` |/ __"
		"| \'_ \\ / _ \\ \'__"
		"| | \'_ ` _ \\ / _ "
		"\\ \'_ \\| | | |\r\n"
		"| | | | (_| | (_| | "
		"| ||  __/ (_| | (__|"
		" | | |  __/ |    | |"
		" | | | |  __/ | | | "
		"|_| |\r\n"
		"\\_| |_/\\__,_|\\__,"
		"_|  \\__\\___|\\__,_"
		"|\\___|_| |_|\\___|_"
		"|    |_| |_| |_|\\__"
		"_|_| |_|\\__,_|\r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"     \r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"     \r\n";

	cout << heading;
}

void showEditStudentMenuHeading()
{
	string heading = "\r\n"
		" _____    _ _ _     "
		"    _             _ "
		"           _        "
		"                    "
		"    \r\n"
		"|  ___|  | (_) |    "
		"   | |           | |"
		"          | |       "
		"                    "
		"    \r\n"
		"| |__  __| |_| |_   "
		"___| |_ _   _  __| |"
		" ___ _ __ | |_   _ _"
		"_ ___   ___ _ __  _ "
		"  _ \r\n"
		"|  __|/ _` | | __| /"
		" __| __| | | |/ _` |"
		"/ _ \\ \'_ \\| __| |"
		" \'_ ` _ \\ / _ \\ "
		"\'_ \\| | | |\r\n"
		"| |__| (_| | | |_  "
		"\\__ \\ |_| |_| | (_"
		"| |  __/ | | | |_  |"
		" | | | | |  __/ | | "
		"| |_| |\r\n"
		"\\____/\\__,_|_|\\__"
		"| |___/\\__|\\__,_|"
		"\\__,_|\\___|_| |_|"
		"\\__| |_| |_| |_|\\_"
		"__|_| |_|\\__,_|\r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"    \r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"    \r\n";

	cout << heading;
}

void showEditTeacherMenuHeading()
{
	string heading = " _____    _ _ _     "
		"    _             _ "
		"           _        "
		"                    "
		"    \r\n"
		"|  ___|  | (_) |    "
		"   | |           | |"
		"          | |       "
		"                    "
		"    \r\n"
		"| |__  __| |_| |_   "
		"___| |_ _   _  __| |"
		" ___ _ __ | |_   _ _"
		"_ ___   ___ _ __  _ "
		"  _ \r\n"
		"|  __|/ _` | | __| /"
		" __| __| | | |/ _` |"
		"/ _ \\ \'_ \\| __| |"
		" \'_ ` _ \\ / _ \\ "
		"\'_ \\| | | |\r\n"
		"| |__| (_| | | |_  "
		"\\__ \\ |_| |_| | (_"
		"| |  __/ | | | |_  |"
		" | | | | |  __/ | | "
		"| |_| |\r\n"
		"\\____/\\__,_|_|\\__"
		"| |___/\\__|\\__,_|"
		"\\__,_|\\___|_| |_|"
		"\\__| |_| |_| |_|\\_"
		"__|_| |_|\\__,_|\r\n"
		" ";

	cout << heading;
}

void showDeleteStudentMenuHeading()
{
	string heading = "______     _      _ "
		"            _       "
		"      _            _"
		"                    "
		"            \r\n"
		"|  _  \\   | |    | "
		"|           | |     "
		"      | |          |"
		" |                  "
		"             \r\n"
		"| | | |___| | ___| |"
		"_ ___   ___| |_ _   "
		"_  __| | ___ _ __ | "
		"|_   _ __ ___   ___ "
		"_ __  _   _ \r\n"
		"| | | / _ \\ |/ _ \\"
		" __/ _ \\ / __| __| "
		"| | |/ _` |/ _ \\ \'"
		"_ \\| __| | \'_ ` _ "
		"\\ / _ \\ \'_ \\| | "
		"| |\r\n"
		"| |/ /  __/ |  __/ |"
		"|  __/ \\__ \\ |_| |"
		"_| | (_| |  __/ | | "
		"| |_  | | | | | |  _"
		"_/ | | | |_| |\r\n"
		"|___/ \\___|_|\\___|"
		"\\__\\___| |___/\\__"
		"|\\__,_|\\__,_|\\___"
		"|_| |_|\\__| |_| |_|"
		" |_|\\___|_| |_|\\__"
		",_|                 "
		"                    "
		"                    "
		"     ";

	cout << heading;
}

void showDeleteTeacherMenuHeading()
{
	string heading = "\r\n"
		"______     _      _ "
		"        _           "
		"       _            "
		"                    "
		"            \r\n"
		"|  _  \\   | |    | "
		"|       | |         "
		"       | |          "
		"                    "
		"             \r\n"
		"| | | |___| | ___| |"
		"_ ___  | |_ ___  __ "
		"_  ___| |__   ___ _ "
		"__   _ __ ___   ___ "
		"_ __  _   _ \r\n"
		"| | | / _ \\ |/ _ \\"
		" __/ _ \\ | __/ _ \\"
		"/ _` |/ __| \'_ \\ /"
		" _ \\ \'__| | \'_ ` "
		"_ \\ / _ \\ \'_ \\| "
		"| | |\r\n"
		"| |/ /  __/ |  __/ |"
		"|  __/ | ||  __/ (_|"
		" | (__| | | |  __/ |"
		"    | | | | | |  __/"
		" | | | |_| |\r\n"
		"|___/ \\___|_|\\___|"
		"\\__\\___|  \\__\\__"
		"_|\\__,_|\\___|_| |_"
		"|\\___|_|    |_| |_|"
		" |_|\\___|_| |_|\\__"
		",_|";

	cout << heading;
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

	for(size_t i = 0; i < options.size(); i++)
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
		{1, ".Students", showStudentMenu},
		{2, ".Teachers", showTeacherMenu},
		{3, ".Teams", showTeamsMenu},
		{4, ".Exit", exitProgram}
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
	showTeamsMenuHeading();

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

