#include "StackAllocator.h"
#include "DoubleStackAllocator.h"
#include <cassert>
#include <string.h>
#include <stdio.h>

int main()
{
	{
		StackAllocator allocator(193);

		char text[] = "Lorem ipsum dolor sit amet, consectetur pharetra.a\0";

		char* tab = (char*)allocator.alloc(51);
		memcpy(tab, text, sizeof(char) * 51);

		char* kolonia = (char*)allocator.alloc(51);
		memcpy(kolonia, text, sizeof(char) * 51);


		printf("%s", tab);

		//state 1
		StackAllocator::Marker mark1 = allocator.GetCurrentMarker();

		uint8* someMem = allocator.alloc(80);
		allocator.ClearToMarker(mark1);
		//back to state 1

		printf("\n");
	}

	{
		DoubleStackAllocator allocator(193);

		char text[] = "Lorem ipsum dolor sit amet, consectetur pharetra.b";

		char* tab = (char*)allocator.allocLow((uint32)strlen(text)+1);
		memcpy(tab, text, sizeof(char) * (strlen(text) + 1));

		char* kolonia = (char*)allocator.allocHi((uint32)strlen(text) + 1);
		memcpy(kolonia, text, sizeof(char) * (strlen(text) + 1));


		printf("%s", tab);

		//state 1
		DoubleStackAllocator::Marker mark1 = allocator.GetCurrentMarker();

		uint8* someMem = allocator.allocLow(80);
		allocator.ClearToMarker(mark1);
		//back to state 1
	}
	
	
}
