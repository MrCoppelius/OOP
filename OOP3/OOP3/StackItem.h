#pragma once
#include <memory>
#include "Figure.h"
struct StackItem {
	std::shared_ptr<Figure> figure;
	std::shared_ptr<StackItem> next;
};