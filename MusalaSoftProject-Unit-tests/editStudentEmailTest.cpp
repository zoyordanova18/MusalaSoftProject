#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editStudentEmailTest)
	{
	public:
		TEST_METHOD(shouldEditStudentEmail)
		{
			// Arrange
			createFilesNeededForTestingStudent("students_shouldEditStudentEmail.txt");

			// Act
			STUDENT_SERVICE::editEmail(1, "iiivanov18@codingburgas.bg");
			std::vector<STUDENT> students = STUDENT_SERVICE::getAll();
			STUDENT student = findStudentById(students, 1);
			STUDENT_SERVICE::close();
			remove("students_shouldEditStudentEmail.txt");

			// Assert
			Assert::AreEqual(student.email, "iiivanov18@codingburgas.bg");
		}
	};
}
