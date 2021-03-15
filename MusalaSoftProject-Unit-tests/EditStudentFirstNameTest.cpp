#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editStudentFirstNameTest)
	{
	public:
		TEST_METHOD(shouldEditStudentFirstName)
		{
			// Arrange
			createFilesNeededForTestingStudent("students_shouldEditStudentFirstName.txt");

			// Act
			STUDENT_SERVICE::editFirstName(1, "Ivan");
			std::vector<STUDENT> students = STUDENT_SERVICE::getAll();
			STUDENT student = findStudentById(students, 1);
			STUDENT_SERVICE::close();
			remove("students_shouldEditStudentFirstName.txt");
			
			// Assert
			Assert::AreEqual(student.firstName, "Ivan");
		}
	};
}
