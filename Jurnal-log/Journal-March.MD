# C++ Learning Journal: 42 CPP Modules

A chronicle of my journey through C++ fundamentals, from basic OOP concepts to advanced polymorphism and memory management.

---

## Module Overview

| Module | Duration | Focus Area                 |
|--------|----------|----------------------------|
| CPP00  | 2 days   | Class basics, canon form   |
| CPP01  | 2 days   | Memory, refs, pointers     |
| CPP02  | 2 days   | Operator overloading       |
| CPP03  | 3 days   | Inheritance, constructors  |
| CPP04  | 2 days   | Polymorphism, virtual dtor |

---

## CPP00: Object-Oriented Foundations

### Core Concept: Grouping Data and Functions Together

An **object** is a region of storage holding a value; integers and arrays are objects too. A class object is an instance of that class. In C++, both classes and structs can have data, functions, constructors, and destructors; their main language differences are default member access and default inheritance access.

### Key Concepts

#### Constructor
A function that runs automatically when an object is created—the object's starting setup function.

**Important Rule:** Constructors with reference members must use initialization lists.

#### Method
A function that belongs to a class and is called on an object. Its meaning is intrinsically tied to that object.

---

## CPP01: Memory Management

### Core Concept: Visualizing Memory

Understanding where objects live and how to access them.

### Memory Regions

**Automatic storage duration** → Local objects normally live until their scope ends. A machine stack is the usual implementation.

**Dynamic storage duration** → Storage lives until released by its owner. That owner can be an RAII object; manual cleanup is not the only option.

### References vs. Pointers

#### References
- Must be set at construction
- A valid reference designates an object; it can still dangle if that object's lifetime ends
- Cannot be reassigned to refer to another object

#### Pointers
- Can be null
- Can be set later
- Can be reassigned

### Brace Uniform Initialization `{}`

Unifies older initialization syntaxes:
```cpp
// Copy initialization
std::string s = "hi";

// Direct initialization
std::string s("hi");

// Aggregate initialization
int arr[3] = {1, 2, 3};

// Brace initialization (modern)
std::string s{"hi"};
int arr[]{1, 2, 3};
```

**Benefits:**
- Catches bugs like narrowing conversions: `int x{2.3};` won't silently lose the decimal part
- Works seamlessly with containers: `std::vector<int> v{1, 2, 3};`

---

### Ex03: Reference vs. Pointer Members

**Key Question:** When to use a reference vs. a pointer as a member variable?

#### Reference Member Characteristics
- Opposite to pointer member
- Must be initialized immediately
- Cannot be null
- Cannot later refer to another object
- **Use when:** The object is mandatory and won't change

#### Exercise Pattern
One shared object with changing internal state:
- One class holding a reference to that object
- One class holding a pointer to that object

#### Object Lifecycle
```
MEMORY ALLOCATED
       ↓
CONSTRUCTOR RUNS
       ↓
OBJECT IS USED (methods called)
       ↓
DESTRUCTOR RUNS
       ↓
MEMORY RELEASED
```

#### Const Return Optimization
```cpp
const std::string& getType() const;
```
Returns `const std::string&` instead of `std::string` to avoid copying the string on every call.

