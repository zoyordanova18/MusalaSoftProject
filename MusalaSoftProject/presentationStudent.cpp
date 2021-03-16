#include <iostream>
#include "presentationStudent.h"
#include "Presentation.h"

using namespace std;

vector<MENU_OPTION> initializeStudentMenuOptions()
{
    vector<MENU_OPTION> mainMenu =
    {
        {1, ".Add student", showAddStudentMenu},
        {2, ".Edit student", showEditStudentMenu},
        {3, ".Delete student", deleteStudentMenu},
        {4, ".View all students", showAllMenu},
        {5, ".Return to the main menu", showMainMenu}
    };

    return mainMenu;
}

void showAddStudentMenu()
{
    system("cls");

    showAddStudentMenuHeading();

    STUDENT student;

    inputFirstName(student);
    inputLastName(student);
    inputStudentClass(student);
    inputEmail(student);

    STUDENT_SERVICE::add(student);

    showMessage("The student was successfully registered in the system.\n");

    cout << endl;
    showStudentMenu();
}

void showEditStudentMenu()
{
    int id = 0;
    STUDENT student;

    system("cls");

    showEditStudentMenuHeading();

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
        {1, ".First name", editFirstNameMenu},
        {2, ".Last name", editLastNameMenu},
        {3, ".Class", editStudentClassMenu},
        {4, ".E-mail", editStudentEmailMenu},
        {5, ".Return to student menu", returnToStudentMenu}
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
        strcpy_s(student.firstName, firstNameStr.c_str());
    }

    try
    {
        chosen.editFirstName(id, student.firstName);

        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

  
    cout << endl;
    showEditStudentMenu();
}

void editLastNameMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
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
        strcpy_s(student.lastName, lastNameStr.c_str());
    }

    try
    {
        chosen.editLastName(id, student.lastName);
        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    cout << endl;
    showEditStudentMenu();
}

void editStudentClassMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
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
        string studentClassStr;
        isInputValid = safeCin<string>(studentClassStr);
        isInputValid = isNameValid(studentClassStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_STUDENTCLASS_MESSAGE;
        }
        strcpy_s(student.studentClass, studentClassStr.c_str());
    }

    try
    {
        chosen.editClass(id, student.studentClass);

        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    cout << endl;
    showEditStudentMenu();
}

void editStudentEmailMenu(int& id)
{
    STUDENT student;
    STUDENT_SERVICE chosen;
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
        string emailStr;
        isInputValid = safeCin<string>(emailStr);
        isInputValid = isNameValid(emailStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_EMAIL_MESSAGE;
        }
        strcpy_s(student.email, emailStr.c_str());
    }

    try
    {
        chosen.editEmail(id, student.email);

        cout << INFORMATION_EDITED_SUCCESSFULLY_MESSAGE;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

    cout << endl;
    showEditStudentMenu();
}

void inputFirstName(STUDENT& student)
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

        strcpy_s(student.firstName, firstNameStr.c_str());
    }

    cout << endl;
}

void inputLastName(STUDENT& student)
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

        strcpy_s(student.lastName, lastNameStr.c_str());
    }

    cout << endl;
}

void inputStudentClass(STUDENT& student)
{
    bool isInputValid = false;

    while (!isInputValid) {

        setColor(WHITE);
        showMessage("\nClass: ");
        string studentClassStr;
        isInputValid = safeCin<string>(studentClassStr);
        isInputValid = isStudentClassValid(studentClassStr);
        if (!isInputValid)
        {
            setColor(RED);
            cout << INVALID_STUDENTCLASS_MESSAGE;
        }

        strcpy_s(student.studentClass, studentClassStr.c_str());
    }

    cout << endl;
}

void inputEmail(STUDENT& student)
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

        strcpy_s(student.email, emailStr.c_str());
    }

    cout << endl;
}

void deleteStudentMenu()
{
    system("cls");

    STUDENT_SERVICE chosen;
    bool isInputValid = false;
    int id;

    showDeleteStudentMenuHeading();

    showMessage("\nChoose a student to delete: ");
    
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