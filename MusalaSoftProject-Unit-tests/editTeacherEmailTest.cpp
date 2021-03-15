#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/teachers.h"
#include "HelperFunctionsForTesting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(editTeacherEmailTest)
	{
	public:
		TEST_METHOD(shouldEditTeacherEmail)
		{
			// Arrange
			createFilesNeededForTestingTeacher("teachers_shouldEditTeacherEmail.txt");

			// Act
			TEACHER_SERVICE::editEmail(0, "kkoleva@codingburgas.bg");
			std::vector<TEACHER> teachers = TEACHER_SERVICE::getAll();
			TEACHER teacher = findTeacherById(teachers, 0);
			TEACHER_SERVICE::close();
			remove("teachers_shouldEditTeacherEmail.txt");

			// Assert
			Assert::AreEqual(teacher.email, "kkoleva@codingburgas.bg");
		}
	};
}
