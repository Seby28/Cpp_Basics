#include "Class.h"

int main()
{
    fraction X(3, 2), Y(6, 4), inverse = X.getInverse();
    std::cout << X.getA() << " / ";
    std::cout << X.getB() << std::endl;
    std::cout << inverse.getA() << " / ";
    std::cout << inverse.getB() << std::endl;

    fraction Z = X;
    std::cout << Z.getA() << " / ";
    std::cout << Z.getB() << std::endl;

    fraction A(Y), B(2, 7);
    std::cout << A.getA() << " / ";
    std::cout << A.getB() << std::endl;
    std::cout << (A + B).getA() << " / ";
    std::cout << (A + B).getB() << std::endl;

    fraction RES = X / Y;
    std::cout << RES.getA() << " / ";
    std::cout << RES.getB() << std::endl;
    std::cout << RES.getValue() << std::endl;

    fraction C(1, 3), D(5), E;
    (((E += D) -= C) += B) -= A;
    std::cout << E.getA() << " / ";
    std::cout << E.getB() << std::endl;

    fraction P = -A, Q(2, 2);
    std::cout << P.getA() << " / ";
    std::cout << P.getB() << std::endl;
    P /= Q;
    std::cout << P.getA() << " / ";
    std::cout << P.getB() << std::endl;

    fraction F = operator *(X, Y);
    std::cout << F.getA() << " / ";
    std::cout << F.getB() << std::endl;
    F.setData(69, 420);
    std::cout << F.getA() << " / ";
    std::cout << F.getB() << std::endl;

    fraction G(69, 420), H(28, 420);
    if (F == G)
    {
        std::cout << "F == F\n";
    }
    if (H != G)
    {
        std::cout << "H != G\n";
    }

    fraction M = X, N(6, 3);
    if (M >= X)
    {
        std::cout << "M >= X\n";
    }
    if (N < Y)
    {
        std::cout << "N < Y\n";
    }
    else
    {
        std::cout << "N > Y\n";
    }

    return 0;
}
