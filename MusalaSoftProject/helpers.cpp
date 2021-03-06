#include "helpers.h"

template <class T>
bool safeCin(T& input)
{
	if (!(cin >> input))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		return false;
	}

	return true;
}
