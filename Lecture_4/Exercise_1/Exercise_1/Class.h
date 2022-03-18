#pragma once

#include <iostream>

class fraction
{
    int a;  // numerator
    int b;  // denominator

public:
    fraction(int aa = 0, int bb = 0);
    fraction(const fraction&);
    fraction& operator =(const fraction&);
    ~fraction();

    float getA();
    float getB();
    void setData(int, int);
    double getValue();
    fraction getInverse();

    friend int GCD(int, int);   // greatest common divisor
    friend int LCM(int, int);   // least common multiple
    friend fraction operator +(const fraction&, const fraction&);
    friend fraction operator -(const fraction&, const fraction&);
    friend fraction operator *(const fraction&, const fraction&);
    friend fraction operator /(const fraction&, const fraction&);
    friend fraction operator -(const fraction&);

    fraction& operator +=(const fraction&);
    fraction& operator -=(const fraction&);
    fraction& operator *=(const fraction&);
    fraction& operator /=(const fraction&);

    bool operator ==(const fraction&);
    bool operator !=(const fraction&);
    bool operator <(const fraction&);
    bool operator <=(const fraction&);
    bool operator >(const fraction&);
    bool operator >=(const fraction&);
};
