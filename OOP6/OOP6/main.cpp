#include "Hexagon.h"
#include "Octagon.h"
#include "Triangle.h"
#include "TSTACK.h"
#include "TItearator.h"
#include "TVector.h"
#include "TAllocBlock.h"
#include <iostream>
#include <memory>

int main() {
	/*
	TAllocBlock alloc(sizeof(int), 100);
	int* a1 = nullptr;
	int* a2 = nullptr;
	
	a1 = (int*)alloc.allocate();
	a2 = (int*)alloc.allocate();
	*a1 = 5;
	cout << a1 << a2 << *a1 << endl;
	cout << alloc.freeCount << alloc.maxBlocks << endl;
	alloc.deallocate(a1);
	alloc.deallocate(a1);
	system("pause"); */
	TStack<Figure> stack;
	TIterator<StackItem<Figure>, Figure> it;
	Hexagon* hex;
	Octagon* oct;
	Triangle* tr;
	try {
		hex = new Hexagon;
		oct = new Octagon;
		tr = new Triangle;
	}
	catch(exception& e){
		cerr << e.what() << endl;
		//system("pause");
		return 1;
	}
	shared_ptr<Figure> figur;
	int key;
	std::cout << "0.Exit" << std::endl << "1.push Hexagon" << std::endl << "2.push Octagon" << std::endl << "3.push Triangle" << std::endl << "4.pop" << std::endl << "5.Print stack" << std::endl;
	try {
		while (true) {
			std::cin >> key;
			if (key == 0)
				return 0;
			if (key == 1) {
				std::cin >> *hex;
				figur = shared_ptr<Figure>(hex);
				stack.Push(figur);
				std::cout << "pushed" << std::endl;
				hex = new Hexagon;
			}
			if (key == 2) {
				std::cin >> *oct;
				figur = shared_ptr<Figure>(oct);
				stack.Push(figur);
				//vector.push_back(*figur);
				std::cout << "pushed" << std::endl;
				oct = new Octagon;
			}
			if (key == 3) {
				std::cin >> *tr;
				figur = shared_ptr<Figure>(tr);
				stack.Push(figur);
				//vector.push_back(*figur);
				std::cout << "pushed" << std::endl;
				tr = new Triangle;
			}
			if (key == 4) {
				figur = stack.Pop();
				if (figur) figur->Print();
				std::cout << std::endl;
			}
			if (key == 5) {
				cout << stack;


				std::cout << std::endl;
			}
		}
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}
