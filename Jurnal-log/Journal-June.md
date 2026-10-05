# C++ Learning Journal: 42 CPP Modules
 
A chronicle of my journey through C++ fundamentals, from basic CPP concepts to advanced polymorphism and memory management.
 
---
 
## Module Overview
 
| Module | Duration | Focus Area                 |
|--------|----------|----------------------------|
| CPP05  | 2 days   |		Exceptions			 |
| CPP06  | 2 days   |  	  	Casting				 |
| CPP07  | 3 days   |  		templates 				 |
| CPP08  | 6 days   |  |
| CPP09  | 6 days   |  |

## CASTING

How I handle data: conversion of **scalar types** -> single value

	- arithmetic - int, float, double, char, bool
	- enumerations - enum
	- Pointers - int*, char*, void*, obj pointers
	- pointers to memebers

# 4 casts:
	1. static_cast<type>(value)
		handles supported explicit conversions; numeric bounds and downcast validity are still the programmer's responsibility
		it navigates upcasting - class hierarchies
		the compiler checks whether the conversion is allowed, not whether every runtime value is safe
	2. dynamic_cast<type>(value) : polymorphic cast
		casts pointers and references witihn an inheritance hierarchy (downcasting) : dealing with base and derived classes
		high safety level - checked at runtime - returning NULL pointer - or throw exep for references
	3. const_cast<type>(value)
		adds/removes const or volatile qualifiers from variable
		used with const pointers/references that must be passed to API that expects non-const pointer
		medium safety level - modifying an originally const value results undefined behaviour
	4. reinterpret_cast<type>(value)
		low-level permitted representation conversions such as an address/integer round trip
		does not remove constness, create an object, or permit arbitrary access through an unrelated type

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

`static convert()` means the function belongs to the class and has no `this` pointer. This alone does not make the class non-instantiable; access control or deleted constructors can do that.

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
		The behavior is undefined if the value if ch is not representable as unsigned char and is not equal to EOF
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

ex:00

# architecture: 
solution for helper fucntions option 1 - **anonymus namespace**
namespace {pervent naming collisions}

solution option 2 - **internal linkage** - static functions

Detection:  process of elimination

# NaN — a floating-point "not a number" value, not uninitialized storage
	Under ordinary IEEE behavior, `x != x` is true for NaN. Equality and ordered comparisons with NaN are false; inequality is true. C++11 `std::isnan` expresses the check directly. NaN is not safe to convert to an integer.



conversion:
Standard C++ scalar conversion truncates floating-point numbers when casting to integer types. - char becomes ASCII

ex01: 
# type punning/ raw mem reinterpret.

reinterpret_cast<type> :
serialize: treat mem add as positive number
deserialize: the reverse
safety:
 => `uintptr_t` from `<cstdint>` in C++11 (or the applicable `<stdint.h>` extension in a C++98 environment)
 	*unsigned int ptr type*
When provided, this unsigned integer type can represent a void pointer for a supported round trip; it need not have exactly the pointer's size. The original object must still be alive when its recovered pointer is used. An address is not persistent serialization and cannot be reused across arbitrary process runs.

# webserv reference: OS API meets c++ (epoll event loop exapmle)
	how server handles multiple connections
	
	OS gives a struct to register events: - provides generic field to attach user 	data - 64 int or void*	
	
	struct os_event {
		uint32_t event_type;
		uint64_t user_data;
	}
	execution - Client obj lifecycle through OS kernel and back
	
	class Client {
		public:
		int socket_fd;
		std::string request_buffer;
	
		void handleIncomingData()
		std::cout << "handle data for socket: " << socket_fd << std::endl;
	}
	
	Client *newClientConnectrion* = new Client();
	newClientConnection->socket_fd = 5;
	
	at this point we want OS to inform when socket 5 has incoming data - os_event config struct -> serializer logic useful

	struct os_event ev;
	ev.event_type = 1;
	ev.usr_data = reinterpret_cast<uintptr_t>(newClient);
	register_event_with_os(newClient->socket_fd, &ev);

	we cast pinter to int and hand it off to OS kernel that puts it into queue and goes to sleep- wakes up when socket 5 has data.

	after client sends HTTP GET request OS sneds list of active events:


ex02:
# RunTime type identification - RTTI
**dynamic_cast & software architecture concept: polymorphism**

	* hiding a specific object behind a generic base pointer: Heterogeneous Collections - This makes code infinitely scalable.

polymorphism means - having a base class that covers the subclasses object's type. The way for compiler to find out about the type is by dynamic_casting/

because the generate() returns a pointer to base class - we can't know what obj was created.

# Polymorphic base and virtual destructor
 - Runtime-checked hierarchy downcasts require a polymorphic base: one or more virtual functions. A virtual destructor is one way to satisfy that and is needed for safe deletion of derived objects through an owning base pointer. It is not the only virtual function that enables dynamic_cast.
 - A vtable is a common implementation technique, not a C++ language requirement; avoid assuming a specific memory layout.

then we identify by pointer or by reference:

1- by passing the pointer

2- by reference - we pass an obj in a try/catch block - bc cannot return nullptr, we need to throw exception (std::bad_cast) to move to next type.

casting by pointer is asking a question, and looking at the answer.
by reference we don't store the answer we just wait for the try/catch block to react, so casting needs to e silenced with (void), because we don't care abput return value;

## CPP06 — parsing and conversion gaps to practice

### Parsing is a separate contract

Define the accepted grammar: sign, digits, decimal point, optional exponent if required, and float suffix. Check empty input before indexing it. For stoi/stof/stod, inspect the consumed position when accepting general user input; successful conversion alone can accept a valid prefix followed by junk. For strtol/strtod, inspect the end pointer and range-error reporting. Decide how whitespace and trailing characters are handled.

Pass character-classification inputs as unsigned char values (or EOF), including isdigit and isprint. A negative signed char is not a valid argument to these functions.

### Floating-to-integer conversion

Conversion truncates toward zero, but the truncated result must fit the destination. NaN/infinity and out-of-range finite values are not safe casts. Guard every conversion, including those used only for formatting. A float representation of INT_MAX can round upward; avoid treating that rounded value as an exact safe boundary.

The review reproduced an out-of-range cast in ScalarConverter's double-formatting condition using `1000000000000.0`. Checking and printing "int: impossible" earlier does not protect a later independent cast. Use a floating-point test for a fractional part and separate presentation from conversion.

### RTTI and lifetime

A failed pointer downcast returns null; a failed reference downcast throws std::bad_cast. A successful cast verifies type compatibility at that moment, not ownership or lifetime. Deleting the object still invalidates all observing pointers/references. `dynamic_cast<void*>` has a special most-derived-object role; it is distinct from identifying a specific subclass.

### Validation checklist

- Single character, signed number, decimal value, permitted special literals.
- Empty input, malformed decimal/suffix, trailing junk, and non-ASCII character classification.
- Exact and nearby integer limits, large finite values, NaN/infinity, and fractional values.
- Serializer round trip within one live object's lifetime; never dereference an expired pointer.
- Successful and failed RTTI identification by pointer and by reference.

See [Code-review.md](Code-review.md) for the observed converter diagnostic and [basics.MD](basics.MD) for the four casts.
