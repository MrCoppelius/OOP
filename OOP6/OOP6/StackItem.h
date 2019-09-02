#pragma once
#include <memory>
#include "TAllocBlock.h"
#define SIZE 1024

template<class T>
class StackItem {
public:
	std::shared_ptr<T> element;
	std::shared_ptr<StackItem> next;
	void* operator new (size_t size); 
	void operator delete(void *ptr);
private:
	static  TAllocBlock  stackItemAllocator;
};

template <class T> 
void* StackItem<T>::operator new (size_t size) {
	return stackItemAllocator.allocate();
}
template <class T> 
void StackItem<T>::operator delete(void *p) { 
	stackItemAllocator.deallocate(p);
}

template<class T>  
TAllocBlock StackItem<T>::stackItemAllocator(sizeof(StackItem<T>), SIZE);