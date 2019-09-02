#pragma once
#include <memory>
#include "TAllocBlock.h"
#define SIZE 11024

template<class T>
class StackItem {
public:
	std::shared_ptr<T> element;
	std::shared_ptr<StackItem> next;
	

};
