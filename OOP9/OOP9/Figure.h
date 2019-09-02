#pragma once
#include <iostream>
#include <cmath>
class Figure {
public:
	virtual double Square() = 0;
	virtual ~Figure() {};
	virtual  void Print() = 0;
	friend std::ostream& operator <<(std::ostream &os, Figure& fig) { fig.Print(); return os; }
};