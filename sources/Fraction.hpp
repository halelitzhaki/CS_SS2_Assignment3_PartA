#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <sstream>
#include "math.h"

using namespace std;

namespace ariel {
    class Fraction {
        private:
        int num, den;
        double frac;

        public:
        Fraction();
        Fraction(int, int);
        Fraction(const Fraction&);
        Fraction(Fraction &&) = default;
        Fraction& operator=(const Fraction&) = default;
        Fraction& operator=(Fraction &&) = default;
        ~Fraction() = default;

        // Addition
        Fraction operator+(Fraction&) const;
        Fraction operator+(int) const;
        friend Fraction operator+(int,Fraction&);
        Fraction operator+(double) const;
        friend Fraction operator+(double,Fraction&);
        Fraction operator+(float) const;
        friend Fraction operator+(float,Fraction&);
        Fraction operator++(int);
        Fraction operator++();

        // Substraction
        Fraction operator-(Fraction&) const;
        Fraction operator-(int) const;
        friend Fraction operator-(int,Fraction&);
        Fraction operator-(double) const;
        friend Fraction operator-(double,Fraction&);
        Fraction operator-(float) const;
        friend Fraction operator-(float,Fraction&);
        Fraction operator--(int);
        Fraction operator--();

        // Multiplication
        Fraction operator*(Fraction&) const;
        Fraction operator*(int) const;
        friend Fraction operator*(int,Fraction&);
        Fraction operator*(double) const;
        friend Fraction operator*(double,Fraction&);
        Fraction operator*(float) const;
        friend Fraction operator*(float,Fraction&);

        // Division
        Fraction operator/(Fraction&) const;
        Fraction operator/(int) const;
        friend Fraction operator/(int,Fraction&);
        Fraction operator/(double) const;
        friend Fraction operator/(double,Fraction&);
        Fraction operator/(float) const;
        friend Fraction operator/(float,Fraction&);

        //Boolean
        bool operator==(const Fraction&) const;
        bool operator==(int) const;
        friend bool operator==(int, const Fraction&);
        bool operator==(double) const;
        friend bool operator==(double, const Fraction&);

        bool operator<(const Fraction&) const;
        bool operator<(int) const;
        friend bool operator<(int,const Fraction&);
        bool operator<(double) const;
        friend bool operator<(double,const Fraction&);

        bool operator>(const Fraction&) const;
        bool operator>(int) const;
        friend bool operator>(int,const Fraction&);
        bool operator>(double) const;
        friend bool operator>(double,const Fraction&);

        bool operator>=(const Fraction&) const;
        bool operator>=(int) const;
        friend bool operator>=(int,const Fraction&);
        bool operator>=(double) const;
        friend bool operator>=(double,const Fraction&);

        bool operator<=(const Fraction&) const;
        bool operator<=(int) const;
        friend bool operator<=(int,const Fraction&);
        bool operator<=(double) const;
        friend bool operator<=(double,const Fraction&);

        // Input & Output
        friend ostream& operator<<(ostream&, const Fraction&);
        friend istream& operator>>(istream&,Fraction&);

        // Getters & Etc..
        int getNumerator() const;
        int getDenominator() const;
        double getFrac() const;
        int gcd(int, int) const;
        void reduce();
        Fraction convertDoubleToFrac(double) const;
        void makeFracShort(double);

    };
}

#endif