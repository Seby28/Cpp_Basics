#pragma once

#include <iostream>

class Professor
{
protected:
    char* name;
    char group[7];

public:
    Professor();
    Professor(const char*, char[]);
    Professor(const Professor&);
    Professor& operator =(const Professor&);
    ~Professor();

    friend std::ostream& operator <<(std::ostream&, const Professor&);
    friend std::istream& operator >>(std::istream&, Professor&);

    void modify(const char*);
};

