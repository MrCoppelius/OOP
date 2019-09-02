#pragma once
#include "Figure.h"
#include "TAllocBlock.h"


class Octagon : public Figure {
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
	void* operator new (size_t size);
	void operator delete(void *ptr);
	virtual ~Octagon();
private:
	static  TAllocBlock  OctagonAllocator;
	size_t side_a;
};