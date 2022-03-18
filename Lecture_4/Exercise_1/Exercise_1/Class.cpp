#include "Class.h"

fraction::fraction(int aa, int bb)
{
    a = aa;
    b = bb;
}

fraction::fraction(const fraction& obj)
{
    a = obj.a;
    b = obj.b;
}

fraction& fraction::operator =(const fraction& obj)
{
    a = obj.a;
    b = obj.b;

    return *this;
}

fraction::~fraction() {}

float fraction::getA()
{
    return (float)a;
}

float fraction::getB()
{
    return (float)b;
}

void fraction::setData(int a, int b)
{
    this->a = a;
    this->b = b;
}

double fraction::getValue()
{
    return (double)a / b;
}

fraction fraction::getInverse()
{
    fraction obj;
    obj.a = this->a;
    obj.b = this->b;

    int aux = obj.a;
    obj.a = obj.b;
    obj.b = aux;

    return obj;
}

int GCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return GCD(b % a, a);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

fraction operator +(const fraction& obj1, const fraction& obj2)
{
    fraction aux;

    if (obj1.b != obj2.b)
    {
        aux.b = LCM(obj1.b, obj2.b);
        aux.a = obj1.a * (aux.b / obj1.b) + obj2.a * (aux.b / obj2.b);
    }
    else
    {
        aux.b = obj1.b;
        aux.a = obj1.a + obj2.a;
    }

    return aux;
}

fraction operator -(const fraction& obj1, const fraction& obj2)
{
    fraction aux;

    if (obj1.b != obj2.b)
    {
        aux.b = LCM(obj1.b, obj2.b);
        aux.a = obj1.a * (aux.b / obj1.b) - obj2.a * (aux.b / obj2.b);
    }
    else
    {
        aux.b = obj1.b;
        aux.a = obj1.a - obj2.a;
    }

    return aux;
}

fraction operator *(const fraction& obj1, const fraction& obj2)
{
    fraction aux;
    aux.a = obj1.a * obj2.a;
    aux.b = obj1.b * obj2.b;

    return aux;
}

fraction operator /(const fraction& obj1, const fraction& obj2)
{
    fraction aux;
    aux.a = obj1.a * obj2.b;
    aux.b = obj1.b * obj2.a;

    return aux;
}

fraction operator -(const fraction& obj)
{
    fraction aux;
    aux.a = 0 - obj.a;
    aux.b = 0 - obj.b;

    return aux;
}

fraction& fraction::operator +=(const fraction& obj)
{
    this->a = this->a + obj.a;
    this->b = this->b + obj.b;

    return *this;
}

fraction& fraction::operator -=(const fraction& obj)
{
    this->a = this->a - obj.a;
    this->b = this->b - obj.b;

    return *this;
}

fraction& fraction::operator *=(const fraction& obj)
{
    this->a = this->a * obj.a;
    this->b = this->b * obj.b;

    return *this;
}

fraction& fraction::operator /=(const fraction& obj)
{
    this->a = this->a / obj.a;
    this->b = this->b / obj.b;

    return *this;
}

bool fraction::operator ==(const fraction& obj)
{
    return (this->a == obj.a && this->b == obj.b);
}

bool fraction::operator !=(const fraction& obj)
{
    return (this->a != obj.a || this->b != obj.b);
}

bool fraction::operator <(const fraction& obj)
{
    if (this->a == obj.a)
    {
        return (this->b > obj.b);
    }
    else
    {
        if (this->b == obj.b)
        {
            return (this->a < obj.a);
        }
        else
        {
            return 0;
            // cout << "Fractions must have a common denominator.\n";
        }
    }
}

bool fraction::operator <=(const fraction& obj)
{
    if (this->a == obj.a)
    {
        return (this->b >= obj.b);
    }
    else
    {
        if (this->b == obj.b)
        {
            return (this->a <= obj.a);
        }
        else
        {
            return 0;
            // cout << "Fractions must have a common denominator.\n";
        }
    }
}

bool fraction::operator >(const fraction& obj)
{
    if (this->a == obj.a)
    {
        return (this->b < obj.b);
    }
    else
    {
        if (this->b == obj.b)
        {
            return (this->a > obj.a);
        }
        else
        {
            return 0;
            // cout << "Fractions must have a common denominator.\n";
        }
    }
}

bool fraction::operator >=(const fraction& obj)
{
    if (this->a == obj.a)
    {
        return (this->b <= obj.b);
    }
    else
    {
        if (this->b == obj.b)
        {
            return (this->a >= obj.a);
        }
        else
        {
            return 0;
            // cout << "Fractions must have a common denominator.\n";
        }
    }
}
