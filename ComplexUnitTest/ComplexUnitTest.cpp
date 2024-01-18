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
			float re = 1.5;
			float imz = 5.5;
			ComplexNumbers ans = ComplexNumbers(1.5, 5.5);
			c.SetRealPart(re);
			c.SetImaginaryPart(imz);
			Assert::IsTrue(c == ans);
		}

		TEST_METHOD(AdditionTest)
		{
			ComplexNumbers a = ComplexNumbers(4.0, 12.5);
			ComplexNumbers b = ComplexNumbers(2.0, 2.5);
			ComplexNumbers ans = ComplexNumbers(6.0, 15.0);
			auto res = ComplexNumbers::Add(a, b);
			Assert::IsTrue(res == ans);
		}

		TEST_METHOD(SubtractionTest)
		{
			ComplexNumbers a = ComplexNumbers(4.0, 12.5);
			ComplexNumbers b = ComplexNumbers(2.0, 2.5);
			ComplexNumbers ans = ComplexNumbers(-2, -10);
			auto res = ComplexNumbers::Sub(b, a);
			Assert::IsTrue(res == ans);
		}

		TEST_METHOD(MultiplicationTest)
		{
			ComplexNumbers a = ComplexNumbers(4.0, 5.0);
			ComplexNumbers b = ComplexNumbers(10.0, 3.0);
			ComplexNumbers ans = ComplexNumbers(25.0, 62.0);
			auto res = ComplexNumbers::Mult(a, b);
			Assert::IsTrue(res == ans);
		}

		TEST_METHOD(DivisionTest)
		{
			ComplexNumbers a = ComplexNumbers(13.0, 1.0);
			ComplexNumbers b = ComplexNumbers(7.0, -6.0);
			ComplexNumbers ans = ComplexNumbers(1.0, 1.0);
			auto res = ComplexNumbers::Div(a, b);
			Assert::IsTrue(res == ans);
			Assert::ExpectException<std::exception>([]() {
				auto a = ComplexNumbers(4.0, 12.5);
				ComplexNumbers c;
				ComplexNumbers::Div(a, c);
				});
		}

		TEST_METHOD(PowTest)
		{
			ComplexNumbers a = ComplexNumbers(13.0, 1.0);
			ComplexNumbers ans = ComplexNumbers(168.0, 26.0);
			float power = 2;
			auto res = ComplexNumbers::Pow(a, power);
			Assert::IsTrue(res == ans);
		}

		TEST_METHOD(AbsTest)
		{
			ComplexNumbers a = ComplexNumbers(-4.0, 3.0);
			auto res = a.Abs();
			Assert::IsTrue(res == 5);
		}
	};

	TEST_CLASS(BoolOperationTests)
	{
	public:
		TEST_METHOD(EqualsWithComplex)
		{
			ComplexNumbers a = ComplexNumbers(5, 10);
			ComplexNumbers b = ComplexNumbers(5, 10);
			ComplexNumbers c = ComplexNumbers(-5, -10);
			Assert::IsTrue(a == b);
			Assert::IsFalse(a == c);
		}

		TEST_METHOD(EqualsWithInt)
		{
			ComplexNumbers a = ComplexNumbers(4, 0);
			int b = 4;
			Assert::IsTrue(a == b);
			float d = 2.0;
			a.SetImaginaryPart(d);
			Assert::IsFalse(a == b);
		}

		TEST_METHOD(EqualsWithfloat)
		{
			ComplexNumbers a = ComplexNumbers(10, 0);
			float b = 10;
			Assert::IsTrue(a == b);
			a.SetImaginaryPart(b);
			Assert::IsFalse(a == b);

		}
	};
	TEST_CLASS(PackingTest)
	{
		TEST_METHOD(PackingShould) {
			ComplexNumbers c(3.142, 1.234);
			long long c_pack = c.Pack();
			ComplexNumbers b(c_pack);
			Assert::IsTrue(c == b);
		}

		TEST_METHOD(UnpackingShould) {
			ComplexNumbers a(3.142, -5.21);
			long long a_pack = a.Pack();
			ComplexNumbers b;
			b.Unpack(a_pack);
			Assert::IsTrue(a == b);
		}
	};
}
