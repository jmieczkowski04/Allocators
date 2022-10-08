#include "PoolAllocator.h"
#include <cassert>


PoolAllocator::PoolAllocator(uint32 ElementSize, uint32 ElementCount) : elementSize(ElementSize), elementCount(ElementCount)
{
	assert(ElementSize > sizeof(NextFreeBlock));
	assert(ElementCount > 0);

	mem = new uint8[elementCount * elementSize];

	CreateFreeBlockList();
}

PoolAllocator::~PoolAllocator()
{
	delete mem;
}

void PoolAllocator::CreateFreeBlockList()
{
	usedBlocks = 0;
	NextFreeBlock* lastBlock = nullptr;
	for (uint32 i = elementCount; i != 0;)
	{
		NextFreeBlock* temp = lastBlock;
		lastBlock = (NextFreeBlock*)(mem + (elementSize * --i));
		lastBlock->NextBlock = temp;
	}
	nextBlock = lastBlock;
}

uint8* PoolAllocator::Alloc()
{
	assert(nextBlock != nullptr);
	uint8* Out = (uint8*)nextBlock;
	nextBlock = nextBlock->NextBlock;
	usedBlocks++;

	return Out;
}

void PoolAllocator::Free(uint8* Addr)
{
	//check if between mem and end of mem
	assert(Addr >= mem && Addr < (mem + (elementSize * elementCount)));
	//check if a multiple of elementSize
	assert((Addr - mem) % elementSize == 0);

	NextFreeBlock* newBlock = (NextFreeBlock*)mem;
	newBlock->NextBlock = nextBlock;
	nextBlock = newBlock;
	usedBlocks--;
}

void PoolAllocator::Clean()
{
	CreateFreeBlockList();
}

uint32 PoolAllocator::GetUsedBlocks()
{
	return usedBlocks;
}