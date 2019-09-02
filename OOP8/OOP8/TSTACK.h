#pragma once
#include "TItearator.h"
#include "StackItem.h"
#include <future>


template<class T> class TStack {
public:
	TStack();
	TStack(const TStack<T>& orig);
	void Push(std::shared_ptr<T>& element);
	std::shared_ptr<T> Pop();
	bool Empty();
	size_t Size();
	template<class T> friend std::ostream& operator<<(std::ostream& os, const TStack<T>& stack);
	void ParallelQuickSort();
	void QuickSort();
	TIterator<StackItem<T>, T> begin();
	TIterator<StackItem<T>, T> end();
	~TStack();

protected:
	size_t size;
	std::shared_ptr<StackItem<T>> head;
};

template<class T>
TStack<T>::TStack() : head(nullptr), size(0) {
}

template<class T>
TStack<T>::TStack(const TStack<T>& orig) {
	head = orig.head;
	size = orig.size;
}

template<class T>
void TStack<T>::Push(std::shared_ptr<T>& element) {
	std::shared_ptr<StackItem<T>> new_head(new StackItem<T>);
	new_head->element = element;
	if (!size) {
		new_head->next = nullptr;
		head = new_head;
	}
	else {
		new_head->next = head;
		head = new_head;
	}
	new_head->element = element;
	
	++size;
}

template<class T>
size_t TStack<T>::Size() {
	return size;
}

template<class T>
bool TStack<T>::Empty() {
	return size == 0;
}

template<class T>
std::shared_ptr<T> TStack<T>::Pop() {
	std::shared_ptr<T> result = nullptr;
	if (size) {
		result = head->element;
		head = head->next;
		--size;
	}
	
	return result;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<StackItem<T>> item = stack.head;
	while (item != nullptr) {
		os << "[" << *item->element << "]" << endl;
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



template <class T>
void TStack<T>::QuickSort() {
	if (size > 1) {
		TStack<T> right;
		TStack<T> left;
		TStack<T> tmpStack;
		shared_ptr<T> figurPat;
		shared_ptr<T> figurIt;
		figurPat = Pop();
		double patSquare;
		patSquare = figurPat->Square();
		while (!Empty()) {
			figurIt = Pop();
			if (figurIt->Square() >= patSquare) {
				right.Push(figurIt);
			}
			else {
				left.Push(figurIt);
			}
		}
		right.QuickSort();
		left.QuickSort();
		while (!right.Empty()) {
			tmpStack.Push(right.Pop());
		}
		while (!tmpStack.Empty()) {
			Push(tmpStack.Pop());
		}
		Push(figurPat);
		while (!left.Empty()) {
			tmpStack.Push(left.Pop());
		}
		while (!tmpStack.Empty()) {
			Push(tmpStack.Pop());
		}
	}
}

template <class T>
void TStack<T>::ParallelQuickSort() {
	if (size > 1) {
		TStack<T> right;
		TStack<T> left;
		TStack<T> tmpStack;
		shared_ptr<T> figurPat;
		shared_ptr<T> figurIt;
		figurPat = Pop();
		double patSquare;
		patSquare = figurPat->Square();
		while (!Empty()) {
			figurIt = Pop();
				if (figurIt->Square() >= patSquare) {
					right.Push(figurIt);
				}
				else {
					left.Push(figurIt);
			}
		}
		future<void> rightResult =  async(std::launch::async, &TStack<T>::ParallelQuickSort, &right);
		future<void> leftResult = async(std::launch::async, &TStack<T>::ParallelQuickSort, &left);
		rightResult.wait();
		while (!right.Empty()) {
			tmpStack.Push(right.Pop());
		}
		while (!tmpStack.Empty()) {
			Push(tmpStack.Pop());
		}
		 Push(figurPat);
		leftResult.wait();
		while (!left.Empty()) {
			tmpStack.Push(left.Pop());
		}
		while (!tmpStack.Empty()) {
			Push(tmpStack.Pop());
		}
	}
}

