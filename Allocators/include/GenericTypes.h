#pragma once

/* 
	Generic types for all platforms 
	Based on: https://en.cppreference.com/w/cpp/language/types
*/


// Unsigned types


//8-bit unsigned integer
typedef unsigned char uint8;

//16-bit unsigned integer
typedef unsigned short int uint16;

//32-bit unsigned integer
typedef unsigned int uint32;

//64-bit unsigned integer
typedef unsigned long long uint64;


// Signed types


//8-bit signed integer
typedef signed char int8;

//16-bit signed integer
typedef signed short int int16;

//32-bit signed integer
typedef signed int int32;

//64-bit signed integer
typedef signed long long int64;


// Character types


//ANSI 8-bit character
typedef char ANSICHAR;

//Wide chartacter. Size is depended on platform's specification.
typedef wchar_t TCHAR;