
#include "Hexagon.h"
#include "Octagon.h"
#include "Triangle.h"
#include <iostream>
#include "TSTACK.h"
#include "TItearator.h"
#include "TVector.h"
#include "TAllocBlock.h"
#include "Operator.h"
#include <memory>
void menu() {
	std::cout << "0.Exit" << std::endl; 
	std::cout << "1.push Hexagon" << std::endl;
	std::cout << "2.push Octagon" << std::endl;
	std::cout << "3.push Triangle" << std::endl;
	std::cout << "4.pop" << std::endl;
	std::cout << "5.Square delete" << std::endl;
	std::cout << "6.Type delete"  << std::endl;
	std::cout << "7.Print stack" << std::endl;
}

int main() {
	Operator<Figure> op;
	TVector<Figure>* vector = new TVector<Figure>;
	const type_info& HexID = typeid(Hexagon);
	const type_info& OctID = typeid(Octagon);
	const type_info& TriangleID = typeid(Triangle);
	Octagon* oct = new Octagon;
	Hexagon* hex = new Hexagon;
	Triangle* tr = new Triangle;
	shared_ptr<Figure> figur;
	int key; 
	menu();
	while (true) {
		std::cin >> key;
		if (key == 0)
			return 0;
		if (key == 1) {
			std::cin >> *hex;
			figur = shared_ptr<Figure>(hex);
			op.Push(figur);
			std::cout << "pushed" << std::endl;
			hex = new Hexagon;
		}
		if (key == 2) {
			std::cin >> *oct;
			figur = shared_ptr<Figure>(oct);
			op.Push(figur);
			std::cout << "pushed" << std::endl;
			oct = new Octagon;
		}
		if (key == 3) {
			std::cin >> *tr;
			figur = shared_ptr<Figure>(tr);
			op.Push(figur);
			std::cout << "pushed" << std::endl;
			tr = new Triangle;
		}
		if (key == 4) {
			figur = op.Pop();
			if (figur) cout << *figur;
			std::cout << std::endl; 
			
		}
		if (key == 5) {
			double Square;
			cout << "Enter max Square:"; 
			cin >> Square;
			
			op.DeleteSquare(Square);
		}
		if (key == 6) {
			cout << "1. Delete all Hexagons" << endl << "2. Delete all Octagons" << endl << "3. Delete all Triangles" << endl;
			cin >> key;
			switch (key){
				case 1:
					op.DeleteType(HexID);
					break;
				case 2:
					op.DeleteType(OctID);
					break;
				case 3:
					op.DeleteType(TriangleID);
					break;
				default:
					break;
			}
		}
		if (key == 7) {
			cout << op;
		}
	}
	return 0;
}
