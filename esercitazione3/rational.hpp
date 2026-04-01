#ifndef RATIONAL_HEADER
#define RATIONAL_HEADER

#include <concepts>
#include <iostream>
#include <numeric>

template<typename T> requires std::integral<T>
class rational {
	T num_;
	T den_;
	
  public:
	// Default constructor
	rational() {
		num_ = static_cast<T>(0);
		den_ = static_cast<T>(1);
	}
	// Custom constructor
	rational(const T& numerator, const T& denominator) {
		num_ = numerator;
		den_ = denominator;
		
		// Call simplification at construction.
		simplify();
	}
	
	// Accessor methods to numerator and denominator
	T num() const {
		return num_;
	}	
	T den() const {
		return den_;
	}
	
	// Overloading of mathematical operators.
	// Simplification is systematically called so that the rational number is stored already simplified.
	// Positive increment +=
	rational& operator+=(const rational& n) {
		// Updating the numerator before the denominator because the numerator depends on the denominator in the formula.
		// a/b + c/d = (ad + bc)/bd
		this->num_ = this->num_*n.den() + this->den_*n.num(); 
		this->den_ *= n.den(); 
		
		// Call simplification before return.
		simplify();		
		return *this;
	}
	// Sum +
	rational operator+(const rational& n) {
		rational out = *this;
		out += n;
		return out;
	}
	// Negative increment -=
	rational& operator-=(const rational& n) {
		// Updating the numerator before the denominator because the numerator depends on the denominator in the formula.
		// a/b - c/d = (ad - bc)/bd
		this->num_ = this->num_*n.den() - this->den_*n.num();
		this->den_ *= n.den(); 

		// Call simplification before return.
		simplify();		
		return *this;
	}
	// Difference -
	rational operator-(const rational& n) {
		rational out = *this;
		out -= n;
		return out;
	}
	// Multiplicative increment *=
	rational& operator*=(const rational& n) {
		this->num_ *= n.num();
		this->den_ *= n.den();

		// Call simplification before return.
		simplify();
		return *this;
	}
	// Multiplication *
	rational operator*(const rational& n) {
		rational out = *this;
		out *= n;
		return out;
	}
	// Division increment /=
	rational& operator/=(const rational& n) {
		// Swap numerator and denominator w.r.t. multiplication
		this->num_ *= n.den();
		this->den_ *= n.num();

		// Call simplification before return.
		simplify();
		return *this;
	}
	// Division /
	rational operator/(const rational& n) {
		rational out = *this;
		out /= n;
		return out;
	}
	
  private:
    void simplify() {
		// Divide by the greatest common divisor.
		T gcd = std::gcd(this->num_, this->den_);		
		if (gcd != static_cast<T>(0)) { // std::gcd returns zero only if both inputs are zero.
			this->num_ /= gcd;
			this->den_ /= gcd;
		}
	}
	
};

// Display
// Since the operations on type T in the rational template class are only multiplications or sums of numerators and denominators, 
// and since the numerator and denominator are computed and stored individually,
// there is no risk of undefined operation such as division by zero or 0/0. 
// Therefore, it is sufficient to handle these special cases at display.
// In the following, n/0 = Inf (for n != 0) and 0/0 = NaN
template<typename T>
std::ostream& operator<<(std::ostream& os, const rational<T>& value) {
	if (value.den() == static_cast<T>(0)) { // Inf or NaN
		if (value.num() == static_cast<T>(0)) {
			os << "NaN";
		} else {
			os << "Inf";
		}
	} else if (value.num() == static_cast<T>(0)) { // 0/den with den !=0 can be displayed as 0
		os << "0" ;
	} else { // Showing num/den because already simplified in the rational class instance
		os << value.num() << "/" << value.den();
	}
	return os;
}

#endif
