#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/teachers.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editTeacherLastNameTest)
	{
	public:
		TEST_METHOD(shouldEditTeacherLastName)
		{
			// Arrange
			createFilesNeededForTestingTeacher("teachers_shouldEditTeacherLastName.txt");

			// Act
			TEACHER_SERVICE::editLastName(2, "Videv");
			std::vector<TEACHER> teachers = TEACHER_SERVICE::getAll();
			TEACHER teacher = findTeacherById(teachers, 2);
			TEACHER_SERVICE::close();
			remove("teachers_shouldEditTeacherLastName.txt");

			// Assert
			Assert::AreEqual(teacher.lastName, "Videv");
		}
	};
}
