#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>	
#include "students.h"
#include "teachers.h"
#include "teams.h"
#include "participants.h"
#include "Presentation.h"
#include "presentationTeam.h"
#include "helpers.h"
using namespace std;

int main()
{
	setColor(WHITE);
	consoleSetup();

	openAllFiles();

	showMainMenu();

	closeAllFiles();
}

