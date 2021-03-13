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
        {'2', ".Edit teacher", showEditMenuTeacher},
        {'3', ".Delete teacher", deleteTeacherMenu},
        {'4', ".View all teachers", showAllTeacherMenu},
        {'5', ".Return to main menu", showMainMenu}
    };

    return options;
}

void inputFirstName(TEACHER& teacher)
{
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("\nFirst name: ");
        isInputValid = safeCin<const char*>(teacher.firstName);
    }*/
    
    showMessage("First name: ");
    cin >> teacher.firstName;
    cout << endl;
}

void inputLastName(TEACHER& teacher)
{
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("\nLast name: ");
        isInputValid = safeCin<const char*>(teacher.lastName);
    }*/

    showMessage("Last name: ");
    cin >> teacher.lastName;
    cout << endl;
}

void inputEmail(TEACHER& teacher)
{
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("E-mail: ");
        isInputValid = safeCin<const char*>(teacher.email);
    }*/

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

    cout << endl;

    showTeacherMenu();
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

    cout << endl;

    showTeacherMenu();
}

void editFirstNameMenuTeacher(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;
    bool isInputValid = false;

    /*while (!isInputValid) {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nFirst name: ");
        isInputValid = safeCin<const char*>(teacher.firstName);
    }*/
    
    showMessage("\nFirst name: ");
    cin >> teacher.firstName;

    chosen.editFirstName(id, teacher.firstName);

    showMessage("\nThe information was edited successfully.");
}

void editLastNameMenuTeacher(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;
    bool isInputValid = false;

    /*while (!isInputValid) {

       showMessage("\nEnter ID: ");
       isInputValid = safeCin<int>(id);
    }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nLast name: ");
        isInputValid = safeCin<const char*>(teacher.lastName);
    }*/

    showMessage("\nLast name: ");
    cin >> teacher.lastName;

    chosen.editLastName(id, teacher.lastName);

    showMessage("\nThe information was edited successfully.");
}

void editEmailMenuTeacher(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;
    bool isInputValid = false;

    /*while (!isInputValid) {

       showMessage("\nEnter ID: ");
       isInputValid = safeCin<int>(id);
    }*/

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nE-mail: ");
        isInputValid = safeCin<const char*>(teacher.email);
    }*/

    showMessage("\nE-mail: ");
    cin >> teacher.email;

    chosen.editEmail(id, teacher.email);

    showMessage("\nThe information was edited successfully.");
}

void deleteTeacherMenu()
{
    TEACHER_SERVICE chosen;
    int id;
    bool isInputValid = false;

    showMessage("\nChoose a teacher to delete");

    showMessage("\nEnter ID: ");
    cin >> id;

    /*while (!isInputValid) {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }*/

    chosen.removeTc(id);

    showMessage("\nThe teacher was removed successfully.");

    cout << endl;

    showTeacherMenu();
}

void showAllTeacherMenu()
{
    TEACHER::showAll();
    cout << endl;
    showTeacherMenu();
}