#include <iostream>
#include <vector>
#include "Presentation.h"
#include "students.h"

using namespace std;

void showMainMenuHeading()
{
    cout << "  __  __       _                                    " << endl;
    cout << " |  \\/  |     (_)                                   " << endl;
    cout << " | \\  / | __ _ _ _ __    _ __ ___   ___ _ __  _   _ " << endl;
    cout << " | |\\/| |/ _` | | '_ \\  | '_ ` _ \\ / _ \\ '_ \\| | | | " << endl;
    cout << " | |  | | (_| | | | | | | | | | | |  __/ | | | |_| | " << endl;
    cout << " |_|  |_|\\__,_|_|_| |_| |_| |_| |_|\\___|_| |_|\\__,_| " << endl;
}

void showSchoolArt()
{
    cout << "         ___________________________" << endl;
    cout << "        //////////////|\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "       '.---------------------------.'" << endl;
    cout << "        |                           |" << endl;
    cout << "        |  [] [] [] [] [] [] [] []  |" << endl;
    cout << "        |                           |" << endl;
    cout << "     _.-.          _ _2_ _          |" << endl;
    cout << "     >   ) ] [] [] ||_|||| [] [] [] |  ,'`\\" << endl;
    cout << "     `.,' _________||___||__________|  \\  <" << endl;
    cout << "      ||   /  _<> _      _    (_)<>\\    ||" << endl;
    cout << "      ''  /<>(_),:/      \\:. <>'  <>\\   ||" << endl;
    cout << "       __::::::::/ _ _ _  \\:::::::::::_" << endl;
    cout << "       __________           ___________" << endl;
    cout << "          ,.::. /           \\  _________" << endl;
    cout << "          `''''/             \\ \\:'-'-'-'-" << endl;
    cout << "         `''''/             \ \ \\:'-'-'-'-" << endl;
}

void showMessage(const char* message)
{
    cout << message;
}

