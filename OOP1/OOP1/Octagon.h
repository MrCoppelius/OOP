#pragma once
#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Octagon : public Figure{
public:
	Octagon();
	Octagon(size_t a);
	Octagon(const Octagon& orig);
	Octagon& operator++();
	double Square();
	void Print();
	friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
	friend std::istream& operator >> (std::istream& is, Octagon& obj);
	friend  bool operator ==(const Octagon& left, const Octagon& right);
	Octagon& operator=(const Octagon& right);
	virtual ~Octagon();
private:
	size_t side_a;
};