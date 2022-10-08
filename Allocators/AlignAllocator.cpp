#include "AlignAllocator.h"
#include <cassert>


uint8* AlignAllocator::Alloc(uint32 Size, uint32 Align)
{
	uint8* mem = new uint8[Size + Align];

	uint8* alignedMem = AlignAddr((uintptr_t)mem, (size_t)Align);

	if (alignedMem == mem)
		alignedMem += Align;

	ptrdiff_t shift = alignedMem - mem;

	assert(shift > 0 && shift <= 256);

#pragma warning(push)
#pragma warning(disable: 4244)
	alignedMem[-1] = shift;
#pragma warning(pop)

	return alignedMem;
}

void AlignAllocator::Free(uint8* Addr)
{
	assert(Addr);
	uintptr_t shift = Addr[-1];
	if (shift == 0)
		shift = 256;
	uint8* mem = Addr - shift;
	delete mem;
}

uint8* AlignAllocator::AlignAddr(uintptr_t Addr, size_t Align)
{
	const size_t mask = Align - 1;
	assert((Align & mask) == 0);
	uintptr_t Out = (Addr + mask) & ~mask;
	return (uint8*)Out;
}