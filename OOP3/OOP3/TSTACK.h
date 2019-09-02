#pragma once
 #include "StackItem.h"
#include <memory>

class TStack {
public:
    TStack();
    TStack(const TStack& orig);
	void Push(std::shared_ptr<Figure>& figure);
	std::shared_ptr<Figure> Pop();
    bool Empty();
    friend std::ostream& operator<<(std::ostream& os, const TStack& stack);
    ~TStack();

private:
	std::shared_ptr<StackItem> head;
};

