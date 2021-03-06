#include <iostream>
#include "presentationStudent.h"
#include "Presentation.h"

using namespace std;

vector<MENU_OPTION> initializeStudentMenuOptions()
{
    vector<MENU_OPTION> mainMenu =
    {
        {'1', ".Add student", showStudentAddMenu},
        {'2', ".Edit student", showEditMenu},
        {'3', ".Delete student", deleteStudentMenu}
        //{'4', ".View all students", /*func*/},
    };

    return mainMenu;
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

    vector<MENU_OPTION_INT> options = initializeEditMenuOptions();

    showMenuOptionsInt(options);

    handleUserChoiceInt(options);
}

vector<MENU_OPTION_INT> initializeEditMenuOptions()
{
    vector<MENU_OPTION_INT> options =
    {
        {'1', ".First name", editFirstNameMenu},
        {'2', ".Last name", editLastNameMenu},
        {'3', ".Class", editStudentClassMenu},
        {'4', ".E-mail", editStudentEmailMenu},
    };

    return options;
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

void editLastNameMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nLast name: ");
    cin >> student.lastName;

    chosen.editLastName(id, student.lastName);

    showMessage("\nThe information was edited successfully.");
}

void editStudentClassMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nClass: ");
    cin >> student.studentClass;

    chosen.editClass(id, student.studentClass);

    showMessage("\nThe information was edited successfully.");
}

void editStudentEmailMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;

    showMessage("\nEnter ID: ");
    cin >> id;

    showMessage("\nE-mail: ");
    cin >> student.email;

    chosen.editEmail(id, student.email);

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

void deleteStudentMenu()
{
    STUDENT_SERVICE chosen;
    int id;

    showMessage("\nChoose a student to delete: ");

    showMessage("\nEnter ID: ");
    cin >> id;

    chosen.removeSt(id);

    showMessage("\nThe student was removed successfully.");
}