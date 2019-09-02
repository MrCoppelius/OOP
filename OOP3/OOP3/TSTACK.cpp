#include "TSTACK.h"
#include <memory>

TStack::TStack() : head(nullptr){
}

TStack::TStack(const TStack& orig){
    head = orig.head;
}

void TStack::Push(std::shared_ptr<Figure>& figure) {
	std::shared_ptr<StackItem> new_head(new StackItem);
	new_head->figure = figure;
	new_head->next = head;
	
	head = new_head;
	
}

bool TStack::Empty() {
    return head == nullptr;
}

std::shared_ptr<Figure> TStack::Pop() {
	std::shared_ptr<Figure> result;
    if (head!=nullptr) {
        result = head->figure;
		head = head->next;
	}
    return result;
}

std::ostream& operator<<(std::ostream& os, const TStack& stack) {
	std::shared_ptr<StackItem> item = stack.head;
    while (item != nullptr) {
		os << "[";
		item->figure->Print();
		os << "]";
        item = item->next;
    }
    return os;
}

TStack::~TStack() {
}