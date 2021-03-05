#include <iostream>
#include "Presentation.h"
#include "students.h"
#include "students.cpp"
#include "teams.h"
#include "teams.cpp"
#include "teachers.h"
#include "teachers.cpp"

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

void mainMenu()
{
    int choice;
    STUDENT student;
    TEAM team;
    TEACHER teacher;

    cout << "1. Add a student" << endl;
    cout << "2. Edit a student" << endl;
    cout << "3. Delete a student" << endl;
    cout << "4. Add a team" << endl;
    cout << "5. Edit a team" << endl;
    cout << "6. Delete a team" << endl;
    cout << "7. Add a teacher" << endl;
    cout << "8. Edit a teacher" << endl;
    cout << "9. Delete a teacher" << endl;
    cout << "10. Exit" << endl;

    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        STUDENT_SERVICE::add(student);
        break;
    case 2:
        editStudentMenu();
        break;
    case 3:
        //b
        break;
    case 4:
        TEAM_SERVICE::add(team);
        break;
    case 5:
        //b
        break;
    case 6:
        //b
        break;
    case 7:
        TEACHER_SERVICE::add(teacher);
        break;
    case 8:
        editTeacherMenu();
        break;
    case 9:
        //b
        break;
    case 10:
        break;
    default:
        break;

    }
}

void editStudentMenu()
{
    int choice, id;
    const char* studentName;
    const char* studentSurname;
    const char* studentEmail;
    const char* studentClass;

    cout << "1. Edit first name" << endl;
    cout << "2. Edit last name" << endl;
    cout << "3. Edit email" << endl;
    cout << "4. Edit class" << endl;

    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        STUDENT_SERVICE::editFirstName(id, studentName);
        break;
    case 2:
        STUDENT_SERVICE::editLastName( id, studentSurname);
        break;
    case 3:
        STUDENT_SERVICE::editEmail(id, studentEmail);
        break;
    case 4:
        STUDENT_SERVICE::editClass(id, studentClass);
        break;
    default:
        break;
    }
}

void editTeacherMenu()
{
    int choice, id;
    const char* teacherName;
    const char* teacherSurname;
    const char* teacherEmail;

    cout << "1. Edit first name" << endl;
    cout << "2. Edit last name" << endl;
    cout << "3. Edit email" << endl;

    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        TEACHER_SERVICE::editFirstName(id, teacherName);
        break;
    case 2:
        TEACHER_SERVICE::editLastName(id, teacherSurname);
        break;
    case 3:
        TEACHER_SERVICE::editEmail(id, teacherEmail);
        break;
    default:
        break;
    }
}