#include <iostream>

// using namespace std;

int* allocate_array(int);

void read_array(int[], int);

void order_array(int[], int);

void print_array(int[], int);

int main()
{
    int* arr, n;
    std::cout << "Enter array dimension: ";
    std::cin >> n;

    arr = allocate_array(n);
    read_array(arr, n);
    order_array(arr, n);
    print_array(arr, n);

    delete[] arr;

    return 0;
}

int* allocate_array(int dim)
{
    int* arr;
    arr = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        arr[i] = 0;
    }

    return arr;
}

void read_array(int arr[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    std::cout << std::endl;
}

void order_array(int arr[], int dim)
{
    for (int i = 0; i < dim - 1; i++)
        for (int j = i + 1; j < dim; j++)
            if (arr[i] > arr[j])
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
}

void print_array(int arr[], int dim)
{
    std::cout << "Array: ";
    for (int i = 0; i < dim; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
