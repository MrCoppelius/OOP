#include "TAllocBlock.h"

TAllocBlock::TAllocBlock(size_t _sizeOfOneBlock, size_t _maxBlocks) : sizeOfOneBlock(_sizeOfOneBlock), maxBlocks(_maxBlocks){
	allocBlocks = (char*)malloc(sizeOfOneBlock*maxBlocks);
	for (size_t i = 0; i < maxBlocks; ++i) {
		ptrToFreeBlocks.push_back(allocBlocks + i*sizeOfOneBlock);
	}
	freeCount = maxBlocks;
}

void* TAllocBlock::allocate() {
	void *result = nullptr; 
	if (freeCount>0){
		result = ptrToFreeBlocks[freeCount - 1];
		--freeCount;
	}
	return result;
}
void TAllocBlock::deallocate(void* ptr) {
	ptrToFreeBlocks[freeCount] = ptr; 
	freeCount++;
}

TAllocBlock::~TAllocBlock(){
	delete allocBlocks;
}