**Double const:**
- One on the return type (prevents modification of returned data)
- One trailing on the method (indicates method doesn't modify object state)

---

### Ex04: File I/O and String Manipulation

**Concept:** Reading a file into a string with `std::getline`

#### File Stream Objects
Instead of C file APIs, use object-oriented streams:
- `std::ifstream` for reading files
- `std::ofstream` for writing files
- `std::string` for storing and manipulating text

#### Important Methods

**String methods:**
- `.find()` - locate substrings
- `.substr(start, len)` - extract substrings
- `.size()` - get length
- `.empty()` - check if empty

**Stream methods:**
- `.bad()` - check for serious I/O errors
- `.fail()` - check for any error (including EOF, too noisy for post-read checks)

**Note:** `eofbit` records that input encountered EOF; `fail()` tests `failbit` or `badbit`, not `eofbit` alone. A failed read after consuming all input commonly sets both `eofbit` and `failbit`. `badbit` indicates a loss of stream integrity, not only a hardware error. After a read loop, distinguish expected EOF from a non-EOF failure; opening, formatting, and writing failures also need explicit checks.

**Non-member function:**
- `std::getline(stream, string)` - extract a line from stream

**Important:** `std::getline` strips the newline delimiter, so you must add it back manually if needed.

#### Key Advantages

**`std::string` over `char[]`:**
- Creates empty string that expands automatically
- No manual buffer size management

**Object-oriented library usage:**
- Using library abstractions instead of pointer arithmetic
- Higher-level algorithms: find → copy substring → append replacement

**Safer text manipulation:**
```cpp
const std::string& text  // Read-only reference, no expensive copy
```

#### RAII Pattern
**Resource Acquisition Is Initialization**

Style of resource handling that manages cleanup automatically without explicit effort.

#### Nested Types and Constants

Classes can define types and constants inside themselves using `::` (scope resolution operator).

```cpp
std::string::size_type  // size_type is a nested type of the std::string class
std::string::npos       // Special constant meaning "not found"
```

---

### Ex05: Member Function Pointers

**Core Question:** How do I map a string to one of the class's member functions?

#### Regular vs. Member Function Pointers

**Regular function pointer:**
```cpp
void (*fp)() = &someFunction;
fp();  // Call it
```

**Member function pointer:**
Stores the address of a function that belongs to a class, so it always needs an object to run on:
```cpp
void (Harl::*mp)() = &Harl::debug;
(myObject.*mp)();   // Call via object
(ptr->*mp)();       // Call via pointer ← we use this
```

#### Implementation Pattern: Parallel Arrays

```cpp
void (Class::*funcName)();  // Pointer to member function taking no args
```

**Steps:**
1. Initialize an array of level names
2. Declare and fill an array of member-function pointers
3. Find matching index
4. Call the function at that index: `(this->*actions[i])();`

**Note:** `this->*` is the pointer-to-member dereference operator.

#### Why This Pattern?

Member functions here are private → can't be called directly from outside, only through the `complain()` method.

Levels serve as labels for logging system messages.

**Calling mechanism:**
```cpp
(this->*actions[i])();
```
- `this` → pointer to current object inside member function
- `actions[i]` → pointer to member function stored in array

#### Use Cases (Lookup Table Pattern)

- Command tables
- Event handlers
- Callback systems
- Virtual dispatch
- State machines
- Plugin systems

---

### Ex06: String to Control Flow

**Core Question:** How to transform input into a control-flow structure?

**Pattern:** `string → index → switch → behavior`

---

## CPP02: Operator Overloading & Fixed-Point Numbers

### Core Concept: Orthodox Canonical Form (OCF)

Understanding floating-point representation and teaching custom types to behave like built-in numbers.

### Numbers: Floating-Point Representation

**Scientific notation** with bitwise operations.

#### Bitwise Shift Operator `<<`
If I want to store an integer in a class, it needs to be pushed past 8 fractional bits.

---

### Ex00: Fixed-Point Number Basics

**Class Members:**
- `int _fpn` - raw value (fixed-point number)
- `int _fbn` - fractional bits number (determines position of decimal point in bit sequence)

The `_fbn` value determines how many bits represent the fractional part of a number.

---

### Ex01: Creating the Container

**Goal:** Store and convert fixed-point numbers

**Components:**
- Two constructors to convert numbers into fixed-point format
- Two methods to convert back
- `<<` overload: insertion operator calls `toFloat()` when it sees a fixed object

---

### Ex02: Operator Overloading

**Why?** The compiler doesn't know how to perform operations on custom objects, so we give it instructions.

#### Four Groups of Overloads

Teaching the container to behave like a number so the class acts like a real numeric type.

**Key insight:** The object stores a scaled integer, not a real number.

With `fractionalBits = 8`, scale is 256:
- Real value = `fixedBits / 256`
- It's all about manipulating raw integers

#### Arithmetic Operators `+` `/` `-`

Instead of casting to float and relying on processor's Floating Point Unit:
- Use bit shifting and raw integer operations

#### Increment/Decrement Overload

**Post-increment (`a++`):**
- Returns the current value to use in the current line
- Increments the variable for the next time it's used

**Pre-increment (`++a`):**
- Increments immediately
- Returns the new value

**An operator expression is resolved based on the type of the left operand first.**
Meaning a memeber operator is called always on the left operand.
For the compiler order matters:   `3 * v1` & `v1 * 3` is not symmetric.
That is why non-memeber operators remove assymmetry.
It is about matching syntax shapes to function signatures.

---

### Ex03: BSP - Binary Space Partitioning

#### Part 1: Class Mechanics with Const Members

**Challenge:** Handle const members: `Fixed const _x, _y;`

Const changes class functioning—`_x` and `_y` can't be modified after creation.

**Solution:** Instead of assigning values inside `{}`, use initialization list at moment of construction.

**Copy assignment operator:** Because of const attributes `_x`, `_y`, we can't overwrite them with new data. Cast parameter to void to suppress warnings and return current object.

#### Part 2: The Algorithm - Binary Space Partitioning

**Method:** Half-space / Cross Product method

**Why this algorithm?**
- Relies only on addition, subtraction, and multiplication
- Extremely fast
- Avoids all division errors
- Perfectly utilizes the overloaded operators from ex02

#### Vector Math: The `sign()` Function

Calculates the determinant of a 2D matrix—the 2D cross product of two vectors.

**Purpose:** Determine which side of a line a point is on.

**Steps:**
1. Create vector 1: line endpoint to target point
2. Create vector 2: actual point-to-point segment
3. Calculate: `(x1 * y2) - (x2 * y1)`

**Result:** Single number where only the sign matters:
- Positive → point is on the left side
- Negative → point is on the right side
- Zero → point sits on the line

#### Triangle Point-in-Triangle Test

Depending on how the triangle is drawn in `main()`, check both sides.

Use strict `<` and `>` (not `<=` or `>=`) because if the point is on the line, it should return false.

**Logic:**
- Cross product is positive if P is on left side
- Cross product is negative if P is on right side
- Cross product is zero if P sits on the line

**The test:** Point is inside if all signs are positive OR all negative. If mixed, the point crossed over an edge.

#### Why Not Other Methods?

**Barycentric coordinates:**
- Require division
- Risk of dividing by zero
- Lose precision

**Angle summation:**
- Requires heavy floating-point trigonometry like `acos()`
- Defeats the purpose of writing a fixed-point math class

---

## CPP03: Inheritance and Constructors

*Coming soon...*

---

## CPP04: Polymorphism and Virtual Destructors

*Coming soon...*

---

## Key Learnings

### Memory Management
- Understanding stack vs. heap allocation
- When to use references vs. pointers
- RAII pattern for automatic resource cleanup

### Object-Oriented Design
- Proper constructor/destructor patterns
- Const correctness for performance and safety
- Member function pointers for flexible dispatch

### Operator Overloading
- Making custom types behave like built-in types
- Fixed-point arithmetic without floating-point operations
- Efficient geometric algorithms using only integer math

### Best Practices
- Prefer `const` references to avoid unnecessary copies
- Use initialization lists for const and reference members
- Choose algorithms that avoid division and floating-point operations when precision matters

---

## Resources & References

- 42 School C++ Modules (CPP00-CPP04)
- The C++ Programming Language - Bjarne Stroustrup
- Effective C++ - Scott Meyers

---

## CPP00–CPP02: Theory gaps to revisit

### CPP00 — state, static members, and input contracts

A class invariant describes valid state. A phone book's stored count and circular replacement index must stay consistent when contacts are added, rejected, or replaced. Separate parsing an index from checking whether a stored contact exists at that index. EOF should end an input loop cleanly, rather than repeatedly retrying a stream that cannot produce more input.

An instance member belongs to each object; a static data member is shared by the class. A static member function has no `this` pointer and cannot access an instance without being given one. In the Account exercise, connect per-account values with class-wide totals and define how constructors/destructors affect each total. In C++98, an odr-used static data member normally needs an out-of-class definition.

Headers declare interfaces; source files define ordinary functions and non-inline storage. Include guards prevent repeated inclusion in one translation unit. They do not solve multiple program definitions across translation units. Keep one `main` per executable; put alternative implementations into separate exercises or notes.

Checkpoint: describe construction versus copy construction versus assignment, and trace how object count changes through each operation. These are different events even when the resulting values match.

### CPP01 — ownership and boundary behavior

`new T` pairs with `delete`; `new T[n]` pairs with `delete[]`. Copying a pointer does not transfer ownership. References and observing pointers can outlive their targets and become dangling; neither syntax guarantees lifetime safety.

A reference member binds during construction, and assignment through the reference assigns to its target rather than rebinding it. A pointer member may be absent or reseated. For the weapon exercises, the observing Human must not outlive its Weapon. A reference returned by a getter also becomes invalid when its owning object dies.

For replacement: reject an empty search string; define non-overlapping matching; test empty replacement, no matches, consecutive matches, empty file, and a file without a final newline. Output can fail during flushing/closing, so immediate insertion success is not the whole I/O story when reliable output is required.

For Harl filtering, distinguish intentional fallthrough from an accidental missing `break`. The usual severity order is DEBUG → INFO → WARNING → ERROR. A C++98 implementation can use a compiler-recognized fallthrough comment; the `[[fallthrough]]` attribute is C++17.

### CPP02 — value semantics and numeric contracts

Orthodox Canonical Form covers default construction, copy construction, copy assignment, and destruction. Assignment normally returns `T&`; prefix increment returns a reference to the updated object, while postfix returns the old value. Read-only comparisons and queries should work on const objects.

Fixed point stores a scaled integer, so one raw increment represents `1 / 256` when there are eight fractional bits. This is not the same as adding one whole real unit. State the rounding policy for negative conversions, the valid range, and behavior on zero division or overflow.

Under C++98, left-shifting a negative signed value is undefined; right-shifting one is implementation-defined. Large intermediates and float-to-int casts need representability checks. Widen operands before arithmetic rather than casting an already-overflowed result.

For the point-in-triangle exercise, use consistent orientation signs, and define whether points on edges count as inside. Test vertices, edges, outside points, reversed vertex order, and degenerate triangles. `const` coordinate members also constrain assignment: decide the supported interface instead of modifying const storage through a cast.

See [basics.MD](basics.MD) for storage duration and numeric safety, and [Code-review.md](Code-review.md) for concrete defects. These additions are study material; they do not claim every exercise is finished.
