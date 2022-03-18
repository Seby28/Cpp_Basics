#pragma once

#include "Student.h"
#include <cstdlib>

class Class
{
    Student* students;
    int students_nr;

public:
    Class();
    Class(const Student*, int);
    Class(const Class&);
    Class& operator =(const Class&);
    ~Class();

    friend std::ostream& operator <<(std::ostream&, const Class&);
    // friend std::istream& operator >>(std::istream&, Class&);

    void sortStudents();
    void modify(const char*);

    friend Student* allocate(Student*, int);
    Student* addStudent(Student*, int, Student);
};

