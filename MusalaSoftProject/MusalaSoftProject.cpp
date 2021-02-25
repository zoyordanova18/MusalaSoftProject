#include <iostream>
#include "students.h"
using namespace std;


int main()
{
	STUDENT a{ 1,"Kondoriano", "Horhe", "10A", "IDIliev18@codingburgas.bg" };
	STUDENT_SERVICE b;
	cout << sizeof(a)<<endl;

	cout << b.open();
	b.editFirstName(2, "Kandy");
	b.getAll();
	b.close();

}

