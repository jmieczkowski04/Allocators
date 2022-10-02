#include "StackAllocator.h"
#include <malloc.h>
#include <assert.h>

StackAllocator::StackAllocator(uint32 StackSize) : memSize(StackSize), usedMem(0), bShouldFree(true)
{
	mem = new uint8[memSize];
	
	stackTop = mem;
}

StackAllocator::StackAllocator(uint8* Mem, uint32 Size, bool ShouldFree) : memSize(Size), usedMem(0), bShouldFree(ShouldFree), mem(Mem)
{
	stackTop = mem;
}

StackAllocator::~StackAllocator()
{
	if(bShouldFree)
		delete mem;
}

uint8* StackAllocator::alloc(uint32 size)
{
	assert(memSize > usedMem + size);

	uint8* out = stackTop;
	usedMem += size;
	stackTop = stackTop + size;

	return out;
}

void StackAllocator::Clear()
{
	usedMem = 0;
	stackTop = mem;
}

StackAllocator::Marker StackAllocator::GetCurrentMarker()
{
	Marker marker;
	marker.pointer = stackTop;
	marker.used = usedMem;
	return marker;
}

void StackAllocator::ClearToMarker(Marker marker)
{
	uint8* newTop = marker.pointer;
	assert((newTop >= mem) && (newTop <= stackTop));
	stackTop = newTop;
	usedMem = marker.used;
}

uint32 StackAllocator::GetAllocetedMem()
{
	return usedMem;
}

uint32 StackAllocator::GetMaximumMem()
{
	return memSize;
}
