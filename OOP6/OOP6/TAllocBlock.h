#pragma once
#include "TVector.h"
#include <memory>
#include <iostream>


class TAllocBlock{
public:
	TAllocBlock(size_t _sizeOfOneBlock, size_t _maxBlocks);
	void* allocate();
	void deallocate(void* ptr);
	size_t sizeOfOneBlock, freeCount, maxBlocks;
	~TAllocBlock();
private:
	char *allocBlocks;
	TVector<void*> ptrToFreeBlocks;
};

