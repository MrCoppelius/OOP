#include "Hexagon.h"
#include <cmath>
#include <iostream>

Hexagon::Hexagon() : Hexagon(0) {
}

Hexagon::Hexagon(size_t a) : side_a(a){
    
}
Hexagon::Hexagon(const Hexagon& orig) {
    side_a = orig.side_a;
}

double Hexagon::Square() {
    return double(3 * 1 / 3 * side_a*side_a*sqrt(3));
}

void Hexagon::Print() {
	std::cout << *this;
}

Hexagon& Hexagon::operator = (const Hexagon& right) {
    if (this == &right) return *this;
    
    side_a = right.side_a;
    return *this;
}

Hexagon& Hexagon::operator ++ () {
    side_a++;
    return *this;
}



Hexagon::~Hexagon(){}

std::ostream& operator << (std::ostream& os, const Hexagon& obj) {
	os << "a=" << obj.side_a << " ";
    return os;
}

std::istream& operator >> (std::istream& is, Hexagon& obj) {
    is >> obj.side_a;
    return is;
}
bool operator==(const Hexagon& left, const Hexagon& right) {
    return left.side_a == right.side_a;
}