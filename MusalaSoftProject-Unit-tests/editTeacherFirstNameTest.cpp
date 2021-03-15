#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/teachers.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editTeacherFirstNameTest)
	{
	public:
		TEST_METHOD(shouldEditTeacherFirstName)
		{
			// Arrange
			createFilesNeededForTestingTeacher("teachers_shouldEditTeacherFirstName.txt");

			// Act
			TEACHER_SERVICE::editFirstName(1, "Kalina");
			std::vector<TEACHER> teachers = TEACHER_SERVICE::getAll();
			TEACHER teacher = findTeacherById(teachers, 1);
			TEACHER_SERVICE::close();
			remove("teachers_shouldEditTeacherFirstName.txt");

			// Assert
			Assert::AreEqual(teacher.firstName, "Kalina");
		}
	};
}
