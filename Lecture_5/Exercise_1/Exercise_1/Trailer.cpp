#include "Trailer.h"

Trailer::Trailer()
{
    weight = 0;
    type = NULL;
}

Trailer::Trailer(int weight, const char* type)
{
    this->weight = weight;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Trailer::Trailer(const Trailer& obj)
{
    weight = obj.weight;
    type = new char[strlen(obj.type) + 1];
    strcpy(type, obj.type);
}

Trailer& Trailer::operator =(const Trailer& obj)
{
    weight = obj.weight;
    if (type != NULL)
    {
        delete[] type;
    }
    type = new char[strlen(obj.type) + 1];
    strcpy(type, obj.type);

    return *this;
}

Trailer::~Trailer()
{
    delete[] type;
}

std::ostream& operator <<(std::ostream& write, const Trailer& obj)
{
    write << "Trailer type: ";
    if (obj.type != NULL)
    {
        write << obj.type;
    }
    std::cout << std::endl;
    write << "Weight: ";
    write << obj.weight << std::endl;

    return write;
}

std::istream& operator >>(std::istream& read, Trailer& obj)
{
    std::cout << "\tWeight: ";
    read >> obj.weight;
    std::cout << "\tTrailer type: ";
    char buffer[100];
    read >> buffer;
    if (obj.type != NULL)
    {
        delete[] obj.type;
    }
    obj.type = new char[strlen(buffer) + 1];
    strcpy(obj.type, buffer);

    return read;
}

int Trailer::getWeight() const
{
    return weight;
}