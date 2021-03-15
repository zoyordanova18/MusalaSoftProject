#pragma once
#include <iostream>
#include <fstream>

constexpr auto MAX_CHAR_ARRAY_LENGTH = 32;
constexpr auto MAX_ST_CLASS_LENGTH = 32;
constexpr auto MAX_DESCRIPTION_LENGTH = 256;
constexpr auto RED = 12;
constexpr auto WHITE = 7;

typedef char byte_;

// Frequently used messages
#define INVALID_EMAIL_MESSAGE "\nPlease enter a valid e-mail!\n";
#define INVALID_ID_MESSAGE "\nPlease enter a valid ID!\n";
#define INVALID_FIRSTNAME_MESSAGE "\nPlease enter a valid first name!\n";
#define INVALID_LASTNAME_MESSAGE "\nPlease enter a valid last name!\n";
#define INFORMATION_EDITED_SUCCESSFULLY_MESSAGE "\nThe information was edited successfully.\n";
#define INVALID_MENU_OPTION_MESSAGE "\nPlease enter a valid menu option!\n"