#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editFirstNameTest)
	{
	public:

		TEST_METHOD(shouldEditFirstName)
		{
			// Arrange
			remove("students_shouldEditFirstName.txt");
			bool isOpened = STUDENT_SERVICE::open("students_shouldEditFirstName.txt");			
			STUDENT_SERVICE::add({ 1, "Maksim", "Dimitrov", "10V", "MDDimitrov@codingburgas.bg" });
			STUDENT_SERVICE::add({ 2, "Pedro", "Geshev", "10A", "PMGeshev@codingburgas.bg" });

			// Act
			STUDENT_SERVICE::editFirstName(1, "Ivan");
			std::vector<STUDENT> students = STUDENT_SERVICE::getAll();
			STUDENT student = findStudentById(students, 1);
			STUDENT_SERVICE::close();
			
			// Assert
			Assert::AreEqual(student.firstName, "Ivan");
		}
	};
}
