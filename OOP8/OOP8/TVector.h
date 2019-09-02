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
	void push_back(T element);
	size_t size();
	bool empty();
	T& operator[](int index);
	template<class T> friend std::ostream& operator<<(std::ostream& os, const TVector<T>& vector);
	void clean();
	~TVector();
private:
	T* buffArray;
	size_t BuffLength;
	size_t currIndex;
};

template<class T>
TVector<T>::TVector() : buffArray(nullptr), BuffLength(0), currIndex(0) {
}

template<class T>
TVector<T>::TVector(size_t size) {
	buffArray = (T*)malloc(sizeof(T)*size);
	currIndex = 0;
	BuffLength = size;
}
template<class T>
TVector<T>::TVector(const TVector<T>& orig) {
	buffArray = (T*)malloc(sizeof(T)*orig.currIndex);
	for (int i = 0; i <= orig.currIndex; ++i) {
		buffArray[i] = orig.buffArray[i];
	}
	currIndex = orig.currIndex;
	BuffLength = orig.BuffLength;
}

template<class T>
void TVector<T>::push_back(T element) {
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
size_t TVector<T>::size() {
	return currIndex+1;
}

template<class T>
bool TVector<T>::empty() {
	return (currIndex == 0);
}

template<class T>
T& TVector<T>::operator[](int index) {
	
	
	return buffArray[index];
}

template<class T>
void TVector<T>::clean() {
	free(buffArray);
	BuffLength = 0;
	currIndex = 0;
}

template<class T>
ostream& operator<<(std::ostream& os, const TVector<T>& vector) {
	
	for (size_t i = 0; i<=vector.currIndex; ++i) {
		os << "[";
		vector.buffArray[i]->Print();
		os << "]";
	}
	return os;
}


template<class T>
TVector<T>::~TVector() {
	delete (buffArray);
}

