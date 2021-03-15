#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editStudentLastNameTest)
	{
	public:
		TEST_METHOD(shouldEditStudentLastName)
		{
			// Arrange
			createFilesNeededForTestingStudent("students_editStudentLastNameTest.txt");

			// Act
			STUDENT_SERVICE::editLastName(2, "Marinova");
			std::vector<STUDENT> students = STUDENT_SERVICE::getAll();
			STUDENT student = findStudentById(students, 2);
			STUDENT_SERVICE::close();
			remove("students_editStudentLastNameTest.txt");

			// Assert
			Assert::AreEqual(student.lastName, "Marinova");
		}
	};
}
