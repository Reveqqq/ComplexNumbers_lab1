#include <iostream>

namespace complex {

	class ComplexNumbers
	{
	private:
		float _real;
		float _imz;
		float GetAngle() const;
		const float epsilon{ 0.0001f };
	public:
		ComplexNumbers(float re, float imz);
		ComplexNumbers();
		ComplexNumbers(long long packed);
		long long Pack();
		void Unpack(long long packedValue);

		float GetRealPart();
		float SetRealPart(const float num_part);
		float GetImaginaryPart();
		float SetImaginaryPart(float& num_part);

		static ComplexNumbers Add(ComplexNumbers& left, ComplexNumbers& rigjt);
		static ComplexNumbers Sub(ComplexNumbers& left, ComplexNumbers& right);
		static ComplexNumbers Mult(ComplexNumbers& left, ComplexNumbers& right);
		static ComplexNumbers Div(ComplexNumbers& left, ComplexNumbers& right);
		static ComplexNumbers Pow(const ComplexNumbers& num, float& n);
		float Abs() const;

		ComplexNumbers operator+(const ComplexNumbers& other) const;
		ComplexNumbers operator-(const ComplexNumbers& other) const;
		ComplexNumbers operator*(const ComplexNumbers& other) const;
		ComplexNumbers operator/(const ComplexNumbers& other) const;

		bool operator==(const ComplexNumbers& other) const noexcept;
		bool operator==(int& other) noexcept;
		bool operator==(float& other) noexcept;

		friend std::ostream& operator<<(std::ostream& out, const ComplexNumbers& complex);
		friend std::istream& operator>>(std::istream& in, ComplexNumbers& complex);
	};
}