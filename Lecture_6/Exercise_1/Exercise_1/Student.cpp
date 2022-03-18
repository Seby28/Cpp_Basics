#include "Student.h"

Student::Student() : Grade(), Professor(), name(NULL) {}

Student::Student(const char* S_name, int* grades, int grades_nr, const char* P_name, char group[]) : Grade(grades, grades_nr), Professor(P_name, group)
{
    this->name = new char[strlen(S_name) + 1];
    strcpy(this->name, S_name);
}

Student::Student(const Student& obj)
{
    Student::name = NULL;
    Professor::name = NULL;
    *this = obj;
}

Student& Student::operator =(const Student& obj)
{
    Grade::operator =(obj);
    Professor::operator =(obj);
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);

    return *this;
}

Student::~Student()
{
    delete[] name;
}

std::ostream& operator <<(std::ostream& write, const Student& obj)
{
    write << "\tNume: ";
    if (obj.name != NULL)
    {
        write << obj.name;
    }
    write << std::endl;
    write << (Grade&)obj;
    write << (Professor&)obj;

    return write;
}

std::istream& operator >>(std::istream& read, Student& obj)
{
    std::cout << "Name: ";
    char buffer[100];
    read >> buffer;
    if (obj.name != NULL)
    {
        delete[] obj.name;
    }
    obj.name = new char[strlen(buffer) + 1];
    strcpy(obj.name, buffer);
    read >> (Grade&)obj;
    read >> (Professor&)obj;
    std::cout << std::endl;

    return read;
}

void Student::swap(Student& obj)
{
    Student aux(*this);
    *this = obj;
    obj = aux;
}

