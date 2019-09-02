#pragma once
#include <memory> 
#include <iostream>

template <class Node , class T>
class TIterator {
public:
	TIterator() {
		node_ptr = nullptr;
	}

	TIterator(std::shared_ptr<Node> node) {
		node_ptr = node;
	}
	std::shared_ptr<T> operator * () {
		return node_ptr->figure;
	}
	std::shared_ptr<T> operator -> () {
		return node_ptr->figure;
	}
	void operator ++ () {
		node_ptr = node_ptr->next;
	}
	TIterator operator ++ (int) {
		TIterator tmp(*this);
		++(*this);
		return tmp;
	}
	bool operator == (TIterator const& i) {
		return node_ptr == i.node_ptr;
	}
	bool operator != (TIterator const& i) {
		return !(node_ptr == i.node_ptr);
	}
private:
	std::shared_ptr<Node> node_ptr;
};