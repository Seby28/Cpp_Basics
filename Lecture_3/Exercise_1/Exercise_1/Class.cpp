#include "Class.h"

Student::Student()
{
    name = NULL;
    faculty = NULL;
    for (int i = 0; i < 14; i++)
    {
        CNP[i] = '0';
    }
    birth_year = 0;
}

Student::Student(const char* n, const char* f, char C[], int year)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    faculty = new char[strlen(f) + 1];
    strcpy(faculty, f);
    strcpy(CNP, C);
    birth_year = year;
}

Student::Student(const Student& obj)
{
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);
    faculty = new char[strlen(obj.faculty) + 1];
    strcpy(faculty, obj.faculty);
    strcpy(CNP, obj.CNP);
    birth_year = obj.birth_year;
}

Student::~Student()
{
    delete[] name;
    delete[] faculty;
}

void Student::display() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Faculty: " << faculty << "\n";
    std::cout << "CNP: " << CNP << "\n";
    std::cout << "Year of birth: " << birth_year << "\n";
    std::cout << std::endl;
}

void Student::modify(const char* n, const char* f, char C[], int year)
{
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    if (faculty != NULL)
    {
        delete[] faculty;
    }
    faculty = new char[strlen(f) + 1];
    strcpy(faculty, f);
    strcpy(CNP, C);
    birth_year = year;
}

char* Student::getFaculty() const
{
    return faculty;
}

int getYear(const Student& obj)
{
    return 2022 - obj.birth_year;
}

void swap(Student& obj1, Student& obj2)
{
    Student aux(obj1);
    // aux = obj_1;
    obj1 = obj2;
    obj2 = aux;
}

void Student::sortArray(Student* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[i].getFaculty(), arr[j].getFaculty()) > 0)
            {
                swap(arr[i], arr[j]);
            }
}

void Student::printArray(Student* arr, int n)
{
    int max_age = 0;
    for (int i = 0; i < n; i++)
    {
        int age = getYear(arr[i]);
        if (age > max_age)
        {
            max_age = age;
        }
    }
    std::cout << "The oldest students:\n";
    for (int i = 0; i < n; i++)
    {
        int age = getYear(arr[i]);
        if (age == max_age)
        {
            std::cout << arr[i].name << "\n";
        }
    }
}
