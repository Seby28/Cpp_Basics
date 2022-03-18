#include "Grade.h"

Grade::Grade() : grades(NULL), grades_nr(0) {}

Grade::Grade(int* grades, int grades_nr)
{
    this->grades = new int[grades_nr];
    for (int i = 0; i < grades_nr; i++)
    {
        this->grades[i] = grades[i];
    }
    this->grades_nr = grades_nr;
}

Grade::Grade(const Grade& obj)
{
    grades = NULL;
    *this = obj;
}

Grade& Grade::operator =(const Grade& obj)
{
    grades_nr = obj.grades_nr;
    if (grades != NULL)
    {
        delete[] grades;
    }
    grades = new int[grades_nr];
    for (int i = 0; i < grades_nr; i++)
    {
        grades[i] = obj.grades[i];
    }

    return *this;
}

Grade::~Grade()
{
    delete[] grades;
}

std::ostream& operator <<(std::ostream& write, const Grade& obj)
{
    write << "\tGrades: ";
    if (obj.grades != NULL)
        for (int i = 0; i < obj.grades_nr; i++)
        {
            write << obj.grades[i] << " ";
        }
    write << std::endl;

    return write;
}

std::istream& operator >>(std::istream& read, Grade& obj)
{
    std::cout << "Number of grades: ";
    read >> obj.grades_nr;
    std::cout << "Grades:\n";
    obj.grades = new int[obj.grades_nr];
    for (int i = 0; i < obj.grades_nr; i++)
    {
        read >> obj.grades[i];
    }

    return read;
}

float Grade::average()
{
    float S = 0;
    for (int i = 0; i < grades_nr; i++)
    {
        S += grades[i];
    }

    return S / grades_nr;
}
