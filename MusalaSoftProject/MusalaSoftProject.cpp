#include <iostream>
#include "students.h"
using namespace std;


int main()
{
	STUDENT a{ 1,"Kondoriano", "Horhe", "10A", "IDIliev18@codingburgas.bg" };
	STUDENT_SERVICE b;
	//cout << sizeof(a)<<endl;

	STUDENT_SERVICE::open();
	//b.editFirstName(2, "Kandy");
	//vector<STUDENT> c = b.getAll();


	STUDENT_SERVICE::add({ 1, "Kondoriano", "Horhe", "10A", "KGHorhe18@codingburgas.bg" });
	STUDENT_SERVICE::add({ 2, "Habibi", "Viutr", "10G", "HZViutr18@codingburgas.bg" });
	STUDENT_SERVICE::add({ 3, "Korja", "Zarzavat", "10G", "KJZarzavat18@codingburgas.bg" });
	STUDENT_SERVICE::add({ 4, "Mokor", "Misooo", "10V", "MJMisooo18@codingburgas.bg" });

	
	//try
	//{
	//	STUDENT_SERVICE::editFirstName(1, "Alo, Alo, Alo");
	//	STUDENT_SERVICE::editLastName(1, "S.O.S, S.O.S");
	//	STUDENT_SERVICE::editClass(8, "36G");
	//	STUDENT_SERVICE::editEmail(1, "DGAlo18@codingburgas.bg");
	//	
	//}
	//catch (const std::exception& e)
	//{
	//	cout << e.what();
	//}
	//cout << sizeof(a);
	STUDENT_SERVICE::removeSt(2);
	a.showAll();
	STUDENT_SERVICE::close();

}

