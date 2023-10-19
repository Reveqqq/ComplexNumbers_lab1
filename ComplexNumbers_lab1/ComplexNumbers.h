class ComplexNumbers
{
private:
	double _real_part;
	double _imaginary_part;
public:
	ComplexNumbers(double re, double imz); //constructor
	ComplexNumbers();
	double GetRealPart();
	double SetRealPart(double num_part);
	double GetImaginaryPart();
	double SetImaginaryPart(double num_part);
	static ComplexNumbers Add(ComplexNumbers& left, ComplexNumbers& rigjt);
	static ComplexNumbers Sub(ComplexNumbers& left, ComplexNumbers& right);
	static ComplexNumbers Mult(ComplexNumbers& left, ComplexNumbers& right);
	static ComplexNumbers Div(ComplexNumbers& left, ComplexNumbers& right);
	static ComplexNumbers Pow(ComplexNumbers& num, float& pow);
	double Abs();
	ComplexNumbers operator+(const ComplexNumbers& other);
	ComplexNumbers operator-(const ComplexNumbers& other);
};

