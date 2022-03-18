#include "Vehicle.h"

Vehicle::Vehicle() : Trailer(), price(0), brand(NULL) {}

Vehicle::Vehicle(int price, char* brand, int weight, char* type) : Trailer(weight, type), price(price)
{
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

Vehicle::~Vehicle()
{
    delete[] brand;
}

std::ostream& operator <<(std::ostream& write, const Vehicle& obj)
{
    write << "Car brand: ";
    if (obj.brand != NULL)
    {
        write << obj.brand;
    }
    std::cout << std::endl;

    return write;
}

std::istream& operator >>(std::istream& read, Vehicle& obj)
{
    std::cout << "Information about the trailer\n";
    read >> (Trailer&)obj;
    std::cout << "Information about the vehicle\n";
    std::cout << "\tPrice: ";
    read >> obj.price;
    std::cout << "\tBrand: ";
    char buffer[100];
    read >> buffer;
    if (obj.brand != NULL)
    {
        delete[] obj.brand;
    }
    obj.brand = new char[strlen(buffer) + 1];
    strcpy(obj.brand, buffer);
    std::cout << std::endl;

    return read;
}

int Vehicle::getPrice() const
{
    return price;
}

void Vehicle::swap(Vehicle& obj)
{
    Vehicle aux(*this);
    *this = obj;
    obj = aux;
}

void Vehicle::sortArray(Vehicle* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i].getPrice() > arr[j].getPrice())
            {
                arr[i].swap(arr[j]);
            }
}

