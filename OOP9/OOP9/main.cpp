
#include "Hexagon.h"
#include "Octagon.h"
#include "Triangle.h"
#include "TSTACK.h"
#include "TItearator.h"
#include "TVector.h"
#include "TAllocBlock.h"
#include "Operator.h"
#include <iostream>
#include <memory>
#include <functional>
#include <ctime>
#include <future>

void menu() {
	std::cout << "0.Exit" << std::endl; 
	std::cout << "1.push generator of figure in vector" << std::endl;
	std::cout << "2.push print in vector" << std::endl;
	std::cout << "3.push delete by square in vector" << std::endl;
	std::cout << "4.make lambda expression" << std::endl;
	std::cout << "5.Print stack" << std::endl;
}

int main() {
	typedef function<void(void)> command;
	srand(time(0));
	TStack<Figure> stack;
	TVector<command> vector;
	shared_ptr<Figure> figur;
	command cmd;
	int key;
	menu();
	
	while (true) {
		cin >> key;
		switch (key) {
		case 0:
			return 0;
		case 1:
			cout << "Enter number of figures:" << endl;
			cin >> key;
			cmd = [&, key]() {
				for (int i = 0; i < key; ++i) {
					int a = rand() % 3;
					size_t side = rand() % 1000 + 1;
					if (a == 1)
						figur = shared_ptr<Figure>(new Hexagon(side));
					else if (a == 2)
						figur = shared_ptr<Figure>(new Octagon(side));
					else
						figur = shared_ptr<Figure>(new Triangle(side, side, side));
					stack.Push(figur);
					//cout << i << endl;
				}
			};
			vector.push_back(make_shared<command>(cmd));
			std::cout << "pushed" << std::endl;
			break;
		case 2:
			cmd = [&]() {
				cout << stack << endl;

			};
			vector.push_back(make_shared<command>(cmd));
			std::cout << "pushed" << std::endl;
			break;
		case 3:
			double square;
			cout << "Enter min square:" << endl;
			cin >> square;
			cmd = [&,square]() {
				TStack<Figure> tmpStack;
				TStack<Figure> tmpStack2;
				while (!stack.Empty()) {
					figur = stack.Pop();
					if (figur->Square()>=square)
						tmpStack.Push(figur);
				}
				while (!tmpStack.Empty()) {
					tmpStack2.Push(tmpStack.Pop());
				}
				while (!tmpStack2.Empty()) {
					stack.Push(tmpStack2.Pop());
				}
			};
			vector.push_back(make_shared<command>(cmd));
			std::cout << "pushed" << std::endl;
			break;
		case 4:
			for (int i = 0; i < vector.size(); ++i) {
				shared_ptr<command> ptrCmd = vector[i];
				future<void> ft = async(*ptrCmd);
				ft.get();
			}
			std::cout << "make" << std::endl;
			break;
		case 5:
			cout << stack;
		default:
			break;
		}
	}
	return 0;
}





