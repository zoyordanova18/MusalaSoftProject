#include "pch.h"
#include <iostream>
#include "HelperFunctionsForTesting.h"
using namespace std;

void createFilesNeededForTesting(const char* fileName)
{
	remove(fileName);
	bool isOpened = STUDENT_SERVICE::open(fileName);
	STUDENT_SERVICE::add({ 1, "Maksim", "Dimitrov", "10V", "MDDimitrov@codingburgas.bg" });
	STUDENT_SERVICE::add({ 2, "Pedro", "Geshev", "10A", "PMGeshev@codingburgas.bg" });
	STUDENT_SERVICE::add({ 3, "Vanq", "Velikova", "10B", "VVVelikova@codingburgas.bg" });
}

