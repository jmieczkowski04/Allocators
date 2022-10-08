#pragma once

#include "GenericTypes.h"
#include <cstdint>

class AlignAllocator
{
public:
	static uint8* Alloc(uint32 Size, uint32 Align);

	static void Free(uint8* Addr);
private:
	static uint8* AlignAddr(uintptr_t Addr, size_t Align);
};