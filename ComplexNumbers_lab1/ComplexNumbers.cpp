#include "ComplexNumbers.h"

ComplexNumbers::ComplexNumbers()
{
	_real_part = 0;
	_imaginary_part = 0;
}

ComplexNumbers::ComplexNumbers(double re, double imz)
{
	_real_part = re;
	_imaginary_part = imz;
}

double ComplexNumbers::GetRealPart()
{
	return this->_real_part;
}

double ComplexNumbers::SetRealPart(double num_part)
{
	return this->_real_part = num_part;
}

double ComplexNumbers::GetImaginaryPart()
{
	return this->_imaginary_part;
}

double ComplexNumbers::SetImaginaryPart(double num_part)
{
	return this->_imaginary_part = num_part;
}

ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other)
{
	return ComplexNumbers(
		this->_real_part + other._real_part,
		this->_imaginary_part + other._imaginary_part
	);
};

ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& other)
{
	return ComplexNumbers(
		this->_real_part - other._real_part,
		this->_imaginary_part - other._imaginary_part
	);
};
