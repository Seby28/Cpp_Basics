#pragma once

#include "Grade.h"
#include "Professor.h"

class Student : public Grade, public Professor
{
    char* name;

public:
    Student();
    Student(const char*, int*, int, const char*, char[]);
    Student(const Student&);
    Student& operator =(const Student&);
    ~Student();

    friend std::ostream& operator <<(std::ostream&, const Student&);
    friend std::istream& operator >>(std::istream&, Student&);

    void swap(Student&);
};

