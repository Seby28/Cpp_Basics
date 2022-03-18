#pragma once

#include <iostream>
#include <cstring>

class Student
{
    char* name;
    char* faculty;
    char CNP[14];
    int birth_year;

public:
    Student();
    Student(const char*, const char*, char[], int);
    Student(const Student&);
    ~Student();

    void display() const;
    void modify(const char*, const char*, char[], int);
    char* getFaculty() const;

    friend int getYear(const Student&);
    friend void swap(Student&, Student&);

    void sortArray(Student*, int);
    void printArray(Student*, int);
};


