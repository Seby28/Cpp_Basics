#include <iostream>

// using namespace std;

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << n << "! = " << factorial(n) << std::endl;

    return 0;
}
