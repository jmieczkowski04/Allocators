#include "DoubleStackAllocator.h"
#include <malloc.h>
#include <assert.h>

DoubleStackAllocator::DoubleStackAllocator(uint32 StackSize) : memSize(StackSize), usedMem(0), bShouldFree(true)
{
	mem = new uint8[memSize];

	lowStackTop = mem;
	hiStackTop = mem + memSize;
}

DoubleStackAllocator::DoubleStackAllocator(uint8* Mem, uint32 Size, bool ShouldFree) : memSize(Size), usedMem(0), bShouldFree(ShouldFree), mem(Mem)
{
	lowStackTop = mem;
	hiStackTop = mem + memSize;
}

DoubleStackAllocator::~DoubleStackAllocator()
{
	if(bShouldFree)
		delete mem;
}

uint8* DoubleStackAllocator::allocLow(uint32 Size)
{
	assert(hiStackTop > lowStackTop + Size);

	uint8* out = lowStackTop;
	usedMem += Size;
	lowStackTop = lowStackTop + Size;

	return out;
}

uint8* DoubleStackAllocator::allocHi(uint32 Size)
{
	assert(lowStackTop < hiStackTop - Size);

	uint8* out = hiStackTop - Size;
	usedMem += Size;
	hiStackTop = out;

	return out;
}

void DoubleStackAllocator::Clear()
{
	usedMem = 0;
	lowStackTop = mem;
	hiStackTop = mem + memSize;
}

DoubleStackAllocator::Marker DoubleStackAllocator::GetCurrentMarker()
{
	Marker marker;
	marker.lowPointer = lowStackTop;
	marker.hiPointer = hiStackTop;
	marker.used = usedMem;
	return marker;
}

void DoubleStackAllocator::ClearToMarker(Marker Marker)
{
	uint8* newLowTop = Marker.lowPointer;
	uint8* newHiTop = Marker.hiPointer;
	assert((newLowTop >= mem) && (newHiTop <= mem + memSize) && (newLowTop <= lowStackTop) && (newHiTop >= hiStackTop));
	lowStackTop = newLowTop;
	hiStackTop = newHiTop;
	usedMem = Marker.used;
}

uint32 DoubleStackAllocator::GetAllocetedMem()
{
	return usedMem;
}

uint32 DoubleStackAllocator::GetMaximumMem()
{
	return memSize;
}
