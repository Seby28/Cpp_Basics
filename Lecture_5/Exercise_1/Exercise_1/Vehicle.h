#pragma once

#include "Trailer.h"

class Vehicle : public Trailer
{
	int price;
	char* brand;

public:
	Vehicle();
	Vehicle(int, char*, int, char*);
	~Vehicle();

	friend std::ostream& operator <<(std::ostream&, const Vehicle&);
	friend std::istream& operator >>(std::istream&, Vehicle&);

	int getPrice() const;

	void swap(Vehicle&);
	void sortArray(Vehicle*, int);
};

