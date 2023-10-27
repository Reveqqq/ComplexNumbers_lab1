#include "pch.h"
#include "CppUnitTest.h"
#include "../ComplexNumbers_lab1/ComplexNumbers.cpp"

using namespace complex;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexUnitTest
{
	TEST_CLASS(ComplexUnitTest)
	{
	public:
		
		TEST_METHOD(DefaultConstructorTest)
		{
			ComplexNumbers c;
			Assert::IsTrue(c.GetRealPart() == 0);
			Assert::IsTrue(c.GetImaginaryPart() == 0);

		}
	};
}
