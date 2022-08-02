#include <iostream>

class Fraction
{
public:
	Fraction(int a, int b) {
		numerator = a;
		denominator = b;
	}

	friend std::istream& operator>>(std::istream& in, Fraction& a);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& a);
private:
	int numerator = 0, denominator = 0;
};

std::istream& operator>>(std::istream& in, Fraction& a)
{

	if (in >> a.numerator) {
		std::cout << "Number Entered\n";
	}
	else
	{
		throw "Not int";
	}

	if (in >> a.denominator) {
		if (a.denominator == 0)
			throw std::runtime_error("Denominator is 0");
		else
			std::cout << "Number Entered\n";
	}
	else
	{
		throw "Not int";
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& a)
{
	out << ' ' << a.numerator << ' ' << a.denominator;
	return out;
}

int main()
{
	Fraction f(0, 0);
	try {
		std::cin >> f;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << "\n";
	}
	catch (const char* exception) {
		std::cerr << "Exception: " << exception;
	}
}