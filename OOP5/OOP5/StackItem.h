#pragma once
#include <memory>
#include "Figure.h"
template<class T>
struct StackItem {
	std::shared_ptr<T> figure;
	std::shared_ptr<StackItem> next;
	
};