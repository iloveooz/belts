#include <iostream>
#include <numeric>

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        int GCD = std::gcd(abs(numerator), abs(denominator));

        if (numerator < 0 && denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }

        if (numerator >= 0 && denominator < 0) {
            numerator = -numerator;
            denominator = abs(denominator);
        }

        this->numerator = numerator / GCD;
        this->denominator = denominator / GCD;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    bool operator == (const Rational& lhs) const {
        if (numerator == lhs.Numerator() && denominator == lhs.Denominator())
            return true;
        else
            return false;
    }

    Rational operator + (const Rational& lhs) const {
        return {numerator + lhs.Numerator(), denominator + lhs.Denominator()};
    }

    Rational operator - (const Rational& lhs) const {
        return {numerator - lhs.Numerator(), denominator - lhs.Denominator()};
    }

    friend std::ostream& operator << (std::ostream& stream, const Rational& fraction) {
        stream << "Num = " << fraction.Numerator() << ", Denom = " << fraction.Denominator();
        return stream;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            std::cout << "1. Rational(3, 10) != 3/10" << std::endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            std::cout << "2. Rational(8, 12) != 2/3" << std::endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "3. Rational(-4, 6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            std::cout << "4. r.Num = " << r.Numerator() << ", r.Denom = " << r.Denominator() << std::endl;
            std::cout << "4. Rational(4, -6) != -2/3" << std::endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            std::cout << "5. Rational(0, 15) != 0/1" << std::endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            std::cout << "6. Rational() != 0/1" << std::endl;
            return 5;
        }
    }

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            std::cout << "7. 4/6 != 2/3" << std::endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            std::cout << c << std::endl;
            std::cout << "8. 2/3 + 4/3 != 2" << std::endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            std::cout << "9. 5/7 - 2/9 != 31/63" << std::endl;
            return 3;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}
