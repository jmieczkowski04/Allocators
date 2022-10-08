# Memory allocators

Small project, which provides custom memory allocators. Currently support stack, double stack, pool and align allocators. Additionaly, the project includes generic type redefinition.

## Features

### Stack Allocator
- Initialization with size or additionaly pointer to memory
- Allocating memory
- Clearing the stack
- Saving and restoring memory usage to Marker
- Getting statistic of memory usage

### Double Stack Allocator
- Initialization with size or additionaly pointer to memory
- Allocating memory from both tops of stack
- Clearing the stack
- Saving and restoring memory usage to Marker
- Getting statistic of memory usage

### Pool Allocator
- Initialization with size of element and number of elements or additionaly pointer to memory
- Allocating and freeing memory
- Clearing pool
- Getting statistic of memory usage

### Align Allocator
- Allocating and freeing memory aligned to power of 2

## Usage
Import project from Allocators directory to your VS solution and add Allocators/include directory to your project. Then include allocator you want to use and create an instance of Allocator class.
