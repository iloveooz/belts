#include <iostream>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0)
            throw std::invalid_argument("Invalid argument");


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

private:
    int numerator;
    int denominator;
};

bool operator == (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
        return true;
    else
        return false;
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return { lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return { lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return { lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0)
        throw std::domain_error("Division by zero");

    return { lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator() };
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator())
        return true;
    else
        return false;
}

std::ostream& operator << (std::ostream& stream, const Rational& fraction) {
    stream << fraction.Numerator() << '/' << fraction.Denominator();
    return stream;
}

std::istream& operator >> (std::istream& stream, Rational& fraction) {
    int numerator = 0;
    int denominator = 1;

    if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
        fraction = Rational(numerator, denominator);
    else
        fraction = Rational(fraction.Numerator(), fraction.Denominator());

    return stream;
}

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
            return 4;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            std::cout << "5. Rational(0, 15) != 0/1" << std::endl;
            return 5;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            std::cout << "6. Rational() != 0/1" << std::endl;
            return 6;
        }
    }

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            std::cout << "7. 4/6 != 2/3" << std::endl;
            return 7;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            // std::cout << c << std::endl;
            std::cout << "8. 2/3 + 4/3 != 2" << std::endl;
            return 8;
        }
    }

    {
        Rational a(2, 3);
        Rational b(5, 4);
        Rational c = a + b;
        bool equal = c == Rational(23, 12);
        if (!equal) {
            // std::cout << c << std::endl;
            std::cout << "9. 2/3 + 4/3 != 23/12" << std::endl;
            return 9;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            // std::cout << c << std::endl;
            std::cout << "10. 5/7 - 2/9 != 31/63" << std::endl;
            return 10;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            // std::cout << c << std::endl;
            std::cout << "11. 2/3 * 4/3 != 8/9" << std::endl;
            return 11;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            // std::cout << c << std::endl;
            std::cout << "12. 5/4 / 15/8 != 2/3" << std::endl;
            return 12;
        }
    }

    {
        std::ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            std::cout << "13. Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
            return 13;
        }
    }

    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "14. 5/7 is incorrectly read as " << r << std::endl;
            return 14;
        }
    }

    {
        std::istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            std::cout << "15. Read from empty stream works incorrectly" << std::endl;
            return 15;
        }
    }

    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "16. Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
            return 16;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "17. Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 17;
        }
    }

    {
        std::istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            std::cout << "18. Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << std::endl;

            return 18;
        }
    }

    {
        std::istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            std::cout << "19. Multiple-slashed number sequence value read incorrectly: " << r1 << std::endl;
            return 19;
        }
    }

    {
        const std::set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            std::cout << "20. Wrong amount of items in the set" << std::endl;
            return 20;
        }

        std::vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            std::cout << "21. Rationals comparison works incorrectly" << std::endl;
            return 21;
        }
    }

    {
        std::map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            std::cout << "22. Wrong amount of items in the map" << std::endl;
            return 22;
        }
    }

    try {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 23;
    } catch (std::invalid_argument& error) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 24;
    } catch (std::domain_error& error) {
    }

    // std::cout << "OK" << std::endl;

    Rational a, b;
    char o;

    try {
        std::cin >> a >> o >> b;
        switch (o) {
            case '+':
                std::cout << a + b << std::endl;
                break;
            case '-':
                std::cout << a - b << std::endl;
                break;
            case '*':
                std::cout << a * b << std::endl;
                break;
            case '/':
                std::cout << a / b << std::endl;
                break;
            default:
                break;
        }
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
