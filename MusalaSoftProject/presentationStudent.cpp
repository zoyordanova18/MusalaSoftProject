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
    system("cls");

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

    showMessage("\nChoose what you want to edit\n\n");

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

    while (!isInputValid) 
    {
        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }

    isInputValid = false;
    while (!isInputValid) 
    {
        showMessage("\nFirst name: ");
        string nameStr;
        isInputValid = safeCin<string>(nameStr);
        strcpy_s(student.firstName, nameStr.c_str());
    }

    try
    {
        chosen.editFirstName(id, student.firstName);

        showMessage("\nThe information was edited successfully.\n");
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

  
    cout << endl;
    showEditMenu();
}

void editLastNameMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid) 
    {
         showMessage("\nEnter ID: ");
         isInputValid = safeCin<int>(id);
    }

    isInputValid = false;
    while (!isInputValid)
    {
        showMessage("\nLast name: ");
        string nameStr;
        isInputValid = safeCin<string>(nameStr);
        strcpy_s(student.lastName, nameStr.c_str());
    }

    try
    {
        chosen.editLastName(id, student.lastName);
        showMessage("\nThe information was edited successfully.\n");
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    cout << endl;
    showEditMenu();
}

void editStudentClassMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid) 
    {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }

    isInputValid = false;
    while (!isInputValid) {

        showMessage("\nClass: ");
        string classStr;
        isInputValid = safeCin<string>(classStr);
        isInputValid = isStudentClassValid(classStr);
        strcpy_s(student.studentClass, classStr.c_str());
    }

    try
    {
        chosen.editClass(id, student.studentClass);

        showMessage("\nThe information was edited successfully.\n");
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    cout << endl;
    showEditMenu();
}

void editStudentEmailMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid) 
    {

        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }

    isInputValid = false;
    while (!isInputValid) 
    {
        showMessage("\nEmail: ");
        string emailStr;
        isInputValid = safeCin<string>(emailStr);
        isInputValid = isEmailValid(emailStr);
        strcpy_s(student.studentClass, emailStr.c_str());
    }

    try
    {
        chosen.editEmail(id, student.email);

        showMessage("\nThe information was edited successfully.\n");
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    cout << endl;
    showEditMenu();
}

void inputFirstName(STUDENT& student)
{
    bool isInputValid = false;
    
    while (!isInputValid) 
    {
        showMessage("\nFirst name: ");
        string nameStr;
        isInputValid = safeCin<string>(nameStr);
        strcpy_s(student.firstName, nameStr.c_str());
    }

    cout << endl;
}

void inputLastName(STUDENT& student)
{
    bool isInputValid = false;

    while (!isInputValid) 
    {
        showMessage("\nLast name: ");
        string nameStr;
        isInputValid = safeCin<string>(nameStr);
        strcpy_s(student.lastName, nameStr.c_str());
    }

    cout << endl;
}

void inputStudentClass(STUDENT& student)
{
    bool isInputValid = false;

    while (!isInputValid) {

        showMessage("\nClass: ");
        string classStr;
        isInputValid = safeCin<string>(classStr);
        isInputValid = isStudentClassValid(classStr);
        strcpy_s(student.studentClass, classStr.c_str());
    }

    cout << endl;
}

void inputEmail(STUDENT& student)
{
    bool isInputValid = false;

    while (!isInputValid)
    {
        showMessage("\nEmail: ");
        string emailStr;
        isInputValid = safeCin<string>(emailStr);
        isInputValid = isEmailValid(emailStr);
        strcpy_s(student.email, emailStr.c_str());
    }

    cout << endl;
}

void deleteStudentMenu()
{
    STUDENT_SERVICE chosen;
    bool isInputValid = false;
    int id;

    showMessage("\nChoose a student to delete: ");
    
    while (!isInputValid) 
    {
        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
    }

    try
    {
        chosen.softDeleteStudent(id);
        showMessage("\nThe student was removed successfully.\n");
    }
    catch (const std::exception& e)
    {
        e.what();
    }

    cout << endl;
    showStudentMenu();
}

void showAllMenu()
{
    try
    {
        STUDENT::showAll();
    }
    catch (const std::exception& e)
    {
        e.what();
    }

    cout << endl;
    showStudentMenu();
}