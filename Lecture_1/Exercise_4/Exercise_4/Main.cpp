#include <iostream>

// using namespace std;

struct COMPLEX
{
    double re;
    double im;
};

void read_array(COMPLEX*, int);

void print_array(COMPLEX*, int);

COMPLEX sum(COMPLEX*, int);

void modify_element(COMPLEX*, int, int, COMPLEX);

int main()
{
    int n;
    std::cout << "Enter array dimension: ";
    std::cin >> n;

    COMPLEX* arr;
    arr = new COMPLEX[n];
    read_array(arr, n);
    print_array(arr, n);

    COMPLEX S = sum(arr, n);
    std::cout << "\nSum of elements of array: " << S.re << " + " << S.im << "i" << std::endl;

    modify_element(arr, n, 1, S);
    print_array(arr, n);

    delete[] arr;

    return 0;
}

void read_array(COMPLEX* arr, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        std::cout << "arr[" << i << "].re = ";
        std::cin >> arr[i].re;
        std::cout << "arr[" << i << "].im = ";
        std::cin >> arr[i].im;
    }
}

void print_array(COMPLEX* arr, int dim)
{
    std::cout << "\nArray:" << std::endl;
    for (int i = 0; i < dim; i++)
    {
        std::cout << "arr[" << i << "] = " << arr[i].re << " + " << arr[i].im << "i" << std::endl;
    }
}

COMPLEX sum(COMPLEX* arr, int dim)
{
    COMPLEX S = { 0.0, 0.0 };
    for (int i = 0; i < dim; i++)
    {
        S.re += arr[i].re;
        S.im += arr[i].im;
    }

    return S;
}

void modify_element(COMPLEX* arr, int dim, int p, COMPLEX x)
{
    for (int i = 0; i < dim; i++)
        if (i == p)
        {
            arr[i].re = x.re;
            arr[i].im = x.im;
        }
}
