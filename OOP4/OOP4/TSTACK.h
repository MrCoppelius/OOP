#pragma once
#include "StackItem.h"
#include <memory>


template<class T> class TStack {
public:
    TStack();
    TStack(const TStack<T>& ori);
	void Push(std::shared_ptr<T>& figure);
	std::shared_ptr<T> Pop();
    bool Empty();
	template<class T> friend std::ostream& operator<<(std::ostream& os, const TStack<T>& stack);
    ~TStack();

private:
	
std::shared_ptr<StackItem<T>> head;
};

template<class T>
TStack<T>::TStack() : head(nullptr) {
}

template<class T>
TStack<T>::TStack(const TStack<T>& orig) {
	head = orig.head;
}

template<class T>
void TStack<T>::Push(std::shared_ptr<T>& figure) {
	std::shared_ptr<StackItem<T>> new_head(new StackItem<T>);
	new_head->figure = figure;
	new_head->next = head;
	head = new_head;
}

template<class T>
bool TStack<T>::Empty() {
	return head == nullptr;
}

template<class T>
std::shared_ptr<T> TStack<T>::Pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		result = head->figure;
		head = head->next;
	}
	return result;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<StackItem<T>> item = stack.head;
	while (item != nullptr) {
		os << "[";
		item->figure->Print();
		os << "]";
		item = item->next;
	}
	return os;
}

template<class T>
TStack<T>::~TStack() {
}

