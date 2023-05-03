#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction() {
    num = 0;
    den = 1;
    frac = (double)num / (double)den;
    makeFracShort(frac);
}

Fraction::Fraction(int _num, int _den) {
    num = _num;
    den = _den;
    frac = (double)num / (double)den;
    makeFracShort(frac);
}

Fraction::Fraction(const Fraction &fraction) {
    num = fraction.getNumerator();
    den = fraction.getDenominator();
    frac = fraction.getFrac();
}

/**************
*Addition start*
***************/

Fraction Fraction::operator+(Fraction& fraction) const {
    Fraction result = Fraction(num * fraction.getDenominator() + fraction.getNumerator() * den, den * fraction.getDenominator());
    result.reduce();
    return result;
}

Fraction Fraction::operator+(int number) const {
    Fraction temp = Fraction(number, 1), result = *this+temp;
    result.reduce();
    return result;
}

Fraction ariel::operator+(int number, Fraction& fraction) {
    Fraction result = fraction+number;
    result.reduce();
    return result;
}

Fraction Fraction::operator+(double number) const {
    Fraction temp = convertDoubleToFrac(number), result = *this+temp;
    result.reduce();
    return result;
}

Fraction ariel::operator+(double number, Fraction& fraction) {
    Fraction result = fraction+number;
    result.reduce();
    return result;
}

Fraction Fraction::operator+(float number) const {
    Fraction temp = convertDoubleToFrac((double)number), result = *this+temp;
    result.reduce();
    return result;
}

Fraction ariel::operator+(float number, Fraction& fraction) {
    Fraction result = fraction+number;
    result.reduce();
    return result;
}

Fraction Fraction::operator++(int n) {
    Fraction temp = Fraction(den, den);
    *this = Fraction(num + temp.getDenominator(), den);
    reduce();
    return *this;
}

Fraction Fraction::operator++() {
    Fraction temp = Fraction(den, den);
    *this = Fraction(num + temp.getDenominator(), den);
    reduce();
    return *this;
}

/*************
*Addition end*
*************/

/*******************
*Substraction start*
*******************/

Fraction Fraction::operator-(Fraction& fraction) const {
    Fraction result = Fraction(num * fraction.getDenominator() - fraction.getNumerator() * den, den * fraction.getDenominator());
    result.reduce();
    return result;
}

Fraction Fraction::operator-(int number) const {
    Fraction temp = Fraction(number, 1), result = *this-temp;
    result.reduce();
    return result;
}

Fraction ariel::operator-(int number, Fraction& fraction) {
    Fraction temp = Fraction(number, 1), result = temp-fraction;
    result.reduce();
    return result;
}

Fraction Fraction::operator-(double number) const {
    Fraction temp = convertDoubleToFrac(number), result = *this-temp;
    result.reduce();
    return result;
}

Fraction ariel::operator-(double number, Fraction& fraction) {
    Fraction temp = fraction.convertDoubleToFrac(number), result = temp-fraction;
    result.reduce();
    result.makeFracShort(result.getFrac());
    return result;
}

Fraction Fraction::operator-(float number) const {
    Fraction temp = convertDoubleToFrac((double)number), result = *this-temp;
    result.reduce();
    return result;
}

Fraction ariel::operator-(float number, Fraction& fraction) {
    Fraction temp = fraction.convertDoubleToFrac((double)number), result = temp-fraction;
    result.reduce();
    return result;
}


Fraction Fraction::operator--(int n) {
    Fraction temp1 = Fraction(den, den);
    *this = Fraction(num - temp1.getDenominator(), den);
    reduce();
    return *this;
}

Fraction Fraction::operator--() {
    Fraction temp1 = Fraction(den, den);
    *this = Fraction(num - temp1.getDenominator(), den);
    reduce();
    return *this;
}

/*****************
*Substraction end*
*****************/

/*********************
*Multiplication start*
*********************/

Fraction Fraction::operator*(Fraction& fraction) const {
    Fraction result = Fraction(num * fraction.getNumerator(), den * fraction.getDenominator());
    result.reduce();
    return result;
}

Fraction Fraction::operator*(int number) const {
    Fraction temp = Fraction(number, 1), result = (*this)*temp;
    result.reduce();
    return result;}

Fraction ariel::operator*(int number, Fraction& fraction) {
    Fraction result = fraction*number;
    result.reduce();
    return result;
}

Fraction Fraction::operator*(double number) const {
    Fraction temp = convertDoubleToFrac(number), result = (*this)*temp;
    result.reduce();
    return result;
}

Fraction ariel::operator*(double number, Fraction& fraction) {
    Fraction result = fraction*number;
    result.reduce();
    return result;
}

Fraction Fraction::operator*(float number) const {
    Fraction temp = convertDoubleToFrac(number), result = (*this)*temp;
    result.reduce();
    return result;
}

Fraction ariel::operator*(float number, Fraction& fraction) {
    Fraction result = fraction*number;
    result.reduce();
    return result;
}

/*******************
*Multiplication end*
*******************/

/***************
*Division start*
***************/


Fraction Fraction::operator/(Fraction& fraction) const {
    if(fraction.getFrac() == 0.0) throw runtime_error("Divide by 0!!");
    Fraction result = Fraction(num * fraction.getDenominator(), den * fraction.getNumerator());
    result.reduce();
    return result;
}

Fraction Fraction::operator/(int number) const {
    if(number == 0) throw runtime_error("Divide by 0!!");
    Fraction temp = Fraction(number, 1), result = *this/temp;
    result.reduce();
    return result;
}

