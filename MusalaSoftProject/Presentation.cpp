#include <iostream>
#include <vector>
#include "Presentation.h"
#include "presentationTeacher.h"
#include "students.h"
#include "presentationStudent.h"

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
