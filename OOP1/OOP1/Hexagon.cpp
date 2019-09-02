#include "Hexagon.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0) {
}

Hexagon::Hexagon(size_t a) : side_a(a) {
	std::cout << "Hexagon created"  << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
	is >> side_a;
	std::cout << "Hexagon created" << std::endl;
}

Hexagon::Hexagon(const Hexagon &orig) {
	std::cout << "Hexagon copy created" << std::endl;
	side_a = orig.side_a;
}

double Hexagon::Square() {
	return double(3*1/3*side_a*side_a*sqrt(3));
}

void Hexagon::Print() {
	std::cout << "a=" << side_a << std::endl;
}

Hexagon::~Hexagon() {
	std::cout << "Hexagon deleted" << std::endl;
}
