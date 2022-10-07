#pragma once

#include "GenericTypes.h"

class DoubleStackAllocator
{
public:
	class Marker
	{
	private:
		uint8* lowPointer;
		uint8* hiPointer;
		uint32 used;
		friend class DoubleStackAllocator;
	};

public:
	DoubleStackAllocator(uint32 StackSize);
	DoubleStackAllocator(uint8* Mem, uint32 Size, bool ShouldFree = false);
	~DoubleStackAllocator();

	uint8* allocLow(uint32 Size);
	uint8* allocHi(uint32 Size);
	void Clear();

	Marker GetCurrentMarker();
	void ClearToMarker(Marker Marker);

	uint32 GetAllocetedMem();
	uint32 GetMaximumMem();

private:
	bool bShouldFree;
	uint32 memSize;
	uint32 usedMem;
	uint8* mem;
	uint8* hiStackTop;
	uint8* lowStackTop;
};