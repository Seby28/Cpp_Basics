#pragma once

#include <iostream>
#include <cstring>

class Trailer
{
protected:
    int weight;
    char* type;

public:
    Trailer();
    Trailer(int, const char*);
    Trailer(const Trailer&);
    Trailer& operator =(const Trailer&);
    ~Trailer();

    friend std::ostream& operator <<(std::ostream&, const Trailer&);
    friend std::istream& operator >>(std::istream&, Trailer&);

    int getWeight() const;
};

