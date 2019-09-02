#include "TSTACK.h"

TStack::TStack() : head(nullptr){
}

TStack::TStack(const TStack& orig){
    head = orig.head;
}

void TStack::push(Hexagon &hexagon) {
    StackItem *new_head = new StackItem;
    new_head->hexagon = hexagon;
    new_head->next = head;
    head = new_head;
}

bool TStack::empty() {
    return head == nullptr;
}
Hexagon TStack::pop() {
    Hexagon result;
    if (head!=nullptr) {
        result = head->hexagon;
        StackItem *old_head = head;
        head = old_head->next;
        delete old_head;
    }
    
    return result;
    }

std::ostream& operator<<(std::ostream& os, const TStack& stack) {
    StackItem *item = stack.head;
    while (item != nullptr) {
        os << item->hexagon;
        item = item->next;
    }
    return os;
}

TStack::~TStack() {
    StackItem* old_head;
    while (head != nullptr) {
        old_head = head;
        head = head->next;
        delete old_head;
    }
}