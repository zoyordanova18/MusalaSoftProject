#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"
#include "../MusalaSoftProject/helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(validStudentClassTest)
	{
	public:

		TEST_METHOD(shouldReturnTrueIfStudentClassIsValid)
		{
			// Arrange
			bool result;

			// Act
			result = isStudentClassValid("10V");

			// Assert
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(shouldReturnFalseIfStudentClassIsInvalid)
		{
			// Arrange
			bool result;

			// Act
			result = isStudentClassValid("B9");

			// Assert
			Assert::AreEqual(false, result);
		}
	};
}
