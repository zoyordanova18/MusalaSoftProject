#include "teams.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

string getTodaysDate()
{
	time_t t = time(NULL);
	tm tPtr{ 0 };
	errno_t err = localtime_s(&tPtr, &t);

	int day, month, year;
	string dayString, monthString, yearString;

	day = (tPtr.tm_mday);
	month = (tPtr.tm_mon) + 1;
	year = (tPtr.tm_year) + 1900;

	dayString = to_string(day);
	dayString = dayString.size() == 1 ? "0" + dayString : dayString;
	monthString = to_string(month);
	monthString = monthString.size() == 1 ? "0" + monthString : monthString;
	yearString = to_string(year);

	string date =  yearString + '-' + monthString + '-' + dayString;

	const char* cDate = date.c_str();

	return cDate;
}
