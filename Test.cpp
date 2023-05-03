#include "doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

using namespace doctest;

#include "sources/Fraction.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Testing Initializing Fraction object") {
    CHECK_NOTHROW(Fraction{1,2});
}

TEST_CASE("Testing copy constructor") {
    Fraction a(1,4), b(1,8);

    a = Fraction(b);

    CHECK(a==b);
    CHECK_FALSE(a.getFrac() == 0.25);
}

TEST_CASE("Testing valid fraction data members") {
    Fraction a(1,4);

    CHECK(typeid(a.getNumerator()).name() == typeid(int).name());
    CHECK(typeid(a.getDenominator()).name() == typeid(int).name());

    CHECK_FALSE(typeid(a.getNumerator()).name() == typeid(float).name());
    CHECK_FALSE(typeid(a.getDenominator()).name() == typeid(float).name());
}

TEST_CASE("Testing addition operator") {
    double _double = 1.5; // 3/2
    float _float = 1.25; // 5/4
    Fraction a(1,4), b(1,8), c = a + b, d = a + 1, e = b + _double, f = c + _float;

    // Fractions addition
    CHECK(c.getNumerator() == 3);
    CHECK(c.getDenominator() == 8);
    CHECK(c.getFrac() == 0.375);

    // Fraction and int addition
    CHECK(d.getNumerator() == 5);
    CHECK(d.getDenominator() == 4);
    CHECK(d.getFrac() == 1.25);

    // Fraction and double addition
    CHECK(e.getNumerator() == 13);
    CHECK(e.getDenominator() == 8);
    CHECK(e.getFrac() == 1.625);

    // Fraction and float addition
    CHECK(f.getNumerator() == 13);
    CHECK(f.getDenominator() == 8);
    CHECK(f.getFrac() == 1.625);
}

TEST_CASE("Testing substraction operator") {
    double _double = 1.5; // 3/2
    float _float = 1.25; // 5/4
    Fraction a(1,4), b(1,8), c = a - b, d = a - 1, e = b - _double, f = c - _float;

    // Fractions substraction
    CHECK(c.getNumerator() == 1);
    CHECK(c.getDenominator() == 8);
    CHECK(c.getFrac() == 0.125);

    // Fraction and int substraction
    CHECK(d.getNumerator() == -3);
    CHECK(d.getDenominator() == 4);
    CHECK(d.getFrac() == -0.75);

    // Fraction and double substraction
    CHECK(e.getNumerator() == -11);
    CHECK(e.getDenominator() == 8);
    CHECK(e.getFrac() == -1.375);

    // Fraction and float substraction
    CHECK(f.getNumerator() == -9);
    CHECK(f.getDenominator() == 8);
    CHECK(f.getFrac() == -1.125);
}

TEST_CASE("Testing multiplication operator") {
    double _double = 1.5; // 3/2
    float _float = 1.25; // 5/4
    Fraction a(1,4), b(1,8), c = a * b, d = a * 1, e = b * _double, f = c * _float;

    // Fractions multiplication
    CHECK(c.getNumerator() == 1);
    CHECK(c.getDenominator() == 32);
    CHECK(c.getFrac() == 0.031);

    // Fraction and int multiplication
    CHECK(d.getNumerator() == 1);
    CHECK(d.getDenominator() == 4);
    CHECK(d.getFrac() == 0.25);

    // Fraction and double multiplication
    CHECK(e.getNumerator() == 3);
    CHECK(e.getDenominator() == 16);
    CHECK(e.getFrac() == 0.187);

    // Fraction and float multiplication
    CHECK(f.getNumerator() == 5);
    CHECK(f.getDenominator() == 128);
    CHECK(f.getFrac() == 0.039);
}

TEST_CASE("Testing division operator") {
    double _double = 1.5; // 3/2
    float _float = 1.25; // 5/4
    Fraction a(1,4), b(1,8), c = a / b, d = a / 1, e = b / _double, f = c / _float;

    // Fractions division
    CHECK(c.getNumerator() == 2);
    CHECK(c.getDenominator() == 1);
    CHECK(c.getFrac() == 2);

    // Fraction and int division
    CHECK(d.getNumerator() == 1);
    CHECK(d.getDenominator() == 4);
    CHECK(d.getFrac() == 0.25);

    // Fraction and double division
    CHECK(e.getNumerator() == 1);
    CHECK(e.getDenominator() == 12);
    CHECK(e.getFrac() == 0.083);

    // Fraction and float division
    CHECK(f.getNumerator() == 8);
    CHECK(f.getDenominator() == 5);
    CHECK(f.getFrac() == 1.6);
}

