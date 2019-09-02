#include <cstdlib>
#include "Triangle.h"
#include "Octagon.h"
#include "Hexagon.h"

int main(int argc, char** argv) {

	std::cout << "Enther sides of tringle" << std::endl;
	Figure *ptr = new Triangle(std::cin);
	ptr->Print();
	std::cout << "Square: " <<  ptr->Square() << std::endl;
	delete ptr;
	/*
	std::cout << "Enther side of octagon" << std::endl;
	Figure *oct = new Octagon(std::cin);
	oct->Print();
	std::cout << "Square: " << oct->Square() << std::endl;
	delete oct;
	std::cout << "Enther side of hexagon" << std::endl;
	Figure *hex = new Hexagon(std::cin);
	hex->Print();
	std::cout <<"Square: " << hex->Square() << std::endl;
	delete hex;*/
	system ("pause");
	return 0;

}