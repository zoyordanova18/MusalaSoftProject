#include <iostream>
#include <string>
#include "students.h"
#include "teachers.h"
#include "teams.h"
#include "participants.h"
#include "Presentation.h"
#include "presentationStudent.h"
using namespace std;

int main()
{
	/*TEAM a{ 0, "Chupacabra", "Lovqt Riba", "dfdf", TEAM_STATUS::IN_USE, 0};

	bool isOpen = TEAM_SERVICE::open();

	TEAM_SERVICE::add(a);

	TEAM_SERVICE::close();*/



	//cout << sizeof(a)<<endl;

	 bool isOpen = STUDENT_SERVICE::open();
	// bool isOpenT = TEACHER_SERVICE::open();

	// PARTICIPANT_SERVICE::add({ 0,1,ROLES::SCRUM_MASTER });
	// PARTICIPANT_SERVICE::add({ 2,1,ROLES::BACK_END });
	// PARTICIPANT_SERVICE::add({ 1,2,ROLES::SCRUM_MASTER });
	// PARTICIPANT_SERVICE::add({ 3,3,ROLES::SCRUM_MASTER });

	// TEAM_SERVICE::add({ 0,"Iskender Devs", "Make Duner", "1-1-1", TEAM_STATUS::IN_USE,0 });
	// TEAM_SERVICE::add({ 0,"Jenski Hormoni", "Habii", "1-1-1", TEAM_STATUS::IN_USE,1 });
	// TEAM_SERVICE::add({ 0,"Piko Na Filiq", "Salamuuuuu", "1-1-1", TEAM_STATUS::IN_USE,2 });
	// TEAM_SERVICE::add({ 0,"Sasha Riko", "Udrq li te tok", "1-1-1", TEAM_STATUS::IN_USE,3});

	//b.editFirstName(2, "Kandy");
	//vector<STUDENT> c = b.getAll();


	 //STUDENT_SERVICE::add({ 1, "Kondoriano", "Horhe", "10A", "KGHorhe18@codingburgas.bg" });
	 //STUDENT_SERVICE::add({ 2, "Habibi", "Viutr", "10G", "HZViutr18@codingburgas.bg" });
	 //STUDENT_SERVICE::add({ 3, "Korja", "Zarzavat", "10G", "KJZarzavat18@codingburgas.bg" });
	 //STUDENT_SERVICE::add({ 4, "Mokor", "Misooo", "10V", "MJMisooo18@codingburgas.bg" });

	//STUDENT_SERVICE::add({ 4, "Habib", "Hujok", "10A", "HZHujok18@codingburgas.bg" });
	//TEACHER_SERVICE::add({0,"Vania", "Velikova", "vvelikova@codingburgas.bg"});
	//TEACHER_SERVICE::add({0,"Mitko", "Paynera", "mpaynera@codingburgas.bg"});
	//TEACHER_SERVICE::add({0,"Milko", "Kalaydzhiev", "mkalaydzhiev@codingburgas.bg"});
	//TEACHER_SERVICE::add({0,"Chico", "Turciq", "cturciq@codingburgas.bg"});
	//a.showAll();();


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


	//string date =  getTodaysDate();

	/*vector<PARTICIPANT>a = PARTICIPANT_SERVICE::getAllParticipantsFromTeam(1);

	STUDENT_SERVICE::open();
	vector<STUDENT> c = STUDENT_SERVICE::getAll();
	STUDENT_SERVICE::close();

	STUDENT b = findStudentById(c, a[0].studentId);*/

	// STUDENT student;

	//showMainMenu();



	//student.showAll();

	//STUDENT_SERVICE::editFirstName(1, "GadenTellG");

	//student.showAll();
	
	 STUDENT::showAll();

	STUDENT_SERVICE::close();
	// TEACHER_SERVICE::close();
	// PARTICIPANT_SERVICE::close();

	//showStudentsTableHeader();
}

