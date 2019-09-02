#include "TSTACK.h"
#include <memory>


template<class T>
TStack<T>::TStack() : head(nullptr){
}

template<class T>
TStack<T>::TStack(const TStack<T>& orig){
    head = orig.head;
}

template<class T>
void TStack<T>::Push(std::shared_ptr<T>& element) {
	std::shared_ptr<StackItem> new_head(new StackItem);
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
    if (head!=nullptr) {
        result = head->element;
		head = head->next;
	}
    return result;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<StackItem> item = stack.head;
    while (item != nullptr) {
		os << "[";
		item->element->Print();
		os << "]";
        item = item->next;
    }
    return os;
}

template<class T>
TStack<T>::~TStack() {
}