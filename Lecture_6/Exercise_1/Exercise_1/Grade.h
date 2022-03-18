#pragma once

#include <iostream>

class Grade
{
protected:
    int* grades;
    int grades_nr;

public:
    Grade();
    Grade(int*, int);
    Grade(const Grade&);
    Grade& operator =(const Grade&);
    ~Grade();

    friend std::ostream& operator <<(std::ostream&, const Grade&);
    friend std::istream& operator >>(std::istream&, Grade&);

    float average();
};

