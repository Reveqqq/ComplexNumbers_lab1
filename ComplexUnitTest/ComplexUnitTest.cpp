#include "pch.h"
#include "CppUnitTest.h"
#include "../ComplexNumbers_lab1/ComplexNumbers.cpp"

using namespace complex;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexUnitTest
{
	TEST_CLASS(ConstructorTests)
	{
	public:
		TEST_METHOD(DefaultConstructorTest)
		{
			ComplexNumbers c;
			Assert::IsTrue(c.GetRealPart() == 0);
			Assert::IsTrue(c.GetImaginaryPart() == 0);
		}

		TEST_METHOD(ConstructorTest)
		{
			ComplexNumbers c = ComplexNumbers(10, 5);
			Assert::IsTrue(c.GetRealPart() == 10);
			Assert::IsTrue(c.GetImaginaryPart() == 5);
		}
	};

	TEST_CLASS(OperationWithComplex)
	{
	public:
		TEST_METHOD(SetFunctionsTest)
		{
			ComplexNumbers c;
			double re = 1.5;
			double imz = 5.5;
			c.SetRealPart(re);
			c.SetImaginaryPart(imz);
			Assert::IsTrue(c.GetRealPart() == 1.5);
			Assert::IsTrue(c.GetImaginaryPart() == 5.5);
		}

		TEST_METHOD(AdditionTest)
		{
			ComplexNumbers a = ComplexNumbers(4.0, 12.5);
			ComplexNumbers b = ComplexNumbers(2.0, 2.5);
			a = ComplexNumbers::Add(a, b);
			Assert::IsTrue(a.GetRealPart() == 6);
			Assert::IsTrue(a.GetImaginaryPart() == 15);
		}

		TEST_METHOD(SubtractionTest)
		{
			ComplexNumbers a = ComplexNumbers(4.0, 12.5);
			ComplexNumbers b = ComplexNumbers(2.0, 2.5);
			a = ComplexNumbers::Sub(b, a);
			Assert::IsTrue(a.GetRealPart() == -2);
			Assert::IsTrue(a.GetImaginaryPart() == -10);
		}

		TEST_METHOD(MultiplicationTest)
		{
			ComplexNumbers a = ComplexNumbers(4.0, 5.0);
			ComplexNumbers b = ComplexNumbers(10.0, 3.0);
			double eps = 1E-10;
			a = ComplexNumbers::Mult(a, b);
			Assert::IsTrue(a.GetRealPart() - 25 <= eps);
			Assert::IsTrue(a.GetImaginaryPart() - 62 <= eps);
		}

		TEST_METHOD(DivisionTest)
		{
			ComplexNumbers a = ComplexNumbers(13.0, 1.0);
			ComplexNumbers b = ComplexNumbers(7.0, -6.0);
			double eps = 1E-10;
			a = ComplexNumbers::Div(a, b);
			Assert::IsTrue(a.GetRealPart() - 1 <= eps);
			Assert::IsTrue(a.GetImaginaryPart() - 1 <= eps);
		}

		TEST_METHOD(PowTest)
		{
			ComplexNumbers a = ComplexNumbers(13.0, 1.0);
			double power = 2;
			double eps = 1E-10;
			a = ComplexNumbers::Pow(a, power);
			Assert::IsTrue(a.GetRealPart() - 168 <= eps);
			Assert::IsTrue(a.GetImaginaryPart() - 26 <= eps);
		}

		TEST_METHOD(AbsTest)
		{
			ComplexNumbers a = ComplexNumbers(-4.0, 3.0);
			double eps = 1E-10;
			auto res = a.Abs();
			Assert::IsTrue(res == 5);
		}
	};
}
