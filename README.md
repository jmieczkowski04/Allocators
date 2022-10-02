# Memory allocators

Small project, which provides custom memory allocators. Currently support only stack and double stack allocators. Additionaly, the project includes generic type redefinition.

## Features

### Stack Allocator
- Initialization with size or pointer to memory
- Allocating memory
- Clearing the stack
- Saving and restoring memory usage to Marker
- Getting statistic of memory usage

### Double Stack Allocator
- Initialization with size or pointer to memory
- Allocating memory from both tops of stack
- Clearing the stack
- Saving and restoring memory usage to Marker
- Getting statistic of memory usage

## Usage
Import project from Allocators directory to your VS solution and add Allocators/include directory to your project. Then include allocator you want to use and create an instance of Allocator class.