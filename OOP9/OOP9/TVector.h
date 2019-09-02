#pragma once
#include <memory>

using namespace std;
template<class T>
class TVector
{
public:
	TVector();
	TVector(size_t size);
	TVector(const TVector<T>& orig);
	void push_back(shared_ptr<T>& element);
	size_t size();
	bool empty();
	shared_ptr<T>& operator[](int index);
	void remove(int index);
	void insert(int index, shared_ptr<T>& element);
	template<class T> friend std::ostream& operator<<(std::ostream& os, const TVector<T>& vector);
	void clean();

	~TVector();
protected:
	shared_ptr<T>* buffArray;
	size_t BuffLength;
	size_t currIndex;
};

template<class T>
TVector<T>::TVector() : buffArray(nullptr), BuffLength(0), currIndex(-1) {
}

template<class T>
TVector<T>::TVector(size_t size) {
	buffArray = new shared_ptr<T>[size];
	currIndex = -1;
	BuffLength = size;
}
template<class T>
TVector<T>::TVector(const TVector<T>& orig) {
	buffArray = new shared_ptr<T>[orig.BuffLength];
	for (int i = 0; i <= orig.currIndex; ++i) {
		buffArray[i] = orig.buffArray[i];
	}
	currIndex = orig.currIndex;
	BuffLength = orig.BuffLength;
}

template<class T>
void TVector<T>::push_back(shared_ptr<T>& element) {
	if (!BuffLength) {
		buffArray = new shared_ptr<T>[8];
		BuffLength = 8;
		currIndex = 0;
		buffArray[currIndex] = element;
		
	}
	else if ((currIndex+1)==BuffLength){
		shared_ptr<T>* newBuffArray = new shared_ptr<T>[BuffLength * 2];
		for (size_t i = 0; i <= currIndex; ++i) {
			newBuffArray[i] = buffArray[i];
		}
		delete buffArray;
		buffArray = newBuffArray;
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
size_t TVector<T>::size() {
	return currIndex+1;
}

template<class T>
bool TVector<T>::empty() {
	return (currIndex == 0);
}

template<class T>
shared_ptr<T>& TVector<T>::operator[](int index) {
	
	return buffArray[index];
}

template<class T>
void TVector<T>::clean() {
	delete[] buffArray;
	BuffLength = 0;
	currIndex = -1;
}

template<class T>
void TVector<T>::remove(int index) {

	for (int i = index; i < currIndex; ++i) {
		buffArray[i] = buffArray[i + 1];
	}
	buffArray[currIndex] = nullptr;
	--currIndex;
}

template<class T>
void TVector<T>::insert(int index, shared_ptr<T>& element) {
	if (!BuffLength) {
		push_back(element);
		return;
	}
	if ((currIndex + 1) == BuffLength) {
		shared_ptr<T>* newBuffArray = new shared_ptr<T>[BuffLength * 2];
		for (size_t i = 0; i <= currIndex; ++i) {
			newBuffArray[i] = buffArray[i];
		}
		delete buffArray;
		buffArray = newBuffArray;
		BuffLength = BuffLength * 2;
	}
	for (int i = currIndex + 1; i > index; --i) {
		buffArray[i] = buffArray[i - 1];
	}
	buffArray[index] = element;
	++currIndex;
}

template<class T>
ostream& operator<<(std::ostream& os, const TVector<T>& vector) {
	
	for (size_t i = 0; i<=vector.currIndex; ++i) {
		os << "[" << *vector.buffArray[i]  << "]";
	}
	return os;
}


template<class T>
TVector<T>::~TVector() {
	delete[] (buffArray);
}

