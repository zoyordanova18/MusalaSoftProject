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
        {'1', ".Add teacher", showTeacherAddMenu}
       // {'2', ".Edit teacher", /*func*/},
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