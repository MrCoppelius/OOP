#pragma once
#include "TVector.h"
#include "TSTACK.h"
#include <typeinfo.h> 

template <class T> 
class Operator : public TStack<TVector<T>> {
public:
	//Operator();
	void Push(std::shared_ptr<T>& element);
	shared_ptr<T> Pop();
	void DeleteSquare(double square);
	void DeleteType(const  type_info& ID);
	//~Operator();
private:
	void RebuildStack();
	//TVector<T>* vector;
};



template <class T>
void Operator<T>::Push(std::shared_ptr<T>& telement) {
	if (Empty()) {
		shared_ptr<TVector<T>> vector(new TVector<T>);
		TStack<TVector<T>>::Push(vector);
	}
	if (!head->element->size()) {
		head->element->push_back(telement);
	}
	else if (head->element->size() < 5) {
		
		for (int i = 0; i < head->element->size(); i++) {
			if ((*head->element)[i]->Square() >= telement->Square()) {
				head->element->insert(i, telement);
				break;
			}
			else if (i + 1 == head->element->size()) {
				head->element->push_back(telement);
				break;
			}
		}
	}
	else {
		shared_ptr<TVector<T>> vector(new TVector<T>);
		vector->push_back(telement);
		TStack<TVector<T>>::Push(vector);
	}
}

template <class T>
std::shared_ptr<T> Operator<T>::Pop() {
	shared_ptr<T> result;
	if (!Empty()) {
		if (head->element->size() == 1) {
			auto elem = TStack<TVector<T>>::Pop();
			result = (*elem)[0];
		}
		else {
			result = (*head->element)[head->element->size() - 1];
			head->element->remove(head->element->size() - 1);
		}
	}
	return result;
}

template <class T>
void Operator<T>::RebuildStack() {
	TStack<TVector<T>> TmpStack;
	while (!Empty()) {
		auto element = TStack<TVector<T>>::Pop();
		if (element->size()) {
			TmpStack.Push(element);
		}
	}
	while (!TmpStack.Empty()){
		auto element = TmpStack.Pop();
		TStack<TVector<T>>::Push(element);
	}
}

template <class T>
void Operator<T>::DeleteSquare(double square) {
	for (auto it : *this) {
		
		for (int i = it->size()-1; i >= 0; --i) {
			if ((*it)[i]->Square() < square)
				it->remove(i);
		}
	}
	RebuildStack();
}

template <class T>
void Operator<T>::DeleteType(const  type_info& ID ) {
	for (auto it : *this) {
		for (int i = it->size() - 1; i >= 0; --i) {
			
			if (typeid(*(*it)[i].get()) == ID)
				it->remove(i);
		}
	}
	RebuildStack();
}



