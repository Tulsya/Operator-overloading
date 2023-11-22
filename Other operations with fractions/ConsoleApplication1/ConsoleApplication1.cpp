#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        simplify(); // Упрощаем дробь при создании объекта
    }

    void simplify() {
        // Реализация сокращения дроби
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int findGCD(int a, int b) {
        // Реализация нахождения наибольшего общего делителя
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() {
        // Префиксный инкремент
        numerator += denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int) {
        // Постфиксный инкремент
        Fraction temp = *this;
        numerator += denominator;
        simplify();
        return temp;
    }

    Fraction& operator--() {
        // Префиксный декремент
        numerator -= denominator;
        simplify();
        return *this;
    }

    Fraction operator--(int) {
        // Постфиксный декремент
        Fraction temp = *this;
        numerator -= denominator;
        simplify();
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};

int main() {
    system("chcp 1251");
    int num1, den1, num2, den2;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction frac1(num1, den1);
    Fraction frac2(num2, den2);

    // Демонстрация операций
    std::cout << frac1 << " + " << frac2 << " = " << frac1 + frac2 << std::endl;
    std::cout << frac1 << " - " << frac2 << " = " << frac1 - frac2 << std::endl;
    std::cout << frac1 << " * " << frac2 << " = " << frac1 * frac2 << std::endl;
    std::cout << frac1 << " / " << frac2 << " = " << frac1 / frac2 << std::endl;

    std::cout << "++" << frac1 << " * " << frac2 << " = " << ++frac1 * frac2 << std::endl;
    std::cout << "Значение дроби 1 = " << frac1 << std::endl;

    std::cout << frac1-- << " * " << frac2 << " = " << frac1 * frac2 << std::endl;
    std::cout << "Значение дроби 1 = " << frac1 << std::endl;

    return 0;
}
