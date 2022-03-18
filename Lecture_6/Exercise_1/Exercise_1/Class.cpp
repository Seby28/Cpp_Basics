#include "Class.h"

Class::Class() : students(NULL), students_nr(0) {}

Class::Class(const Student* students, int students_nr)
{
    this->students_nr = students_nr;
    this->students = new Student[students_nr];
    for (int i = 0; i < students_nr; i++)
    {
        this->students[i] = students[i];
    }
}

Class::Class(const Class& obj)
{
    students = NULL;
    *this = obj;
}

Class& Class::operator =(const Class& obj)
{
    students_nr = obj.students_nr;
    if (students != NULL)
    {
        delete[] students;
    }
    students = new Student[students_nr];
    for (int i = 0; i < students_nr; i++)
    {
        students[i] = obj.students[i];
    }

    return *this;
}

Class::~Class()
{
    delete[] students;
}

std::ostream& operator <<(std::ostream& write, const Class& obj)
{
    for (int i = 0; i < obj.students_nr; i++)
    {
        write << "Student " << i + 1 << "\n";
        write << obj.students[i] << std::endl;
    }

    return write;
}

void Class::sortStudents()
{
    for (int i = 0; i < students_nr - 1; i++)
        for (int j = i + 1; j < students_nr; j++)
            if (students[i].average() > students[j].average())
            {
                students[i].swap(students[j]);
            }
}

void Class::modify(const char* n)
{
    for (int i = 0; i < students_nr; i++)
    {
        students[i].modify(n);
    }
}

Student* allocate(Student* arr, int n)
{
    Student* aux = new Student[n + 1];
    for (int i = 0; i < n; i++)
    {
        aux[i] = arr[i];
    }

    return aux;
}

Student* Class::addStudent(Student* arr, int X, Student obj)
{
    if (X > students_nr)
    {
        std::cout << "Position " << X << " does not exist in array.\n";
        return NULL;
    }
    int n = students_nr;
    arr = allocate(students, n);
    for (int i = n - 1; i >= X; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[X] = obj;
    n++;

    return arr;
}


