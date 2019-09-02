#include "Hexagon.h"
#include "Octagon.h"
#include "Triangle.h"
#include "TSTACK.h"
#include "TItearator.h"
#include "TVector.h"
#include "TAllocBlock.h"
#include <iostream>
#include <memory>
#include <future>

void QuickSort(TStack<Figure>& stack) {

	TStack<Figure> right;
	TStack<Figure> left;
	TStack<Figure> tmpStack;
	shared_ptr<Figure> figurPat;
	shared_ptr<Figure> figurIt;
	double patSquare;
	if (!stack.Empty()) {
		figurPat = stack.Pop();
		patSquare = figurPat->Square();
	}
	while (!stack.Empty()) {
		figurIt = stack.Pop();
		if (figurIt->Square() > patSquare) {
			right.Push(figurIt);
		}
		else {
			left.Push(figurIt);
		}
	}
	if (!right.Empty()) {
		QuickSort(right);
	}
	if (!left.Empty()) {
		QuickSort(left);
	}
	
	while (!right.Empty()) {
		figurIt = right.Pop();
		tmpStack.Push(figurIt);
	}
	while (!tmpStack.Empty()) {
		figurIt = tmpStack.Pop();
		stack.Push(figurIt);
	}
	if(figurPat) stack.Push(figurPat);
	while (!left.Empty()) {
		figurIt = left.Pop();
		tmpStack.Push(figurIt);
	}
	while (!tmpStack.Empty()) {
		figurIt = tmpStack.Pop();
		stack.Push(figurIt);
	}
}

void ParallelQuickSort(TStack<Figure>& stack) {

	future<void> rightResult;
	future<void> leftResult;
	TStack<Figure> right;
	TStack<Figure> left;
	TStack<Figure> tmpStack;
	shared_ptr<Figure> figurPat;
	shared_ptr<Figure> figurIt;
	double patSquare;
	if (!stack.Empty()) {
		figurPat = stack.Pop();
		patSquare = figurPat->Square();
	}
	while (!stack.Empty()) {
		figurIt = stack.Pop();
		if (figurIt->Square() > patSquare) {
			right.Push(figurIt);
		}
		else {
			left.Push(figurIt);
		}
	}
	if (!right.Empty()) {
		rightResult = async(std::launch::async, ParallelQuickSort, right);
	}
	if (!left.Empty()) {
		leftResult = async(std::launch::async, ParallelQuickSort, left);
	}
	if( rightResult.valid())
		rightResult.wait();
	if (leftResult.valid())
		leftResult.wait();

	while (!right.Empty()) {
		figurIt = right.Pop();
		tmpStack.Push(figurIt);
	}
	while (!tmpStack.Empty()) {
		figurIt = tmpStack.Pop();
		stack.Push(figurIt);
	}
	if (figurPat) stack.Push(figurPat);
	while (!left.Empty()) {
		figurIt = left.Pop();
		tmpStack.Push(figurIt);
	}
	while (!tmpStack.Empty()) {
		figurIt = tmpStack.Pop();
		stack.Push(figurIt);
	}
}
	/*if (stack.Empty()) return;
	TStack<Figure> right;
	TStack<Figure> left;
	TStack<Figure> tmpStack;
	shared_ptr<Figure> figurPat;
	shared_ptr<Figure> figurIt;
	future<void> rightResult;
	future<void> leftResult;
	double patSquare;
	figurPat = stack.Pop();
	patSquare = figurPat->Square();
	while (!stack.Empty()) {
		figurIt = stack.Pop();
		if (figurIt->Square() > patSquare) {
			right.Push(figurIt);
		}
		else {
			left.Push(figurIt);
		}
	}
	rightResult = async(std::launch::async, ParallelQuickSort, right);
	rightResult.wait();
	leftResult = async(std::launch::async, ParallelQuickSort, left);
	

	leftResult.wait();

	while (!right.Empty()) {
		figurIt = right.Pop();
		tmpStack.Push(figurIt);
	}
	while (!tmpStack.Empty()) {
		figurIt = tmpStack.Pop();
		stack.Push(figurIt);
	}
	stack.Push(figurPat);
	while (!left.Empty()) {
		figurIt = left.Pop();
		tmpStack.Push(figurIt);
	}
	while (!tmpStack.Empty()) {
		figurIt = tmpStack.Pop();
		stack.Push(figurIt);
	}
}*/

void menu() {
	std::cout << "0.Exit" << std::endl;
	std::cout << "1.push Hexagon" << std::endl;
	std::cout << "2.push Octagon" << std::endl;
	std::cout << "3.push Triangle" << std::endl;
	std::cout << "4.pop" << std::endl;
	std::cout << "5.QuickSort" << std::endl;
	std::cout << "6.ParallelQuickSort" << std::endl;
	std::cout << "7.Print stack" << std::endl;
}

int main() {
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
		return 1;
	}
	shared_ptr<Figure> figur;
	int key;
	menu();
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
				std::cout << "pushed" << std::endl;
				oct = new Octagon;
			}
			if (key == 3) {
				std::cin >> *tr;
				figur = shared_ptr<Figure>(tr);
				stack.Push(figur);
				std::cout << "pushed" << std::endl;
				tr = new Triangle;
			}
			if (key == 4) {
				figur = stack.Pop();
				if (figur) figur->Print();
				std::cout << std::endl;
			}
			if (key == 5) {
				stack.QuickSort();
			}
			if (key == 6) {
				stack.ParallelQuickSort();
			}
			if (key == 7) {
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
