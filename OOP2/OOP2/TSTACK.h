#pragma once
#include "Hexagon.h"
#include "StackItem.h"
class TStack {
public:
    TStack();
    TStack(const TStack& orig);
    void push(Hexagon &hexagon);
    Hexagon pop();
    bool empty();
    friend std::ostream& operator<<(std::ostream& os, const TStack& stack);
    ~TStack();

private:
    StackItem *head;
};

