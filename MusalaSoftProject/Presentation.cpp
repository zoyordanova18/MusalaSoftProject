#include <iostream>
#include <vector>
#include "Presentation.h"
#include "students.h"

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

void showMenuOptionsStudent(vector<MENU_OPTION_STUDENT>& options)
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

    cout << "Enter your choice: ";
    cin >> choice;

    for (size_t i = 0; i < options.size(); i++)
    {
        if (choice == options.at(i).number)
        {
            options.at(i).handler();
        }
    }
}

void handleUserChoiceStudent(vector<MENU_OPTION_STUDENT>& options)
{
    char choice;

    cout << "Enter your choice: ";
    cin >> choice;

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

vector<MENU_OPTION> initializeStudentMenuOptions()
{
    vector<MENU_OPTION> mainMenu =
    {
        {'1', ".Add student", showStudentAddMenu},
        {'2', ".Edit student", showEditMenu}
        //{'3', ".Delete student", /*func*/},
        //{'4', ".View all students", /*func*/},
    };

    return mainMenu;
}

vector<MENU_OPTION> initializeTeacherMenuOptions()
{
    vector<MENU_OPTION> options =
    {
        {'1', ".Add teacher", /*func*/},
        {'2', ".Edit teacher", /*func*/},
        {'3', ".Delete teacher", /*func*/},
        {'4', ".View all teachers", /*func*/},
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

vector<MENU_OPTION_STUDENT> initializeEditMenuOptions()
{
    vector<MENU_OPTION_STUDENT> options =
    {
        {'1', ".First name", editFirstNameMenu},
        //{'2', ".Last name", inputLastName},
       // {'3', ".Class", editClassMenu}
        //{'4', ".E-mail", inputEmail},*/
    };

    return options;
}

void showStudentAddMenu()
{
    STUDENT student;

    inputFirstName(student);

    inputLastName(student);

    inputStudentClass(student);

    inputEmail(student);

    STUDENT_SERVICE::add(student);

    showMessage("The student is successfully registered in the system.\n");
}

void showEditMenu()
{
    int id = 0;
    STUDENT student;

    //cout << "Please choose a student to edit: ";

    //student.showAll();

    cout << "Choose what you want to edit: " << endl;

    vector<MENU_OPTION_STUDENT> options = initializeEditMenuOptions();

    showMenuOptionsStudent(options);

    handleUserChoiceStudent(options);
}

void editFirstNameMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nFirst name: ");
    cin >> student.firstName;

    chosen.editFirstName(id, student.firstName);

    showMessage("\nThe information was edited successfully.");
}


void inputFirstName(STUDENT& student)
{
    showMessage("First name: ");
    cin >> student.firstName;
    cout << endl;
}

void inputLastName(STUDENT& student)
{
    showMessage("Last name: ");
    cin >> student.lastName;
    cout << endl;
}

void inputStudentClass(STUDENT& student)
{
    showMessage("Class: ");
    cin >> student.studentClass;
    cout << endl;
}

void inputEmail(STUDENT& student)
{
    showMessage("E-mail: ");
    cin >> student.email;
    cout << endl;
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

void showTeacherMenu()
{
    vector<MENU_OPTION> menu = initializeTeacherMenuOptions();

    showMenuOptions(menu);
    handleUserChoice(menu);
}

void showTeamsMenu()
{
    vector<MENU_OPTION> menu = initializeTeamMenuOptions();

    showMenuOptions(menu);
    handleUserChoice(menu);
}
