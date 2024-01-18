#include "ComplexNumbers.h"
#include <math.h>

namespace complex {

	ComplexNumbers::ComplexNumbers() : ComplexNumbers(0.0, 0.0) {}

	ComplexNumbers::ComplexNumbers(float re, float imz) : _real(re), _imz(imz) {}
	ComplexNumbers::ComplexNumbers(long long packed) { Unpack(packed); }

	long long ComplexNumbers::Pack() {

		unsigned int intA = *reinterpret_cast<unsigned int*>(&_real);
		unsigned int intB = *reinterpret_cast<unsigned int*>(&_imz);

		long long packedValue = static_cast<long long>(intA) << 32 | intB;

		return packedValue;
	}

	void ComplexNumbers::Unpack(long long packed) {

		unsigned int intA = packed >> 32;
		unsigned int intB = packed & 0xFFFFFFFF;

		float* ptrA = reinterpret_cast<float*>(&intA);
		float* ptrB = reinterpret_cast<float*>(&intB);

		_real = *ptrA;
		_imz = *ptrB;
	}

	float ComplexNumbers::GetAngle() const
	{
		return _real ? atan(_imz / _real) : acos(-1);
	}

	float ComplexNumbers::GetRealPart()
	{
		return this->_real;
	}

	float ComplexNumbers::SetRealPart(const float num_part)
	{
		return this->_real = num_part;
	}

	float ComplexNumbers::GetImaginaryPart()
	{
		return this->_imz;
	}

	float ComplexNumbers::SetImaginaryPart(float& num_part)
	{
		return this->_imz = num_part;
	}

	ComplexNumbers ComplexNumbers::Add(ComplexNumbers& left, ComplexNumbers& right)
	{
		return left + right;
	}

	ComplexNumbers ComplexNumbers::Sub(ComplexNumbers& left, ComplexNumbers& right)
	{
		return left - right;
	}

	ComplexNumbers ComplexNumbers::Mult(ComplexNumbers& left, ComplexNumbers& right)
	{
		return left * right;
	}

	ComplexNumbers ComplexNumbers::Div(ComplexNumbers& left, ComplexNumbers& right)
	{
		return left / right;
	}

	ComplexNumbers ComplexNumbers::Pow(const ComplexNumbers& num, float& n)
	{

		float p = pow(num.Abs(), n);
		auto ang = n * num.GetAngle();
		return ComplexNumbers(
			p * cos(ang),
			p * sin(ang)
		);
	}

	float ComplexNumbers::Abs() const
	{
		return sqrt(
			pow(_real, 2) + pow(_imz, 2)
		);
	}

	ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other) const
	{
		return ComplexNumbers(
			this->_real + other._real,
			this->_imz + other._imz
		);
	};

	ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& other) const
	{
		return ComplexNumbers(
			this->_real - other._real,
			this->_imz - other._imz
		);
	}
	ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& other) const
	{
		auto p1 = this->Abs();
		auto p2 = other.Abs();
		auto ang1 = this->GetAngle();
		auto ang2 = other.GetAngle();
		return ComplexNumbers(
			p1 * p2 * cos(ang1 + ang2),
			p1 * p2 * sin(ang1 + ang2)
		);
	}
	ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& other) const
	{
		auto p1 = this->Abs();
		auto p2 = other.Abs();
		if (p2 <= epsilon)
			throw std::exception("Division by zero");
		auto ang1 = this->GetAngle();
		auto ang2 = other.GetAngle();
		return ComplexNumbers(
			(p1 / p2) * cos(ang1 - ang2),
			(p1 / p2) * sin(ang1 - ang2)
		);
	}

	bool ComplexNumbers::operator==(const ComplexNumbers& other) const noexcept
	{
		ComplexNumbers a{ *this };
		return (a - other).Abs() <= epsilon;
	}

	bool ComplexNumbers::operator==(int& other) noexcept
	{
		ComplexNumbers a{ *this };
		ComplexNumbers b{ (float)other, 0 };
		return (a - b).Abs() <= epsilon;
	}

	bool ComplexNumbers::operator==(float& other) noexcept
	{
		ComplexNumbers a{ *this };
		ComplexNumbers b{ other, 0 };
		return (a - b).Abs() <= epsilon;
	}

	std::ostream& operator<<(std::ostream& out, const ComplexNumbers& complex)
	{
		out << complex._real << " + " << complex._imz << 'i';
		return out;
	}

	std::istream& operator>>(std::istream& in, ComplexNumbers& complex)
	{
		in >> complex._real >> complex._imz;
		return in;
	}
}