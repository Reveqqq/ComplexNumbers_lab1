#include "ComplexNumbers.h"
#include <math.h>

namespace complex {

	ComplexNumbers::ComplexNumbers() : ComplexNumbers(0.0, 0.0) {}

	ComplexNumbers::ComplexNumbers(double re, double imz)
	{
		_real = re;
		_imz = imz;
	}

	double ComplexNumbers::GetAngle() const
	{
		return _real ? atan(_imz / _real) : acos(-1);
	}

	double ComplexNumbers::GetRealPart()
	{
		return this->_real;
	}

	double ComplexNumbers::SetRealPart(double& num_part)
	{
		return this->_real = num_part;
	}

	double ComplexNumbers::GetImaginaryPart()
	{
		return this->_imz;
	}

	double ComplexNumbers::SetImaginaryPart(double& num_part)
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

	ComplexNumbers ComplexNumbers::Pow(const ComplexNumbers& num, double& n)
	{

		double p = pow(num.Abs(), n);
		auto ang = n * num.GetAngle();
		return ComplexNumbers(
			p * cos(ang),
			p * sin(ang)
		);
	}

	double ComplexNumbers::Abs() const
	{
		return sqrt(
			pow(_real, 2) + pow(_imz, 2)
		);
	}

	ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other)
	{
		return ComplexNumbers(
			this->_real + other._real,
			this->_imz + other._imz
		);
	};

	ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& other)
	{
		return ComplexNumbers(
			this->_real - other._real,
			this->_imz - other._imz
		);
	}
	ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& other)
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
	ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& other)
	{
		auto p1 = this->Abs();
		auto p2 = other.Abs();
		auto ang1 = this->GetAngle();
		auto ang2 = other.GetAngle();
		return ComplexNumbers(
			(p1 / p2) * cos(ang1 - ang2),
			(p1 / p2) * sin(ang1 - ang2)
		);
	}

	bool ComplexNumbers::operator==(const ComplexNumbers& other) const noexcept
	{
		constexpr double epsilon{ 2.22e-12L };
		ComplexNumbers a{ *this };
		return (a - other).Abs() <= epsilon;
	}

	bool ComplexNumbers::operator==(int& other) noexcept
	{
		constexpr double epsilon{ 2.22e-12L };
		ComplexNumbers a{ *this };
		ComplexNumbers b{ (double)other, 0 };
		return (a - b).Abs() <= epsilon;
	}

	bool ComplexNumbers::operator==(double& other) noexcept
	{
		constexpr double epsilon{ 2.22e-12L };
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