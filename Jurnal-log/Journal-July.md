# C++ Learning Journal: 42 CPP Modules
 
A chronicle of my journey through C++ fundamentals, from basic CPP concepts to advanced polymorphism and memory management.
 
---
 
## Module Overview
 
| Module | Duration | Focus Area                 |
|--------|----------|----------------------------|
| CPP05  | 2 days   |		Exceptions			 |
| CPP06  | 2 days   |  		Casting				 |
| CPP07  | 7 days   |		Templates			 |
| CPP08  | 6 days   | 		STL & ALGOS          |
| CPP09  | 6 days   |  |

## templates: formula for a generic class/function that can work with any data type without repetition.

using a placeholder type : T;
# template arg deduction
type gets checked at compile time;

there are also value - parameters not only types;

# function templates:

when functions should perform identical operations on different data types;

# class templates:

used for data structures where internal logic is the same regardless of what data is being stored;

templates are used when:
- building containers - linkedlist, stack, queue - > class templates to hold anythyng

- generic algorythms - sorting/searching/swapping

- utility/conversion functions - overloading func

ex00:
optimisatoin:
For a C++11 swap experiment, **std::move** casts an expression to an xvalue so a move operation can be selected. It does not itself transfer ownership; the selected constructor or assignment decides what happens, and copying may still occur. Include `<utility>` directly. A C++98 swap uses copying instead.

expressions: lvalue and rvalue;
const T&
A concrete `T&&` rvalue-reference type normally binds to rvalues. A deduced `T&&` parameter in the appropriate function-template context is a forwarding reference and can bind to lvalues too; this is a separate C++11 topic.

ex01: two-template-param design: iter - apply function to every element - func passed as a value
iter - temp. func. : 2 levels of genericity: type to iterate over plus the behaviour over each element;
 function pointers: address to a fucntion

# const/non-const - if we pass a param as void(*f)(T&);
	-> we have a non const signatre that will break if we call print(cosnt T&); -> F: compiler decuces it as whatever we pass. it has to be something callable like function ();*

**A func that iterates over data without knowing the type of that data, and executes behaviour without knowing what behaviour is** both resolved at compile time;

print alone is a pattern bc pointing to no address - so print<type> is a concrete function - existing in memory with address. sometimes the compiler cannot deduce by itself so i make it explicit for the instantiation

# the syntax: void (*f) (const Point&);* 
shows a pointer f; it points to a funciton that returns void and has const Point& as param;

# <<operator teahces compiler how ot print point: 
	std::ostream& os — the stream on the left side of <<, usually std::cout
	const Point& p — the thing on the right side, your Point

# lambada - funciton with no name - just inline definition/ usa e getta

```cpp
iter(arr, len, [](const int& x) { std::cout << x; });
```

# sizeof(): returns bytes;
For an actual built-in array in scope, divide total bytes by `sizeof(arr[0])`; do not assume an element is four bytes. Once the array decays to a pointer, sizeof measures the pointer, not the original array length.

ex02: class template array - safe, dynamically allocated array that works with any data type; pervents overflows;

Dynamic allocation lets the exercise choose its element count at runtime. Automatic local objects can still have runtime initialization, and a local vector can own dynamic element storage. "Stack means known at compile time" is not an accurate lifetime rule.

Array<int> arr(n); - class manages the memory - allocated in the constructor;

deep copy is crucial to avoid pointing at the same memory; allocate new memory and copy the values;

because accessing arrays is familiar to native arrays, but class doesn't know yet how to use it - overload[] ;

assignment operator is used only when obj is assigned to other object, not int to an object;

## CPP07 — missing theory and stronger checks

### Declaration, deduction, instantiation

A template parameter is resolved when forming a specialization. Deduction uses the call's argument types; it is not a general search for a conversion that makes all arguments fit. In a two-argument same-type function, mixed int/double arguments may require an explicit choice or a different interface.

Definitions normally must be visible at the point of instantiation; use a header or an included .tpp. Dependent expressions may only be checked when a particular member is used. Header inclusion does not validate every possible specialization or member.

Genericity still has requirements: swap needs suitable construction/assignment; min/max need comparison; iter needs callable behavior compatible with each element expression. Modern concepts can name these requirements, but C++98 templates still have them without constraint syntax.

### ex00 — reference returns and lifetime

Returning a const reference avoids a copy and refers to one of the arguments. It does not extend an argument's lifetime. A reference returned from min/max on temporary values can dangle after the full expression ends. Use live named objects in tests, and understand the return contract before retaining it.

Test equal values as well as unequal ones; the specified tie behavior can require returning a particular argument. A user-defined comparable type should also work. Qualifying `::min`/`::swap` deliberately selects the global exercise function and avoids ADL ambiguity.

### ex01 — callable and const deduction

`T*` can deduce a const element type from a pointer to a const array. A callable that reads `const T&` works with read-only elements, while a callable that mutates must receive writable ones. A function-template name may need explicit specialization when its type cannot be deduced as a value.

Test a mutating callable on a mutable array, a read-only callable on a const array, zero length, and more than one element type. A positive length requires an actual valid range of elements; the function cannot discover the allocation length from the pointer.

### ex02 — generic ownership and exception safety

The Rule of Three matters because Array owns a raw allocation. Copying must produce independent elements; indexed access needs both mutable and const overloads and an explicit bounds contract.

Value-initialization in `new T[n]()` initializes fundamental elements to zero, but a class's own constructor controls its state. It does not mean every possible T becomes zero bytes.

Deep copying alone is insufficient. If allocation or an element copy throws, construction must clean up already acquired storage. Assignment must keep a valid old state until a safe replacement can be committed. Copy-and-swap is useful after the copy constructor is safe. The current Array has failure-path ownership defects; see [Code-review.md](Code-review.md).

Test empty/default arrays, a valid last index, a rejected index, independent copies, self-assignment, const indexing, and a class type whose copying can throw. Integer-only demos cannot expose every generic lifetime problem.

Next connection: CPP08 replaces many manual storage operations with containers and uses iterators to separate algorithms from concrete data structures. Continue in [Journal-August.md](Journal-August.md).
