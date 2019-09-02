#include "Octagon.h"
#include <iostream>
#include <cmath>


Octagon::Octagon() : Octagon(0) {
}

Octagon::Octagon(size_t a) : side_a(a) {

}
Octagon::Octagon(const Octagon& orig) {
	side_a = orig.side_a;
}

double Octagon::Square() {
	return double(2 * side_a*side_a*(1 + sqrt(2)));;
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




