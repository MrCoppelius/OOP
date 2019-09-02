#include "Octagon.h"
#include <iostream>
#include <cmath>
#define SIZE 1024

Octagon::Octagon() : Octagon(0) {
}

Octagon::Octagon(size_t a) : side_a(a) {

}
Octagon::Octagon(const Octagon& orig) {
	side_a = orig.side_a;
}

TAllocBlock Octagon::OctagonAllocator(sizeof(Octagon), 1024);


double Octagon::Square() {
	return double(2 * side_a*side_a*(1 + sqrt(2)));;
}

void Octagon::Print() {
	std::cout << *this;
}

Octagon& Octagon::operator = (const Octagon& right) {
	if (this == &right) return *this;

	side_a = right.side_a;
	return *this;
}

Octagon& Octagon::operator ++ () {
	side_a++;
	return *this;
}


void* Octagon::operator new (size_t size) {
	return OctagonAllocator.allocate();
}

void Octagon::operator delete(void *p) {
	OctagonAllocator.deallocate(p);
}

Octagon::~Octagon() {

}

std::ostream& operator << (std::ostream& os, const Octagon& obj) {

	os << "a=" << obj.side_a << " ";
	return os;
}

std::istream& operator >> (std::istream& is, Octagon& obj) {
	is >> obj.side_a;
	return is;
}
bool operator==(const Octagon& left, const Octagon& right) {
	return left.side_a == right.side_a;
}




