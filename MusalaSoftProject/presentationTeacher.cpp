#include <iostream>
#include <vector>
#include "Presentation.h"
#include "students.h"
#include "teachers.h"
#include "helpers.h"
#include "presentationTeacher.h"

using namespace std;

vector<MENU_OPTION> initializeTeacherMenuOptions()
{
    vector<MENU_OPTION> options =
    {
        {1, ".Add teacher", showAddTeacherMenu},
        {2, ".Edit teacher", showEditTeacherMenu},
        {3, ".Delete teacher", deleteTeacherMenu},
        {4, ".View all teachers", showAllTeachersMenu},
        {5, ".Return to main menu", showMainMenu}
    };

    return options;
}

void inputFirstName(TEACHER& teacher)
{
    bool isInputValid = false;

    while (!isInputValid) 
    {
        setColor(WHITE);
        showMessage("\nFirst Name: ");
        string firstNameStr;
        isInputValid = safeCin<string>(firstNameStr);
        isInputValid = isNameValid(firstNameStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_FIRSTNAME_MESSAGE;
        }
            
        strcpy_s(teacher.firstName, firstNameStr.c_str());
    }

    cout << endl;
}

void inputLastName(TEACHER& teacher)
{
    bool isInputValid = false;
   
    while (!isInputValid)
    {
        setColor(WHITE);
        showMessage("\nLast Name: ");
        string lastNameStr;
        isInputValid = safeCin<string>(lastNameStr);
        isInputValid = isNameValid(lastNameStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_LASTNAME_MESSAGE;
        }
        strcpy_s(teacher.lastName, lastNameStr.c_str());
    }

    cout << endl;
}

void inputEmail(TEACHER& teacher)
{
    bool isInputValid = false;

    while (!isInputValid)
    {
        setColor(WHITE);
        showMessage("\nE-mail: ");
        string emailStr;
        isInputValid = safeCin<string>(emailStr);
        isInputValid = isEmailValid(emailStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_EMAIL_MESSAGE;
        }
        strcpy_s(teacher.email, emailStr.c_str());
    }

    cout << endl;
}

void showTeacherMenu()
{
    showTeacherMenuHeading();

    vector<MENU_OPTION> menu = initializeTeacherMenuOptions();

    showMenuOptions(menu);
    handleUserChoice(menu);
}

void showAddTeacherMenu()
{
    system("cls");

    showAddTeacherMenuHeading();

    TEACHER student;

    inputFirstName(student);

    inputLastName(student);

    inputEmail(student);

    TEACHER_SERVICE::add(student);

    showMessage("The teacher was successfully registered in the system.\n");

    cout << endl;

    showTeacherMenu();
}

vector<MENU_OPTION_INT> initializeTeacherEditMenuOptions()
{
    vector<MENU_OPTION_INT> options =
    {
       {1, ".First name", editTeacherFirstNameMenu},
       {2, ".Last name", editTeacherLastNameMenu},
       {3, ".E-mail", editTeacherEmailMenu}
    };

    return options;
}

void showEditTeacherMenu()
{
    int id = 0;
    TEACHER teacher;

    system("cls");

    showEditTeacherMenuHeading();

    //cout << "Please choose a student to edit: ";

    //student.showAll();

    cout << "\nChoose what you want to edit\n\n";

    vector<MENU_OPTION_INT> options = initializeTeacherEditMenuOptions();

    showMenuOptionsInt(options);

    handleUserChoiceInt(options);

    cout << endl;

    showTeacherMenu();
}

void editTeacherFirstNameMenu(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid) 
    {
        setColor(WHITE);
        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_ID_MESSAGE;
        }
    }

    isInputValid = false;

    while (!isInputValid) 
    {
        setColor(WHITE);
        showMessage("\nFirst Name: ");
        string firstNameStr;
        isInputValid = safeCin<string>(firstNameStr);
        isInputValid = isNameValid(firstNameStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_FIRSTNAME_MESSAGE;
        }
        strcpy_s(teacher.firstName, firstNameStr.c_str());
    }
    
    try
    {
        chosen.editFirstName(id, teacher.firstName);
        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    showTeacherMenu();
}

void editTeacherLastNameMenu(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid)
    {
        setColor(WHITE);
        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_ID_MESSAGE;
        }
    }

    isInputValid = false;

    while (!isInputValid)
    {
        setColor(WHITE);
        showMessage("\nLast Name: ");
        string lastNameStr;
        isInputValid = safeCin<string>(lastNameStr);
        isInputValid = isNameValid(lastNameStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_LASTNAME_MESSAGE;
        }
        strcpy_s(teacher.lastName, lastNameStr.c_str());
    }

    try
    {
        chosen.editLastName(id, teacher.lastName);
        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    showTeacherMenu();
}

void editTeacherEmailMenu(int& id)
{
    TEACHER teacher;
    TEACHER_SERVICE chosen;
    bool isInputValid = false;

    while (!isInputValid) 
    {
       setColor(WHITE);
       showMessage("\nEnter ID: ");
       isInputValid = safeCin<int>(id);
       if (!isInputValid)
       {
           setColor(RED);
           cout << INVALID_ID_MESSAGE;
       }
    }

    isInputValid = false;

    while (!isInputValid)
    {
        setColor(WHITE);
        showMessage("\nEmail: ");
        string emailStr;
        isInputValid = safeCin<string>(emailStr);
        isInputValid = isEmailValid(emailStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_EMAIL_MESSAGE;
        }
        strcpy_s(teacher.email, emailStr.c_str());
    }
    
    try
    {
        chosen.editEmail(id, teacher.email);
        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    showTeacherMenu();
}

void deleteTeacherMenu()
{
    TEACHER_SERVICE chosen;
    int id;
    bool isInputValid = false;

    showDeleteTeacherMenuHeading();

    showMessage("\nChoose a teacher to delete");

    while (!isInputValid) 
    {
        setColor(WHITE);
        showMessage("\nEnter ID: ");
        isInputValid = safeCin<int>(id);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_ID_MESSAGE;
        }
    }

    chosen.softDeleteTeacher(id);

    showMessage("\nThe teacher was removed successfully.");

    cout << endl;

    showTeacherMenu();
}

void showAllTeachersMenu()
{
    try
    {
        TEACHER::showAll();
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }
 
    cout << endl;
    showTeacherMenu();
}