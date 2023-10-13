#include "ComplexNumbers.h"

ComplexNumbers::ComplexNumbers()
{
	real_part = 0;
	imaginary_part = 0;
}

ComplexNumbers::ComplexNumbers(double re, double imz)
{
	real_part = re;
	imaginary_part = imz;
}

double ComplexNumbers::GetRealPart()
{
	return this->real_part;
}

double ComplexNumbers::SetRealPart(double number)
{
	return this->real_part = number;
}

double ComplexNumbers::GetImaginaryPart()
{
	return this->imaginary_part;
}

double ComplexNumbers::SetImaginaryPart(double number)
{
	return this->imaginary_part = number;
}