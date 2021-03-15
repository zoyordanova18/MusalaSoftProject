#include "pch.h"
#include <iostream>
#include "HelperFunctionsForTesting.h"
using namespace std;

void createFilesNeededForTestingStudent(const char* fileName)
{
	// Remove old file
	remove(fileName);
	bool isOpened = STUDENT_SERVICE::open(fileName);

	// Initialize some "students" for testing
	STUDENT_SERVICE::add({ 0, "Maksim", "Dimitrov", "10V", "MDDimitrov@codingburgas.bg" });
	STUDENT_SERVICE::add({ 1, "Pedro", "Geshev", "10A", "PMGeshev@codingburgas.bg" });
	STUDENT_SERVICE::add({ 2, "Vanq", "Velikova", "10B", "VVVelikova@codingburgas.bg" });
}

void createFilesNeededForTestingTeacher(const char* fileName)
{
	// Remove old file
	remove(fileName);
	bool isOpened = TEACHER_SERVICE::open(fileName);

	// Initialize some "teachers" for testing
	TEACHER_SERVICE::add({ 0, "Galq", "Stoeva", "GStoeva@codingburgas.bg" });
	TEACHER_SERVICE::add({ 1, "Polina", "Genova", "PGenova@codingburgas.bg" });
	TEACHER_SERVICE::add({ 2, "Valentin", "Baev", "VBaev@codingburgas.bg" });
}

