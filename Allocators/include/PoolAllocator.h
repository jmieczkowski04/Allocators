#pragma once

#include "GenericTypes.h"

class PoolAllocator
{
private:
	struct NextFreeBlock
	{
		NextFreeBlock* NextBlock;
	};
public:
	PoolAllocator(uint32 ElementSize, uint32 ElementCount);
	~PoolAllocator();

	uint8* Alloc();
	void Free(uint8* Addr);
	void Clean();
	uint32 GetUsedBlocks();

private:
	void CreateFreeBlockList();

	uint32 usedBlocks;

	uint8* mem;
	uint32 elementSize;
	uint32 elementCount;
	NextFreeBlock* nextBlock;
};