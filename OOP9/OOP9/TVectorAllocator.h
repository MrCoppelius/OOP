#pragma once

#include <memory>

using namespace std;
template<class T>
class TVeactorAllocator
{
public:
	TVeactorAllocator();
	TVeactorAllocator(size_t size);
	TVeactorAllocator(const TVeactorAllocator<T>& orig);
	void push_back(T element);
	size_t size();
	bool empty();
	T& operator[](int index);
	template<class T> friend std::ostream& operator<<(std::ostream& os, const TVeactorAllocator<T>& vector);
	void clean();
	~TVeactorAllocator();
private:
	T* buffArray;
	size_t BuffLength;
	size_t currIndex;
};

template<class T>
TVeactorAllocator<T>::TVeactorAllocator() : buffArray(nullptr), BuffLength(0), currIndex(0) {
}

template<class T>
TVeactorAllocator<T>::TVeactorAllocator(size_t size) {
	buffArray = (T*)malloc(sizeof(T)*size);
	currIndex = 0;
	BuffLength = size;
}
template<class T>
TVeactorAllocator<T>::TVeactorAllocator(const TVeactorAllocator<T>& orig) {
	buffArray = (T*)malloc(sizeof(T)*orig.currIndex);
	for (int i = 0; i <= orig.currIndex; ++i) {
		buffArray[i] = orig.buffArray[i];
	}
	currIndex = orig.currIndex;
	BuffLength = orig.BuffLength;
}

template<class T>
void TVeactorAllocator<T>::push_back(T element) {
	if (!BuffLength) {
		buffArray = (T*)malloc(sizeof(T)*8);
		BuffLength = 8;
		currIndex = 0;
		buffArray[currIndex] = element;
		
	}
	else if ((currIndex+1)==BuffLength){
		buffArray = (T*)realloc(buffArray, sizeof(T)*BuffLength * 2);
		BuffLength = BuffLength * 2;
		++currIndex;
		buffArray[currIndex] = element;
	}
	else {
		++currIndex;
		buffArray[currIndex] = element;
	}
}

template<class T>
size_t TVeactorAllocator<T>::size() {
	return currIndex+1;
}

template<class T>
bool TVeactorAllocator<T>::empty() {
	return (currIndex == 0);
}

template<class T>
T& TVeactorAllocator<T>::operator[](int index) {
	
	
	return buffArray[index];
}

template<class T>
void TVeactorAllocator<T>::clean() {
	free(buffArray);
	BuffLength = 0;
	currIndex = 0;
}

template<class T>
ostream& operator<<(std::ostream& os, const TVeactorAllocator<T>& vector) {
	
	for (size_t i = 0; i<=vector.currIndex; ++i) {
		os << "[";
		vector.buffArray[i]->Print();
		os << "]";
	}
	return os;
}


template<class T>
TVeactorAllocator<T>::~TVeactorAllocator() {
	delete (buffArray);
}

