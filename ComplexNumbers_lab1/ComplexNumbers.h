class ComplexNumbers
{
private:
	double real_part;
	double imaginary_part;
public:
	ComplexNumbers(double re, double imz); //constructor
	ComplexNumbers();
	double GetRealPart();
	double SetRealPart(double number);
	double GetImaginaryPart();
	double SetImaginaryPart(double number);

	ComplexNumbers operator+(const ComplexNumbers &other)
	{
		return ComplexNumbers(
			this->real_part + other.real_part,
			this->imaginary_part + other.imaginary_part
		);
	};

	ComplexNumbers operator-(const ComplexNumbers& other)
	{
		return ComplexNumbers(
			this->real_part - other.real_part,
			this->imaginary_part -	 other.imaginary_part
		);
	};
};