Fraction ariel::operator/(int number, Fraction& fraction) {
    if(fraction.getFrac() == 0.0) throw runtime_error("Divide by 0!!");
    Fraction temp = Fraction(number, 1), result = temp/fraction;
    result.reduce();
    return result;
}

Fraction Fraction::operator/(double number) const {
    if(number == 0.0) throw runtime_error("Divide by 0!!");
    Fraction temp = convertDoubleToFrac(number), result = *this/temp;
    result.reduce();
    return result;
}

Fraction ariel::operator/(double number, Fraction& fraction) {
    if(fraction.getFrac() == 0.0) throw runtime_error("Divide by 0!!");
    Fraction temp = fraction.convertDoubleToFrac(number), result = temp/fraction;
    result.reduce();
    return result;
}

Fraction Fraction::operator/(float number) const {
    if(number == 0.0) throw runtime_error("Divide by 0!!");
    Fraction temp = convertDoubleToFrac(number), result = *this/temp;
    result.reduce();
    return result;
}

Fraction ariel::operator/(float number, Fraction& fraction) {
    if(fraction.getFrac() == 0.0) throw runtime_error("Divide by 0!!");
    Fraction temp = fraction.convertDoubleToFrac((double)number), result = temp/fraction;
    result.reduce();
    return result;
}

/*************
*Division end*
*************/

/**************
*Boolean start*
**************/

bool Fraction::operator==(const Fraction& fraction) const {
    return (num == fraction.getNumerator()) && (den == fraction.getDenominator());
}

bool Fraction::operator==(int number) const {
    Fraction temp = Fraction(number, 1);
    return *this==temp;
}

bool ariel::operator==(int number,const Fraction& fraction) {
    return fraction==number;
}

bool Fraction::operator==(double number) const {
    Fraction temp = convertDoubleToFrac(number);
    return *this==temp;
}

bool ariel::operator==(double number,const Fraction& fraction) {
    return fraction==number;
}

bool Fraction::operator<(const Fraction& fraction) const {
    return frac < fraction.getFrac();
}

bool Fraction::operator<(int number) const {
    Fraction temp = Fraction(number, 1);
    return *this<temp;
}

bool ariel::operator<(int number,const Fraction& fraction) {
    return fraction>number;
}

bool Fraction::operator<(double number) const {
    Fraction temp = convertDoubleToFrac(number);
    return *this<temp;
}

bool ariel::operator<(double number,const Fraction& fraction) {
    return fraction>number;
}

bool Fraction::operator>(const Fraction& fraction) const {
    return fraction<*this;
}

bool Fraction::operator>(int number) const {
    Fraction temp = Fraction(number, 1);
    return *this>temp;
}

bool ariel::operator>(int number,const Fraction& fraction) {
    return fraction<number;
}

bool Fraction::operator>(double number) const {
    Fraction temp = convertDoubleToFrac(number);
    return *this>temp;
}

bool ariel::operator>(double number,const Fraction& fraction) {
    return fraction<number;
}

bool Fraction::operator>=(const Fraction& fraction) const {
    return (*this>fraction) || (*this == fraction);
}

bool Fraction::operator>=(int number) const {
    Fraction temp = Fraction(number, 1);
    return *this>=temp;
}

bool ariel::operator>=(int number,const Fraction& fraction) {
    return fraction<=number;
}

bool Fraction::operator>=(double number) const {
    Fraction temp = convertDoubleToFrac(number);
    return *this>=temp;
}

bool ariel::operator>=(double number,const Fraction& fraction) {
    return fraction<=number;
}

bool Fraction::operator<=(const Fraction& fraction) const {
    return (*this<fraction) || (*this == fraction);
}

bool Fraction::operator<=(int number) const {
    Fraction temp = Fraction(number, 1);
    return *this<=temp;
}

bool ariel::operator<=(int number,const Fraction& fraction) {
    return fraction>=number;
}

bool Fraction::operator<=(double number) const {
    Fraction temp = convertDoubleToFrac(number);
    return *this<=temp;
}

bool ariel::operator<=(double number,const Fraction& fraction) {
    return fraction<=number;
}

/*********************
*Input & Output start*
*********************/

ostream& ariel::operator<<(ostream& outputStream, const Fraction& fraction){
    outputStream << fraction.getFrac();
    return outputStream;
}

istream& ariel::operator>>(istream& inputStream, Fraction& fraction){
    inputStream >> fraction.num;
    inputStream.ignore(1);
    inputStream >> fraction.den;
    fraction.reduce();
    return inputStream;
}

/*********************
*Input & Output end*
*********************/

/************************
*Getters and Etc.. start*
************************/

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

double Fraction::getFrac() const {
    return frac;
}

int Fraction::gcd(int a, int b) const {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Fraction::reduce() {
    int _gcd = gcd(num, den);
    num /= _gcd;
    den /= _gcd;
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    makeFracShort((double)num / (double)den);
}

Fraction Fraction::convertDoubleToFrac(double number) const {
    int n = 0;
    double tempN = number;
    do {
        n++;
        tempN *= 10;
    }while((int)tempN % 10 != 0);
    if(n == 0) n = 1;
    Fraction temp = Fraction(number*pow(10, n), pow(10, n));
    temp.reduce();
    return temp;
}

void Fraction::makeFracShort(double fraction) {
    string strFrac = to_string(fraction), result;
    for(unsigned long i = 0; i < strFrac.length(); i++) {
        if(strFrac[i] == '.') {
            int j = 0;
            while(strFrac[i] != '\0' && j <= 3) { //includes '.'
                result += strFrac[i];
                j++;
                i++;
            }
            break;
        }
        result += strFrac[i];
    }
    frac = stod(result);
}



/**********************
*Getters and Etc.. end*
**********************/