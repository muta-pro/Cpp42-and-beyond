## CASTING

How I handle data: conversion of **scalar types** -> single value

	- arithmetic - int, float, double, char, bool
	- enumerations - enum
	- Pointers - int*, char*, void*, obj pointers
	- pointers to memebers

# 4 casts:
	1. static_cast<type>(value)
		handles all standard, logical and safe conversions
		it navigates upcasting - class hierarchies
		high safety level - compiler checks conversion at compile time
	2. dynamic_cast<type>(value) : polymorphic cast
		casts pointers and references witihn an inheritance hierarchy (downcasting) : dealing with base and derived classes
		high safety level - checked at runtime - returning NULL pointer - or throw exep for references
	3. reinterpret_cast<type>(value) 
		adds/removes const or volatile qualifiers from variable
		used with const pointers/references that must be passed to API that expects non-const pointer
		medium safety level - modifying an originally const value results undefined behaviour

Rule : defend my intent

C++11 & 17 <string>
std::stoi or std::stof ot std::stod ->functions throw errors
auto
std::string_view

C++98 parsing
std::strtod <cstdlib> string to double or std::strtol to long
std::stringstream

	string parsing vs casting
-> to cast a string into any value - first must be parsed into numeric type and then cast that type to other numeric types.

static convert() - means it belongs to class not obj. so not instantiable - does not have a *this pointer*.

 ->modern c++ handles differently the errors and parses the string;

# identification flowchart - 
	1 - pseudo literals:	nanf, +inff, -inff -> float
							nan, +inf, -inf -> double
	2 - char:	str len 1 && not a digit
	3 - int:	str len 1 , index 0 -/+ && digit
	4 - float:	index 0 +/-, has decimal point, digits and end with f
	5 - double:	like float but no f
	6 - overflow
	7 - non displayable - control char (0-31ASCII)
		<cctype> std::isprint() 
		int isprint(int ch) - classifies the char if printable
		return 1, or return 0 if not
		The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF
		- for safety always use arg converted to unsigned char
*bool my_isprint(char ch)
{
    return std::isprint(static_cast<unsigned char>(ch));
}*
also if used in algorithms when iterator value is non unsigned char.

# handling numeric limits <limits>
	to check max allowable values before cast: 
	std::numeric_limits<int>max()/min()
overflow:
- parsing -> if too big std::stoi autmatically throws out_of_range exception
- downcasting -> from double to int/float: <limits>

# architecture: 
solution for helper fucntions option 1 - **anonymus namespace**
namespace {pervent naming collisions}

solution option 2 - **internal linkage** - static functions

Detection:  process of elimination

conversion:
Standard C++ scalar conversion truncates floating-point numbers when casting to integer types. - char becomes ASCII

ex01: 
# type punning/ raw mem reinterpret.

reinterpret_cast<type> :
serialize: treat mem add as positive number
deserialize: the reverse
safety:
 => uintptr_t <cstdlib>
 	*unsigned int ptr type*
ensures the same size as pointer: never to lose data when casting

ex02:
# RunTime type identification
	dynamic_cast & polymorphism