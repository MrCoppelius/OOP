#pragma once
#include <iostream>
#include <cmath>
class Figure {
public:
	virtual double Square() = 0;
	virtual ~Figure() {};
	virtual  void Print() = 0;
};