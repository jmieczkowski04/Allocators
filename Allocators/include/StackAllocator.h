#pragma once

#include "GenericTypes.h"

class StackAllocator
{
public:
	class Marker
	{
	private:
		uint8* pointer;
		uint32 used;
		friend class StackAllocator;
	};

public:
	StackAllocator(uint32 StackSize);
	StackAllocator(uint8* Mem, uint32 Size, bool ShouldFree = false);
	~StackAllocator();

	uint8* alloc(uint32 Size);
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
	uint8* stackTop;
};