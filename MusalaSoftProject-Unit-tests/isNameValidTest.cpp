#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"
#include "../MusalaSoftProject/helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(validNameTests)
	{
	public:

		TEST_METHOD(shouldReturnTrueIfFirstNameIsValid)
		{
			// Arrange
			bool result;

			// Act
			result = isNameValid("Mariana");

			// Assert
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(shouldReturnFalseIfFirstNameIsInvalid)
		{
			// Arrange
			bool result;

			// Act
			result = isNameValid("Mariana8");

			// Assert
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(shouldReturnTrueIfLastNameIsValid)
		{
			// Arrange
			bool result;

			// Act
			result = isNameValid("Koleva");

			// Assert
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(shouldReturnFalseIfLastNameIsInvalid)
		{
			// Arrange
			bool result;

			// Act
			result = isNameValid("8Koleva");

			// Assert
			Assert::AreEqual(false, result);
		}
	};
}
