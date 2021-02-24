#include <iostream>
#include "students.h"
using namespace std;

int main()
{
	STUDENT a{ 0,"Pesho", "Haka", "10A", "IDIliev18@codingburgas.bg" };

	cout << a.open();
	a.showAll();
	a.close();
}

