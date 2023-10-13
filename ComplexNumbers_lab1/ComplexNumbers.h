class ComplexNumbers
{
private:
	double real_part;
	double imaginary_part;
public:
	ComplexNumbers(double x, double y); //constructor
	double GetRealPart(ComplexNumbers number);
	double SetRealPart(ComplexNumbers number);
	double GetImaginaryPart(ComplexNumbers number);
	double SetImaginaryPart(ComplexNumbers number);
};

