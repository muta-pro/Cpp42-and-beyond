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

**Objects** are concrete variables created from a class. A C++ object is similar to a struct but more powerful:
- Holds data
- Has functions attached to it
- Can automatically initialize and clean itself

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

**STACK** → Automatic lifetime  
**HEAP** → Manual lifetime

### References vs. Pointers

#### References
- Must be set at construction
- Always exist (cannot be null)
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
int arr{1, 2, 3};
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

**Note:** `bad()` vs `fail()` — `fail()` also triggers on normal EOF, making it too noisy for post-read checks. `bad()` only fires on real hardware/OS errors.

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
std::string::size_type  // size_type belongs to std::string namespace
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

*Last updated: [Current progress through CPP02]*