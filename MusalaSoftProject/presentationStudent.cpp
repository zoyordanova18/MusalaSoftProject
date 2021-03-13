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
        {'3', ".Delete student", deleteStudentMenu},
        {'4', ".View all students", showAllMenu},
        {'5', ".Return to the main menu", showMainMenu}
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

    cout << endl;
    showStudentMenu();
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

    cout << endl;
    showStudentMenu();
}

void returnToStudentMenu(int& mock)
{
    showStudentMenu();
}

vector<MENU_OPTION_INT> initializeEditMenuOptions()
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
}

void editFirstNameMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid) {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }

    //showMessage("\nEnter ID: ");
   // cin >> id;

    while (!isInputValid) {

        showMessage("\nFirst name: ");
        string nameStr;
        isInputValid = safeCin<string>(nameStr);
        strcpy_s(student.firstName, nameStr.c_str());
    }
    //showMessage("\nFirst name: ");
    //cin >> student.firstName;

    chosen.editFirstName(id, student.firstName);

    showMessage("\nThe information was edited successfully.\n");

    cout << endl;
    showEditMenu();
}

void editLastNameMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    /*while (!isInputValid) {

         showMessage("\nEnter ID: ");
         isInputValid = safeCin<int>(id);
     }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nLast name: ");
        isInputValid = safeCin<const char*>(student.lastName);
    }*/

    showMessage("\nLast name: ");
    cin >> student.lastName;

    chosen.editLastName(id, student.lastName);

    showMessage("\nThe information was edited successfully.\n");

    cout << endl;
    showEditMenu();
}

void editStudentClassMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nClass: ");
        isInputValid = safeCin<const char*>(student.studentClass);
    }*/

    showMessage("\nClass: ");
    cin >> student.studentClass;

    chosen.editClass(id, student.studentClass);

    showMessage("\nThe information was edited successfully.\n");

    cout << endl;
    showEditMenu();
}

void editStudentEmailMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nE-mail: ");
        isInputValid = safeCin<const char*>(student.email);
    }*/

    showMessage("\nE-mail: ");
    cin >> student.email;

    chosen.editEmail(id, student.email);

    showMessage("\nThe information was edited successfully.\n");

    cout << endl;
    showEditMenu();
}

void inputFirstName(STUDENT& student)
{
    bool isInputValid = false;
    
    /*while (!isInputValid) {

        showMessage("\nFirst name: ");
        isInputValid = safeCin<const char*>(student.firstName);
    }*/

    showMessage("First name: ");
    cin >> student.firstName;
    cout << endl;
}

void inputLastName(STUDENT& student)
{
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("Last name: ");
        isInputValid = safeCin<const char*>(student.lastName);
    }*/

    showMessage("Last name: ");
    cin >> student.lastName;
    cout << endl;
}

void inputStudentClass(STUDENT& student)
{
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("Class: ");
        isInputValid = safeCin<const char*>(student.studentClass);
    }*/

    showMessage("Class: ");
    cin >> student.studentClass;
    cout << endl;
}

void inputEmail(STUDENT& student)
{
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("E-mail: ");
        isInputValid = safeCin<const char*>(student.email);
    }*/

    showMessage("E-mail: ");
    cin >> student.email;
    cout << endl;
}

void deleteStudentMenu()
{
    STUDENT_SERVICE chosen;
    bool isInputValid = false;
    int id;

    showMessage("\nChoose a student to delete: ");
    
    /*while (!isInputValid) {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    chosen.removeSt(id);

    showMessage("\nThe student was removed successfully.\n");

    cout << endl;
    showStudentMenu();
}

void showAllMenu()
{
    STUDENT::showAll();
    cout << endl;
    showStudentMenu();
}