TEST_CASE("Testing dividing by 0") {
    Fraction a(1,4);
    double zero1 = 0.0;
    float zero2 = 0.0;

    CHECK_THROWS(a/0); // by int
    CHECK_THROWS(a/zero1); // by double
    CHECK_THROWS(a/zero2); // by float
}

TEST_CASE("Testing ++ operator") {
    Fraction a(1,4), b(1,8);

    a++; // after
    CHECK(a.getNumerator() == 5);
    CHECK(a.getDenominator() == 4);
    CHECK(a.getFrac() == 1.25);

    ++b; // before
    CHECK(b.getNumerator() == 9);
    CHECK(b.getDenominator() == 8);
    CHECK(b.getFrac() == 1.125);
}

TEST_CASE("Testing -- operator") {
    Fraction a(1,4), b(1,8);

    a--; // after
    CHECK(a.getNumerator() == -3);
    CHECK(a.getDenominator() == 4);
    CHECK(a.getFrac() == -0.75);

    --b; // before
    CHECK(b.getNumerator() == -7);
    CHECK(b.getDenominator() == 8);
    CHECK(b.getFrac() == -0.875);
}

TEST_CASE("Testing == operator") {
    Fraction a(1,4), b(1,8), c(1,2), d(1,4), e(2,1);

    CHECK(a == d);
    CHECK(a+d == c);
    CHECK(a*c == b);
    CHECK(c*4 == e);
    CHECK_FALSE(e == 0.5);
    CHECK_FALSE(a == b);
    CHECK_FALSE(1 == e);
}

TEST_CASE("Testing < operator") {
    Fraction a(1,4), b(1,8), c(1,2), d(1,4), e(2,1);

    CHECK(b < a);
    CHECK(a+d < e);
    CHECK(a*c < d);
    CHECK(e < c*5);
    CHECK_FALSE(e < b);
    CHECK_FALSE(1 < a);
}

TEST_CASE("Testing > operator") {
    Fraction a(1,4), b(1,8), c(1,2), d(1,4), e(2,1);

    CHECK(c > a);
    CHECK(a+d > b);
    CHECK(a*e > d);
    CHECK(e > c*3);
    CHECK_FALSE(b > e);
}

TEST_CASE("Testing <= operator") {
    Fraction a(1,4), b(1,8), c(1,2), d(1,4), e(2,1);

    CHECK(b <= a);
    CHECK(a+d <= e);
    CHECK(a*c <= d);
    CHECK(e <= c*4);
    CHECK_FALSE(e <= b);
    CHECK_FALSE(1 <= a);
}

TEST_CASE("Testing >= operator") {
    Fraction a(1,4), b(1,8), c(1,2), d(1,4), e(2,1);

    CHECK(c >= a);
    CHECK(a+d >= b);
    CHECK(a*e >= d);
    CHECK(e >= c*4);
    CHECK_FALSE(b >= e);
}

TEST_CASE("Testing float equals to fraction") {
    Fraction a(1,4), b(4, 8);

    CHECK(a.getFrac() == 0.25);
    CHECK(b.getFrac() == 0.5);
    CHECK_FALSE(b.getFrac() == a.getFrac());
}

TEST_CASE("Testing << operator") {
    Fraction a(1,4), b(1,3);
    ostringstream outputStream;

    CHECK_NOTHROW(outputStream << a << "," << b);
    CHECK(outputStream.str() == "0.25,0.333");

}

TEST_CASE("Testing >> operator") {
    Fraction a(1,4);
    istringstream inputStream("0,1");

    CHECK_NOTHROW(inputStream >> a);
    CHECK(a.getNumerator() == 0);
    CHECK(a.getDenominator() == 1);
    CHECK(a.getFrac() == 0);
    CHECK_FALSE(a==0.25);
}

TEST_CASE("Testing couple objects with +, -, /, * operators") {
    Fraction a(1,4), b(1,2), c(2,1), d = a+b+c, e = a+0.75, f = b+c-2.5, g = 3*b/3, h = b*c+1;

    CHECK(d.getFrac() == 2.75);
    CHECK(e.getFrac() == 1);
    CHECK_FALSE(e.getFrac() == 0);
    CHECK(f.getFrac() == 0);
    CHECK(g.getFrac() == b.getFrac());
    CHECK(h.getFrac() == 2);
}

