#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editFirstNameTest)
	{
	public:

		TEST_METHOD(shouldEditFirstName)
		{
			// Arrange
			createFilesNeededForTesting();

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
