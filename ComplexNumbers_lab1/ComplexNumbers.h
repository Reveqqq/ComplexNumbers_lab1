#include <iostream>

namespace complex {

	class ComplexNumbers
	{
	private:
		double _real;
		double _imz;
		double GetAngle() const;
		const double epsilon{ 2.22e-12L };
	public:
		ComplexNumbers(double re, double imz);
		ComplexNumbers();

		double GetRealPart();
		double SetRealPart(const double num_part);
		double GetImaginaryPart();
		double SetImaginaryPart(double& num_part);

		static ComplexNumbers Add(ComplexNumbers& left, ComplexNumbers& rigjt);
		static ComplexNumbers Sub(ComplexNumbers& left, ComplexNumbers& right);
		static ComplexNumbers Mult(ComplexNumbers& left, ComplexNumbers& right);
		static ComplexNumbers Div(ComplexNumbers& left, ComplexNumbers& right);
		static ComplexNumbers Pow(const ComplexNumbers& num, double& n);
		double Abs() const;

		ComplexNumbers operator+(const ComplexNumbers& other) const;
		ComplexNumbers operator-(const ComplexNumbers& other) const;
		ComplexNumbers operator*(const ComplexNumbers& other) const;
		ComplexNumbers operator/(const ComplexNumbers& other) const;

		bool operator==(const ComplexNumbers& other) const noexcept;
		bool operator==(int& other) noexcept;
		bool operator==(double& other) noexcept;

		friend std::ostream& operator<<(std::ostream& out, const ComplexNumbers& complex);
		friend std::istream& operator>>(std::istream& in, ComplexNumbers& complex);
	};
}