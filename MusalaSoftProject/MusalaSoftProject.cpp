#include <iostream>
#include <string>
#include "students.h"
#include "teachers.h"
#include "teams.h"
using namespace std;


int main()
{
	TEACHER a{ 1,"Jamal", "Salim", "jsalim@codingburgas.bg" };
	//cout << sizeof(a)<<endl;

	//bool isOpen = TEACHER_SERVICE::open();
	//b.editFirstName(2, "Kandy");
	//vector<STUDENT> c = b.getAll();


	 //STUDENT_SERVICE::add({ 1, "Kondoriano", "Horhe", "10A", "KGHorhe18@codingburgas.bg" });
	 //STUDENT_SERVICE::add({ 2, "Habibi", "Viutr", "10G", "HZViutr18@codingburgas.bg" });
	 //STUDENT_SERVICE::add({ 3, "Korja", "Zarzavat", "10G", "KJZarzavat18@codingburgas.bg" });
	 //STUDENT_SERVICE::add({ 4, "Mokor", "Misooo", "10V", "MJMisooo18@codingburgas.bg" });

	//STUDENT_SERVICE::add({ 4, "Habib", "Hujok", "10A", "HZHujok18@codingburgas.bg" });
	//TEACHER_SERVICE::add(a);
	//a.showAll();


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
	//STUDENT_SERVICE::removeSt(2);
	//a.showAll();
	//TEACHER_SERVICE::close();

	string date =  getTodaysDate();
}

