#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editStudentClassTest)
	{
	public:
		TEST_METHOD(shouldEditStudentClass)
		{
			// Arrange
			createFilesNeededForTestingStudent("students_editStudentClassTest.txt");

			// Act
			STUDENT_SERVICE::editClass(2, "10G");
			std::vector<STUDENT> students = STUDENT_SERVICE::getAll();
			STUDENT student = findStudentById(students, 2);
			STUDENT_SERVICE::close();
			remove("students_editStudentClassTest.txt");

			// Assert
			Assert::AreEqual(student.studentClass, "10G");
		}
	};
}
