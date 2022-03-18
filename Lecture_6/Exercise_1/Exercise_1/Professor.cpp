#include "Professor.h"

Professor::Professor()
{
    name = NULL;
    strcpy(group, "");
}

Professor::Professor(const char* name, char group[])
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    strcpy(this->group, group);
}

Professor::Professor(const Professor& obj)
{
    name = NULL;
    *this = obj;
}

Professor& Professor::operator =(const Professor& obj)
{
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);
    strcpy(group, obj.group);

    return *this;
}

Professor::~Professor()
{
    delete[] name;
}

std::ostream& operator <<(std::ostream& write, const Professor& obj)
{
    write << "\tProfessor: ";
    if (obj.name != NULL)
    {
        write << obj.name;
    }
    write << std::endl;
    write << "\tGroup: ";
    write << obj.group << std::endl;

    return write;
}

std::istream& operator >>(std::istream& read, Professor& obj)
{
    std::cout << "Professor: ";
    char buffer[100];
    read >> buffer;
    if (obj.name != NULL)
    {
        delete[] obj.name;
    }
    obj.name = new char[strlen(buffer) + 1];
    strcpy(obj.name, buffer);
    std::cout << "Group: ";
    read >> obj.group;

    return read;
}

void Professor::modify(const char* n)
{
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

