#include "rational.hpp"

void testDefaultConstructor()
{
	rational<int> r;
	std::cout << "Default constructor" << std::endl;
	std::cout << "r = " << r << std::endl;
	std::cout << std::endl;
}

void testCustomConstructor()
{
	rational<int> r(3,6);
	std::cout << "Custom constructor" << std::endl;
	std::cout << "r(3,6) = " << r << std::endl;
	std::cout << std::endl;
}

void testAddition()
{
	rational<int> r1(4,5), r2(6,9);
	std::cout << "Addition" << std::endl;
	std::cout << r1 << " + " << r2 << " = " << r1+r2 << std::endl;
	std::cout << std::endl;
}

void testSubtraction()
{
	rational<int> r1(4,5), r2(6,9);
	std::cout << "Subtraction" << std::endl;
	std::cout << r1 << " - " << r2 << " = " << r1-r2 << std::endl;
	std::cout << std::endl;
}

void testMultiplication()
{
	rational<int> r1(4,5), r2(6,9);
	std::cout << "Multiplication" << std::endl;
	std::cout << r1 << " * " << r2 << " = "  << r1*r2 << std::endl;
	std::cout << std::endl;
}

void testDivision()
{
	rational<int> r1(4,5), r2(6,9);
	std::cout << "Division" << std::endl;
	std::cout << r1 << " / " << r2 << " = " << r1/r2 << std::endl;
	std::cout << std::endl;
}

void testInf()
{
	rational<int> r1, r2(2,3);
	
	std::cout << "Division by zero" << std::endl;
	std::cout << r2 << " / " << r1 << " = "  << r2/r1 << std::endl;
	std::cout << std::endl;
}
	
void testNaN()
{
	rational<int> r1, r2;
	
	std::cout << "Zero divided by zero" << std::endl;
	std::cout << r2 << " / " << r1 << " = "  << r2/r1 << std::endl;
	std::cout << std::endl;
}

void testAdditionWithInf()
{
	rational<int> rInf(1,0), r(2,3);
		
	std::cout << "Addition with Inf" << std::endl;
	std::cout << rInf << " + " << r << " = " << rInf+r << std::endl;
	std::cout << std::endl;
}

void testSubtractionWithInf()
{
	rational<int> rInf(1,0), r(2,3);
		
	std::cout << "Subtraction with Inf" << std::endl;
	std::cout << rInf << " - " << r << " = " << rInf-r << std::endl;
	std::cout << std::endl;
}

void testMultiplicationWithInf()
{
	rational<int> rInf(1,0), r(2,3);
		
	std::cout << "Multiplication with Inf" << std::endl;
	std::cout << rInf << " * " << r << " = " << rInf*r << std::endl;
	std::cout << std::endl;
}

void testDivisionWithInf()
{
	rational<int> rInf(1,0), r(2,3);
		
	std::cout << "Division with Inf" << std::endl;
	std::cout << rInf << " / " << r << " = " << rInf/r << std::endl;
	std::cout << std::endl;
}

void testDivisionByInf()
{
	rational<int> rInf(1,0), r(2,3);
		
	std::cout << "Division by Inf" << std::endl;
	std::cout << r << " / " << rInf << " = " << r/rInf << std::endl;
	std::cout << std::endl;
}

void testAdditionWithNaN()
{
	rational<int> rNaN(0,0), r(2,3);
		
	std::cout << "Addition with NaN" << std::endl;
	std::cout << rNaN << " + " << r << " = " << rNaN+r << std::endl;
	std::cout << std::endl;
}

void testSubtractionWithNaN()
{
	rational<int> rNaN(0,0), r(2,3);
		
	std::cout << "Subtraction with NaN" << std::endl;
	std::cout << rNaN << " - " << r << " = " << rNaN-r << std::endl;
	std::cout << std::endl;
}

void testMultiplicationWithNaN()
{
	rational<int> rNaN(0,0), r(2,3);
		
	std::cout << "Multiplication with NaN" << std::endl;
	std::cout << rNaN << " * " << r << " = " << rNaN*r << std::endl;
	std::cout << std::endl;
}

void testDivisionWithNaN()
{
	rational<int> rNaN(0,0), r(2,3);
		
	std::cout << "Division with NaN" << std::endl;
	std::cout << rNaN << " / " << r << " = " << rNaN/r << std::endl;
	std::cout << std::endl;
}



int main(void) 
{
	
	testDefaultConstructor();
	testCustomConstructor();
	testAddition();
	testSubtraction();
	testMultiplication();
	testDivision();
	testInf();
	testNaN();
	testAdditionWithInf();
	testSubtractionWithInf();
	testMultiplicationWithInf();
	testDivisionWithInf();
	testDivisionByInf();
	testAdditionWithNaN();
	testSubtractionWithNaN();
	testMultiplicationWithNaN();
	testDivisionWithNaN();
	
	return 0;
}
