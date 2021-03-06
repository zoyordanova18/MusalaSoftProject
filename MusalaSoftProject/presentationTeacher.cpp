

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
		{5, ".Filter teachers", showFilterTeacherMenu},
		{6, ".Return to main menu", showMainMenu}
	};

	return options;
}

vector<MENU_OPTION> initializeFilterTeacherMenuOptions()
{
	vector<MENU_OPTION> options =
	{
		{1, ".Find By Id", filterByIdTeacherMenu},
		{2, ".Filter By First Name", filterByFirstNameTeacherMenu},
		{3, ".Filter By Last Name", filterByLastNameTeacherMenu},
		{4, ".Find by Email", filterByEmailTeacherMenu},
		{5, ".Return to Teacher Menu", showTeacherMenu}
	};

	return options;
}

void filterByIdTeacherMenu()
{
	bool isInputValid = false;

	int id;
	while (!isInputValid)
	{
		system("cls");
		setColor(WHITE);
		showMessage("\nEnter ID: ");
		isInputValid = safeCin<int>(id);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_ID_MESSAGE;
		}
	}

	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	auto predicate = [&](TEACHER teacher)
	{
		return teacher.id == id;
	};

	vector<TEACHER> result = findRecords<TEACHER>(teachers, predicate);

	if (result.size() == 0)
	{
		setColor(RED);
		showMessage("There are not teachers with this id! \n\n");
		setColor(WHITE);
	}
	else
	{
		showTeachersTableHeader();

		for (size_t i = 0; i < result.size(); i++)
		{
			showTeacherInTable(result[i]);
			cout << endl;
		}

		string headerLine(83, '-');
		cout << headerLine << endl << endl << endl;

	}

	showTeacherMenu();

}

void filterByFirstNameTeacherMenu()
{
	bool isInputValid = false;

	string firstName;
	while (!isInputValid)
	{
		system("cls");
		setColor(WHITE);
		showMessage("\nEnter First Name: ");
		isInputValid = safeCin<string>(firstName);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
	}

	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	auto predicate = [&](TEACHER teacher)
	{
		return teacher.firstName == firstName;
	};

	vector<TEACHER> result = findRecords<TEACHER>(teachers, predicate);

	if (result.size() == 0)
	{
		setColor(RED);
		showMessage("There are not teachers with this first name! \n\n");
		setColor(WHITE);
	}
	else
	{
		showTeachersTableHeader();

		for (size_t i = 0; i < result.size(); i++)
		{
			showTeacherInTable(result[i]);
			cout << endl;
		}

		string headerLine(83, '-');
		cout << headerLine << endl << endl << endl;

	}

	showTeacherMenu();

}

void filterByLastNameTeacherMenu()
{
	bool isInputValid = false;

	string lastName;
	while (!isInputValid)
	{
		system("cls");
		setColor(WHITE);
		showMessage("\nEnter Last Name: ");
		isInputValid = safeCin<string>(lastName);
		if (!isInputValid)
		{
			setColor(RED);
			cout << INVALID_FIRSTNAME_MESSAGE;
		}
	}

	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	auto predicate = [&](TEACHER teacher)
	{
		return teacher.lastName == lastName;
	};

	vector<TEACHER> result = findRecords<TEACHER>(teachers, predicate);

	if (result.size() == 0)
	{
		setColor(RED);
		showMessage("There are not teachers with this last name! \n\n");
		setColor(WHITE);
	}
	else
	{
		showTeachersTableHeader();

		for (size_t i = 0; i < result.size(); i++)
		{
			showTeacherInTable(result[i]);
			cout << endl;
		}

		string headerLine(83, '-');
		cout << headerLine << endl << endl << endl;

	}

	showTeacherMenu();

}

void filterByEmailTeacherMenu()
{
	bool isInputValid = false;
	bool isStEmailValid = false;

	string email;
	while (!isInputValid || !isStEmailValid)
	{
		system("cls");
		setColor(WHITE);

		showMessage("\nEnter Email: ");
		isInputValid = safeCin<string>(email);

		isStEmailValid = isEmailValid(email);
		if (!isInputValid || !isStEmailValid)
		{
			setColor(RED);
			cout << INVALID_STUDENTCLASS_MESSAGE;
		}
	}

	vector<TEACHER> teachers = TEACHER_SERVICE::getAll();

	auto predicate = [&](TEACHER teacher)
	{
		return teacher.email == email;
	};

	vector<TEACHER> result = findRecords<TEACHER>(teachers, predicate);

	if (result.size() == 0)
	{
		setColor(RED);
		showMessage("There are not teachers with this email! \n\n");
		setColor(WHITE);
	}
	else
	{
		showTeachersTableHeader();

		for (size_t i = 0; i < result.size(); i++)
		{
			showTeacherInTable(result[i]);
			cout << endl;
		}

		string headerLine(83, '-');
		cout << headerLine << endl << endl << endl;

	}

	showTeacherMenu();

}

void showFilterTeacherMenuHeading()
{
	string heading = "\r\n"
		"______ _ _ _        "
		"      _             "
		"     _              "
		"                    "
		"              \r\n"
		"|  ___(_) | |       "
		"     | |            "
		"    | |             "
		"                    "
		"              \r\n"
		"| |_   _| | |_ ___ _"
		" __  | |_ ___  __ _ "
		" ___| |__   ___ _ __"
		" ___   _ __ ___   __"
		"_ _ __  _   _ \r\n"
		"|  _| | | | __/ _ \\"
		" \'__| | __/ _ \\/ _"
		"` |/ __| \'_ \\ / _ "
		"\\ \'__/ __| | \'_ `"
		" _ \\ / _ \\ \'_ \\|"
		" | | |\r\n"
		"| |   | | | ||  __/ "
		"|    | ||  __/ (_| |"
		" (__| | | |  __/ |  "
		"\\__ \\ | | | | | | "
		" __/ | | | |_| |\r\n"
		"\\_|   |_|_|\\__\\__"
		"_|_|     \\__\\___|"
		"\\__,_|\\___|_| |_|"
		"\\___|_|  |___/ |_| "
		"|_| |_|\\___|_| |_|"
		"\\__,_|\r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"              \r\n"
		"                    "
		"                    "
		"                    "
		"                    "
		"              \r\n";

	cout << heading;

}


void showFilterTeacherMenu()
{
	system("cls");

	showFilterTeacherMenuHeading();

	showMessage("\nChoose what you want to edit\n\n");

	vector<MENU_OPTION> options = initializeFilterTeacherMenuOptions();

	showMenuOptions(options);
	handleUserChoice(options);

	cout << endl;
	showStudentMenu();
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