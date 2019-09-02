#pragma once
#include "TItearator.h"
#include "StackItem.h"



template<class T> class TStack {
public:
    TStack();
    TStack(const TStack<T>& orig);
	void Push(std::shared_ptr<T>& element);
	std::shared_ptr<T> Pop();
    bool Empty();
	template<class T> friend std::ostream& operator<<(std::ostream& os, const TStack<T>& stack);
	TIterator<StackItem<T>, T> begin();
	TIterator<StackItem<T>, T> end();
	~TStack();

protected:
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
void TStack<T>::Push(std::shared_ptr<T>& element) {
	std::shared_ptr<StackItem<T>> new_head(new StackItem<T>);
	new_head->element = element;
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
		result = head->element;
		head = head->next;
	}
	return result;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<StackItem<T>> item = stack.head;
	while (item != nullptr) {
		os << "[" << *item->element << item->element->Square() << "]" << endl;
		item = item->next;
	}
	return os;
}

template <class T> 
TIterator<StackItem<T>, T> TStack<T>::begin() {
	return TIterator<StackItem<T>, T>(head); 
} 

template <class T>
TIterator<StackItem<T>, T> TStack<T>::end() {
	return TIterator<StackItem<T>, T>(nullptr);
}

template<class T>
TStack<T>::~TStack() {
}

