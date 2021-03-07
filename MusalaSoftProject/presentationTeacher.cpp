#include <iostream>
#include <vector>
#include "Presentation.h"
#include "students.h"
#include "teachers.h"
#include "presentationTeacher.h"

using namespace std;

vector<MENU_OPTION> initializeTeacherMenuOptions()
{
    vector<MENU_OPTION> options =
    {
        {'1', ".Add teacher", showTeacherAddMenu},
        {'2', ".Edit teacher", showEditMenuTeacher}
        //{'3', ".Delete teacher", /*func*/},
        //{'4', ".View all teachers", /*func*/},
    };

    return options;
}

void inputFirstName(TEACHER& teacher)
{
    showMessage("First name: ");
    cin >> teacher.firstName;
    cout << endl;
}

void inputLastName(TEACHER& teacher)
{
    showMessage("Last name: ");
    cin >> teacher.lastName;
    cout << endl;
}

void inputEmail(TEACHER& teacher)
{
    showMessage("E-mail: ");
    cin >> teacher.email;
    cout << endl;
}

void showTeacherMenu()
{
    vector<MENU_OPTION> menu = initializeTeacherMenuOptions();

    showMenuOptions(menu);
    handleUserChoice(menu);
}

void showTeacherAddMenu()
{
    TEACHER student;

    inputFirstName(student);

    inputLastName(student);

    inputEmail(student);

    TEACHER_SERVICE::add(student);

    showMessage("The student is successfully registered in the system.\n");
}

vector<MENU_OPTION_INT> initializeEditMenuOptionsTeacher()
{
    vector<MENU_OPTION_INT> options =
    {
       {'1', ".First name", editFirstNameMenuTeacher},
       {'2', ".Last name", editLastNameMenuTeacher},
       {'3', ".E-mail", editEmailMenuTeacher}
    };

    return options;
}

void showEditMenuTeacher()
{
    int id = 0;
    TEACHER teacher;

    //cout << "Please choose a student to edit: ";

    //student.showAll();

    cout << "Choose what you want to edit: " << endl;

    vector<MENU_OPTION_INT> options = initializeEditMenuOptionsTeacher();

    showMenuOptionsInt(options);

    handleUserChoiceInt(options);
}

void editFirstNameMenuTeacher(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nFirst name: ");
    cin >> teacher.firstName;

    chosen.editFirstName(id, teacher.firstName);

    showMessage("\nThe information was edited successfully.");
}

void editLastNameMenuTeacher(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nLast name: ");
    cin >> teacher.lastName;

    chosen.editLastName(id, teacher.lastName);

    showMessage("\nThe information was edited successfully.");
}

void editEmailMenuTeacher(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nE-mail: ");
    cin >> teacher.email;

    chosen.editEmail(id, teacher.email);

    showMessage("\nThe information was edited successfully.");
}