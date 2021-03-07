#include "pch.h"
#include "CppUnitTest.h"
#include "../MusalaSoftProject/students.h"
#include "HelperFunctionsForTesting.h"
#include "../MusalaSoftProject/helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusalaSoftProjectUnitTests
{
	TEST_CLASS(validEmailTest)
	{
	public:

		TEST_METHOD(shouldReturnTrueIfEmailIsValid)
		{
			// Arrange
			bool result;
			
			// Act
			result = isEmailValid("AABrown@codingburgas.bg");

			// Assert
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(shouldReturnFalseIfEmailIsInvalid)
		{
			// Arrange
			bool result;
			
			// Act
			result = isEmailValid("AABrowncodingburgasbg");

			// Assert
			Assert::AreEqual(false, result);
		}
	};
}
