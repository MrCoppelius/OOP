#pragma once
#include "Figure.h"
#include <iostream>
#include <cmath>

class Hexagon : public Figure {
public:
	Hexagon();
	Hexagon(std::istream &is);
	Hexagon(size_t a);
	Hexagon(const Hexagon &orig);
	double Square() override;
	void Print() override;
	virtual ~Hexagon();
private:
	size_t side_a;
};
