#include "Hexagon.h"
#include "Octagon.h"
#include "Triangle.h"
#include <iostream>
#include "TSTACK.h"
#include <memory>

int main() {
	TStack<Figure> stack;
	Hexagon* hex = new Hexagon;
	Octagon* oct = new Octagon;
	Triangle* tr = new Triangle;
	std::shared_ptr<Figure> figur;
	int key;
	std::cout << "0.Exit" << std::endl << "1.push Hexagon" << std::endl << "2.push Octagon" << std::endl << "3.push Triangle" << std::endl << "4.pop" << std::endl << "5.Print stack" << std::endl;
	while (true) {
		std::cin >> key;
		if (key == 0)
			return 0;
		if (key == 1) {
			std::cin >> *hex;
			figur = std::shared_ptr<Figure>(hex);
			stack.Push(figur);
			std::cout << "pushed" << std::endl;
			hex = new Hexagon;
		}
		if (key == 2) {
			std::cin >> *oct;
			figur = std::shared_ptr<Figure>(oct);
			stack.Push(figur);
			std::cout << "pushed" << std::endl;
			oct = new Octagon;
		}
		if (key == 3) {
			std::cin >> *tr;
			figur = std::shared_ptr<Figure>(tr);
			stack.Push(figur);
			std::cout << "pushed" << std::endl;
			tr = new Triangle;
		}
		if (key == 4) {
			figur = stack.Pop();
			if (figur) figur->Print();
		}
		if (key == 5) {
			std::cout << stack << std::endl;
		}
	}
	return 0;
}
