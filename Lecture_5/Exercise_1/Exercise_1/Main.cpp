#include "Vehicle.h"

int main()
{
    int n;
    std::cout << "Enter dimension of array: ";
    std::cin >> n;
    std::cout << std::endl;

    Vehicle* arr;
    arr = new Vehicle[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "VEHICLE " << i + 1 << std::endl;
        std::cin >> arr[i];
    }

    arr->sortArray(arr, n);
    std::cout << "Vehicles with trailers heavier than 500:\n";
    for (int i = 0; i < n; i++)
        if (arr[i].getWeight() > 500)
        {
            std::cout << arr[i];
        }

    delete[] arr;

    return 0;
}
