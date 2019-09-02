#pragma once
#include "Figure.h"
#include "TAllocBlock.h"


class Triangle : public Figure{
public:
	Triangle();
	Triangle(size_t a, size_t b, size_t c);
	Triangle(const Triangle& orig);
	Triangle& operator++();
	double Square();
	void Print();
	friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
	friend std::istream& operator >> (std::istream& is, Triangle& obj);
	friend  bool operator ==(const Triangle& left, const Triangle& right);
	Triangle& operator=(const Triangle& right);
	void* operator new (size_t size);
	void operator delete(void *ptr);
	virtual ~Triangle();
	
private:

	static TAllocBlock TriangleAllocator;
	size_t side_a;
	size_t side_b;
	size_t side_c;
};