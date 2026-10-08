
# C++ Foundations: Abstraction, Safety, and Expressive Power

This chapter collects the core ideas I have been learning while moving through early C++: how the language organizes code, how objects live in memory, how classes express behavior, and how C++ gives both low-level control and high-level structure.

The central idea is that C++ is not just “C with classes.” It is a language built to model reality through types, control memory precisely, and express intent clearly. Its strength comes from combining three things: **abstraction**, **safety**, and **expressive power**.

Abstraction means I can describe a concept through a type and hide irrelevant details. Safety means I can structure ownership and lifetime so objects are created and destroyed correctly. Expressive power means I can write code that feels close to the problem itself instead of only manipulating raw memory.

---

## Namespaces

A namespace groups related symbols under one name and prevents naming collisions.

Without namespaces, two libraries could both define a function called `print`, and the compiler would not know which one I mean. A namespace solves that by placing names into a scope.

```cpp
namespace Foo
{
    void print();
}
```

Then I call it with:

```cpp
Foo::print();
```

The standard library lives inside the `std` namespace, which is why I write `std::cout`, `std::string`, `std::vector`, and so on.

Conceptually, a namespace is not an object and not a class. It is just an organizational scope for related names.

What to remember:

* namespace = named scope
* used to group related functions, classes, constants
* avoids collisions between identical names
* accessed with the scope resolution operator `::`

---

## Standard I/O Streams

C++ replaces the old C style `printf` / `scanf` model with stream objects such as `std::cout`, `std::cin`, and `std::cerr`.

A stream is an object that represents a flow of data. The important point is that streams also carry **state**.

For example:

* `good()` means everything is fine
* `eof()` means end-of-file was reached
* `fail()` means an operation failed logically
* `bad()` means a serious stream error happened

These come from the stream hierarchy:

* `std::ios_base` contains general formatting and state machinery
* `std::ios` builds on it and provides common stream behavior
* input and output streams derive from there

Useful functions:

* `good()`
* `eof()`
* `fail()`
* `bad()`
* `rdstate()`

This matters because stream operations are not just “do something and forget.” A stream remembers what happened.

Example:

```cpp
int x;
std::cin >> x;
if (std::cin.fail())
    std::cout << "Input error\n";
```

So a stream is both:

* a channel for data
* an object with internal condition flags

---

## Class and Instance

A class is a blueprint. An instance is a concrete object built from that blueprint.

```cpp
class Dog
{
public:
    void bark();
};
```

`Dog` is the type. If I write:

```cpp
Dog d;
```

then `d` is an instance of `Dog`.

A class usually contains:

* **data members**: what the object stores
* **member functions**: what the object can do

This is the basic C++ way of modeling concepts.

---

## Member Attributes and Member Functions

Member attributes are the variables stored inside an object. Member functions are the operations that act on that object.

```cpp
class Dog
{
private:
    std::string _name;

public:
    void setName(const std::string& name);
    void bark() const;
};
```

Here `_name` is member data, while `setName()` and `bark()` are member functions.

A useful mental rule:

A class answers four questions:

1. What data does this object hold?
2. How is it created?
3. What can it do?
4. Who owns its memory or resources?

That is a strong way to decode any class quickly.

---

## `this`

Inside a non-static member function, `this` is a pointer to the current object.

If I write:

```cpp
class Dog
{
private:
    std::string _name;

public:
    void setName(const std::string& name)
    {
        this->_name = name;
    }
};
```

then `this->_name` means “the `_name` of the current object.”

In practice, `this` helps when:

* distinguishing member data from a parameter with the same name
* returning the current object with `return *this;`
* writing fluent interfaces or assignment operators

Important:

* `this` is a pointer
* `*this` is the object itself

---

## Accessors

An accessor is a function used to read internal state safely, usually without exposing the data member directly.

Example:

```cpp
class Dog
{
private:
    std::string _name;

public:
    const std::string& getName() const
    {
        return _name;
    }
};
```

This is useful because it preserves encapsulation. The class keeps control over how its data is accessed.

A setter modifies internal state; a getter reads it.

---

## Initialization List

The initialization list is the part after a constructor signature and before the body.

```cpp
class Point
{
private:
    int _x;
    int _y;

public:
    Point(int x, int y) : _x(x), _y(y) {}
};
```

This is not the same as assigning inside the constructor body. Initialization happens **before** the body runs.

Why it matters:

* required for `const` members
* required for reference members
* preferred for efficiency
* base classes are also initialized this way

So constructor logic has two phases:

1. initialize members and base parts
2. run the constructor body

---

## `const`

`const` means “this should not be modified through this name.”

In C++, `const` appears in many places, and each one matters.

### Const variable

```cpp
const int x = 5;
```

`x` cannot be changed.

### Const reference parameter

```cpp
void print(const std::string& s);
```

This means:

* do not copy the string
* do not modify the original object

This is a very common and efficient function parameter form.

### Const member function

```cpp
int getX() const;
```

This means the function promises not to modify the logical state of the object.

This is crucial for interface design because it allows functions to work on const objects.

---

## Visibility: `public`, `private`, `protected`

Visibility controls who can access what.

### `public`

Accessible from outside the class.

### `private`

Accessible only inside the class itself.

### `protected`

Accessible in the class and in derived classes.

Encapsulation is built on visibility. A good class hides its internal representation and exposes only the operations that make sense.

---

## `class` vs `struct`

In C++, `class` and `struct` are almost the same, except for default visibility.

In a `class`:

* members are `private` by default
* base-class inheritance is `private` by default

In a `struct`:

* members are `public` by default
* base-class inheritance is `public` by default

So this:

```cpp
class A
{
    int x;
};
```

makes `x` private by default.

While this:

```cpp
struct B
{
    int x;
};
```

makes `x` public by default.

Conceptually:

* `struct` is often used for plain data
* `class` is often used for encapsulated objects with behavior

But technically both can have methods, constructors, inheritance, and so on.

---

## Comparisons

Objects can be compared either by raw identity or by value semantics.

Built-in comparisons work automatically for primitive types, but for classes I often define what equality means.

For example, for a mathematical point, equality might mean both coordinates are equal. For a file handle, equality might mean something else entirely.

This is part of designing the meaning of a type.

---

## Non-Member Functions

Not every function belongs inside a class.

Some operations conceptually act on a class but are better written outside it. A classic example is `operator<<`:

```cpp
std::ostream& operator<<(std::ostream& out, const Point& p);
```

Why outside? Because the left side is the stream, not the object.

A useful design rule:

* use member functions when the operation naturally modifies or depends on the object itself
* use non-member functions when the operation is symmetric or does not belong more strongly to one side

---

## Pointers to Members

C++ also allows pointers to class members, though they are less common in beginner code.

Example:

```cpp
class A
{
public:
    int x;
};

int A::*ptr = &A::x;
```

This is not a normal pointer to an `int`. It is a pointer to a member inside an object of type `A`.

Used with an object:

```cpp
A a;
a.*ptr = 42;
```

Or with an object pointer:

```cpp
A* pa = &a;
pa->*ptr = 42;
```

This syntax is unusual, but it exists because member layout depends on the object type.

---

## Storage Duration and Dynamic Allocation

Prefer an ordinary local object when its lifetime fits the scope. The language calls this automatic storage duration; a machine stack is a common implementation. Dynamic storage is useful when ownership or lifetime requires it. A local vector object can still own dynamically allocated elements.

Heap allocation is often chosen when:

* object size must be dynamic
* the object must outlive the current scope
* ownership must be shared or transferred
* runtime-selected polymorphic objects may need a separate owner
* the object is very large

Example:

```cpp
Dog* d = new Dog();
delete d;
```

But raw `new` and `delete` are dangerous because they make lifetime manual. In modern C++, ownership tools replace this more often.

Polymorphism itself does not require heap allocation: a local derived object can be accessed through a base reference. Variable collection size also does not mean I must write `new` myself; containers manage their own dynamic storage.

### Important note for 42 / C++98

Ideas like **move semantics**, **smart pointers**, and **range-based loops** are later C++ features, not C++98. They are important conceptually, but not part of early 42 modules 00–04 in practice.

---

## RAII and Object Lifetime

RAII means **Resource Acquisition Is Initialization**.

This is one of the most important ideas in C++. It means a resource should be acquired by an object during construction and released during destruction.

So instead of writing “open resource here, maybe forget to close it later,” I tie the resource to an object whose lifetime is automatic.

Example idea:

* constructor acquires resource
* destructor releases resource

This makes code safer because cleanup becomes automatic.

In C++, an object has a lifecycle:

1. memory is obtained
2. constructor initializes it
3. object is used
4. destructor runs
5. memory is released

This lifecycle is central to the language.

---

## `std::string`

`std::string` is a standard class representing a sequence of characters.

It is much safer and more expressive than raw C strings because it manages its own buffer and size.

Useful properties:

* dynamic size
* built-in methods like `.size()`
* easier comparisons
* operator support like `+`, `==`, `[]`
* automatic memory management

Passing strings by `const std::string&` is usually the right default when I only need to read them.

---

## Range-Based Loop

A range-based loop is a later C++ feature, but the concept is still useful:

```cpp
for (const auto& x : container)
{
}
```

It means “iterate through each element in the container.”

This is not C++98 syntax, but it reflects a broader principle: iterate over data at the level of meaning, not only with raw indices.

---

## Four-Step Class Decoding

When reading any class, I can decode it with four questions:

### 1. Data

What memory does the object hold?

### 2. Constructors

How is the object created and initialized?

### 3. Methods

What operations does the object expose?

### 4. Ownership

Who owns what memory or resources?

This is a simple but powerful way to understand a class quickly.

---

# Fixed-Point Numbers

A fixed-point number is a way to represent decimal values using integers by pretending the decimal point is always in a fixed position.

Instead of storing a floating-point value directly, I store an integer plus an agreed scale.

The formula is:

[
\text{real value} = \frac{\text{stored integer}}{\text{scale}}
]

If the scale is `256`, then:

* `256` means `1.0`
* `512` means `2.0`
* `128` means `0.5`

A common choice is a power of two, such as `2^8 = 256`, because that fits well with bit shifts.

This is why Module 02 uses 8 fractional bits.

---

## Why Fixed-Point Exists

Fixed-point is useful when:

* speed and predictability matter
* exact scaled integer behavior is preferred
* floating-point hardware is expensive or undesirable
* graphics, sound, embedded systems, or deterministic calculations are involved

It trades flexibility for control.

---

## Trade-Offs

The advantages:

* simple integer-based representation
* deterministic scaling
* often faster or more predictable in some contexts

The drawbacks:

* limited precision
* limited range
* manual scaling management
* overflow risks
* less flexible than float

---

## Basic Fixed-Point Operations

```cpp
#define SCALE 256

int to_fixed(float x)
{
    return (int)(x * SCALE);
}

float to_float(int x)
{
    return (float)x / SCALE;
}

int fixed_mul(int a, int b)
{
    return (a * b) / SCALE;
}

int fixed_div(int a, int b)
{
    return (a * SCALE) / b;
}
```

### Interpretation

If I store with 8 fractional bits, then multiplying an integer by `256` shifts the number into fixed-point form.

For integers:

* scale by 256 in an arithmetic type wide enough for the input
* in C++98, left-shifting negative signed values is undefined, and large shifts can exceed the valid range; `n << 8` is not a safe general replacement for checked multiplication

For floats:

* multiply by `256`
* round to nearest integer
* store the result as the internal fixed-point integer

To convert back:

* to float: divide by `256`
* to int: apply a documented rounding policy; in C++98, right-shifting negative signed values is implementation-defined and need not give truncation toward zero

The short arithmetic examples above illustrate scaling, not a complete numeric type: multiplication can overflow, division needs a zero check, and a float-to-int conversion must first be representable. A cast after overflow cannot repair it.

---

## Q Format

A notation like `Q8.8` means:

* 8 bits for the integer part
* 8 bits for the fractional part

The exact meaning can vary by convention, especially around signedness, but the general idea is always that a fixed number of bits is reserved for the fraction.

---

## Floating-Point Reminder

A floating-point number is stored approximately using sign, exponent, and mantissa.

In simplified form:

[
(-1)^{sign} \times 1.mantissa \times 2^{(exponent - bias)}
]

So a float is basically binary scientific notation.

Key idea:

* exponent gives range
* mantissa gives precision
* many decimal numbers cannot be stored exactly
* float stores the closest representable approximation

This is why fixed-point and floating-point solve different problems.

---

# Inheritance, Encapsulation, and Polymorphism

Inheritance expresses an **is-a** relationship.

If `Dog` inherits from `Animal`, then a dog is a kind of animal.

Inheritance is useful for building concept hierarchies and reusing common structure or behavior.

---

## Encapsulation

Encapsulation means wrapping data and behavior together while controlling access.

A class should protect its internal state and expose meaningful operations.

This is why access modifiers matter:

* `private` protects representation
* `protected` allows controlled reuse in subclasses
* `public` defines the interface

Encapsulation keeps code understandable and reduces accidental misuse.

---

## Polymorphism and Virtual Functions

Polymorphism means one interface can lead to different behaviors depending on the actual object.

Example:

```cpp
class Animal
{
public:
    virtual void makeSound() const;
};
```

If `Dog` and `Cat` override `makeSound()`, then calling through an `Animal*` can produce different results at runtime.

This is inheritance-based polymorphism, also called runtime polymorphism.

Important condition:

* the function must be `virtual`
* the call must happen through a pointer or reference to base

---

## Static Type vs Dynamic Type

With inheritance, an object can be seen in two ways.

### Static type

What the compiler sees from the declaration.

Example:

```cpp
Animal* a;
```

The static type is `Animal*`.

### Dynamic type

What object was actually created at runtime.

```cpp
a = new Dog();
```

Now the dynamic type is `Dog`.

If `makeSound()` is virtual, the call uses the dynamic type.

So:

* static type controls what the compiler allows
* dynamic type controls which virtual override actually runs

---

## Virtual Destructor

If a base class is meant to be used polymorphically, it needs a virtual destructor.

Why? Because deleting through a base pointer must destroy the whole derived object.

Bad design:

```cpp
Animal* a = new Dog();
delete a;
```

If `Animal` does not have a virtual destructor, deleting a derived object through that base pointer has undefined behavior.

Rule:
If a class has virtual functions or is intended as a base polymorphic type, its destructor should usually be virtual.

---

## Abstract Class and Interface

An abstract class is a class that cannot be instantiated directly because it has at least one pure virtual function.

```cpp
class Animal
{
public:
    virtual void makeSound() const = 0;
};
```

This defines a contract for derived classes.

An interface-like class in C++ is usually a pure abstract class with no state and only pure virtual functions.

Conceptually:

* abstract class: may share behavior and some state
* interface: pure contract, usually no data

C++98 does not have a separate `interface` keyword, so pure abstract classes fill that role.

---

## Shadowing

Shadowing happens when a name in an inner or derived scope hides a name from an outer or base scope.

If a derived class defines a member with the same name as one in the base class, the derived one hides the base one.

To access the base version explicitly:

```cpp
Base::_attribute
```

Compiler flags:

* `-Wshadow` warns when a name hides another
* `-Wno-shadow` suppresses that warning

Shadowing is legal, but often confusing. It is better to avoid it unless there is a clear reason.

---

# Lvalues, Rvalues, and References

This is one of the deeper C++ foundations.

An **lvalue** is an expression that identifies an object or function. Some lvalues can appear on the left side of assignment, but a const object or an array is not a modifiable lvalue.

In modern C++, **rvalue** includes prvalues (pure values, such as `5`) and xvalues (objects whose resources may be reused, such as the expression produced by `std::move(x)`). Expression categories are more precise than "named versus temporary".

Example:

```cpp
int x = 5;
```

* `x` is an lvalue
* `5` is an rvalue

A reference binds another name to an object.

```cpp
int a = 10;
int& ref = a;
```

Now `ref` is another name for `a`.

---

## Why `const std::string&` Accepts Temporaries

When I write:

```cpp
void print(const std::string& s);
print("hello");
```

the string literal `"hello"` is converted into a temporary `std::string`.

A non-const reference cannot bind to that temporary. But a const reference can.

That is why `const std::string&` is such a useful parameter:

* avoids copying
* accepts named objects
* also accepts temporary objects

Important clarification:
a string literal itself is not a `std::string`; it is an array of constant characters. But it can be used to create a temporary `std::string`.

---

# Runtime vs Compile-Time Polymorphism

C++ supports two broad forms of polymorphism.

## Inheritance-Based Polymorphism (Runtime)

This uses:

* base class
* derived classes
* virtual functions
* pointers or references

Properties:

* flexible
* actual behavior chosen at runtime
* slight runtime cost
* good when different object types share one interface

This is what happens with `Animal* a = new Dog();`

---

## Template-Based Polymorphism (Compile-Time)

This uses templates instead of inheritance.

The type does not need to inherit from a base class. It only needs to support the required operations.

Properties:

* checked at compile time
* no virtual dispatch overhead
* often faster
* very useful for generic reusable code like the STL

This is a very different model:

* inheritance polymorphism depends on hierarchy
* template polymorphism depends on structure and compatibility

---

# Connecting the Earlier Modules

The big lesson is that C++ is a language of **models and lifetimes**.

A namespace organizes names.
A class models a concept.
An object owns data and lives through a constructor/destructor cycle.
Encapsulation protects meaning.
Inheritance builds hierarchies.
Virtual functions make behavior depend on the real runtime object.
References and const make interfaces safe and expressive.
Fixed-point numbers show how representation can be designed manually instead of taken for granted.


## Language Versions: Label the Tool I Am Learning

| Version | Examples relevant to these notes |
| --- | --- |
| C++98 | Classes, RAII, exceptions, four named casts, templates, vector/list/deque/map/set/stack, classic iterator algorithms |
| C++11 | `auto` type deduction, range-for, lambdas, move semantics, `unique_ptr`, `array`, `forward_list`, unordered containers, `noexcept`, `override`, `= default`, `= delete`, `minmax_element` |
| C++17 | `string_view`, `optional`, `[[nodiscard]]`, `[[fallthrough]]` |
| C++20 | Concepts, `requires`, ranges algorithms and views, `span` |

An exercise's required language standard is part of its contract. Modern extensions are useful separate practice. `<concepts>` and C++20 syntax cannot be used merely because a C++98 program needs generic behavior. `std::hive` is a C++26 facility, outside this repository's configured C++17/20 scope; header/compiler availability must be checked before experimenting with it.

## Exceptions, Assertions, and Guarantees

An exception reports that a function could not finish its job. For example, easyfind throws when the requested value is missing; its caller can catch that exception and print "not found."

Use `<exception>` for `std::exception`, `<stdexcept>` for errors such as `logic_error`, `runtime_error`, and `out_of_range`, and `<cassert>` for `assert`. These are different headers. `<exception>` is singular.

- **Exception:** the function signals a problem to its caller.
- **Assertion:** a development check that says "this should be true." A failed assertion stops the program. Builds can disable assertions with `NDEBUG`, so use normal checks for user input.
- **Precondition:** a requirement the caller must meet before calling the function. For example, two iterators must belong to a valid range.
- **Invariant:** a rule an object must keep true while it is usable. For Span, stored count must never exceed its limit.

Normally throw an exception object by value and catch it with `const std::exception&` or the appropriate derived type. Catching by reference avoids a copy and keeps access to the actual exception type. Put more specific catch blocks before a general base-class catch.

When an exception travels to a catch block, completed local objects are destroyed along the way. This is called **stack unwinding**. If construction fails, the complete object's destructor does not run; already constructed base/member objects are still cleaned up. A raw pointer does not clean up the allocation it points to, so an owning helper matters.

| Guarantee | Meaning on failure |
| --- | --- |
| Basic | The object remains valid and leaks no resources; its values may have changed |
| Strong | Failure leaves the previous state unchanged |
| No-throw | The operation will not let an exception escape |

`noexcept` promises that an exception will not escape the function. It does not fix failures automatically: an escaping exception calls `std::terminate`. Destructors should not let exceptions escape, especially while another exception is being handled.

For an object that owns memory, first prepare the replacement, then finish copying, and only then replace the old data. This keeps the old object valid if allocation/copying fails. Let a local owning object clean up unfinished replacement data; that is RAII in practice.

**Copy-and-swap** means preparing a copied temporary and exchanging its state with the current object. It can keep assignment safe, but only if making the temporary already cleans up properly on failure and the state exchange cannot throw.

## Rule of Three, Five, and Zero

- **Rule of Three (C++98):** manual ownership usually requires coordinated destructor, copy constructor, and copy assignment.
- **Rule of Five (C++11):** consider move construction and move assignment too when designing such ownership.
- **Rule of Zero:** let member types such as vector/string/smart pointers handle ownership and special members.

Orthodox Canonical Form is an exercise requirement, not a reason to write unnecessary raw memory management in every application. Span's vector already makes an independent copy of its values. Copying a raw pointer only copies an address.

`std::move` from `<utility>` casts an expression to an rvalue category; it does not itself move bytes or transfer ownership. The selected constructor/assignment decides what happens, and copying may still occur. Do not assume the source becomes empty; only rely on the moved-from guarantees of the specific type.

## Casts, Parsing, and Numeric Boundaries

| Cast | Appropriate role | What it does not guarantee |
| --- | --- | --- |
| `static_cast` | Explicit supported conversions, including numeric conversion and hierarchy upcasts | No runtime bounds check; a downcast can be invalid |
| `dynamic_cast` | Runtime-checked hierarchy casts; downcasts require a polymorphic base | Does not keep the source object alive |
| `const_cast` | Adjust const/volatile qualification | Writing an originally const object is undefined behavior |
| `reinterpret_cast` | Restricted low-level representation conversions | Does not create an object, serialize it to disk, or grant arbitrary aliasing access |

Parsing translates text to a value; casting converts an existing typed value. Reject malformed or partly consumed input according to a documented grammar. NaN and infinity need explicit handling; NaN is not an uninitialized value. `x != x` detects NaN under ordinary IEEE behavior; `std::isnan` communicates that intent in C++11.

Widen operands **before** arithmetic. A wider destination cannot fix overflow that already happened in `int`. Verify finiteness and representability before floating-to-integer conversion; decimal formatting must not sneak in an unchecked cast. Short-circuit checks must precede the expression they protect.

`uintptr_t`, when provided, is an unsigned integer type capable of representing `void*` for a supported round trip; it need not have exactly the pointer's size. Modern C++ declares it in `<cstdint>` (C++11), not `<cstdlib>`. A recovered pointer is usable only while the original object lives. This is an address round trip, not portable persistent serialization.

## Reading Template Syntax, One Piece at a Time

A template is a pattern with a placeholder for a type. The compiler fills in that placeholder when I use the pattern with a particular type.

For easyfind, read this declaration:

```cpp
template <typename T>
typename T::const_iterator easyfind(const T& cont, int n);
```

| Piece | Plain meaning |
| --- | --- |
| `template <typename T>` | T is a placeholder for a type |
| `const T& cont` | Receive the original container without copying it; read through cont without changing it |
| `T::const_iterator` | Use the read-only iterator type supplied by the container |
| The second `typename` | Tell the compiler that this name inside T is a type |
| `int n` | Receive the number to search for |

In this example T is the entire container type. If I pass a vector of integers, T becomes `std::vector<int>`, not just `int`. If I pass a list of integers, T becomes `std::list<int>`.

The `::` operator means "look inside this scope." A class can provide named types as well as named functions and data. `std::vector<int>::const_iterator` is one such type name. It is used to declare an actual variable, just as int is:

```cpp
int number;
std::vector<int>::const_iterator it;
```

The types are `int` and `std::vector<int>::const_iterator`. The variable names are `number` and `it`. In a template, T is still unknown when the compiler first reads the pattern, so typename marks the nested name as a type.

Filling in a template for a concrete type is called **instantiation**. Some errors only appear when a particular function/member is actually used. Including MutantStack.hpp in an empty main does not test assignment; calling assignment makes the compiler check that member too.

The compiler normally needs to see a template function's body when using it for a new type. Keep the definition in the header, or in a .tpp file that the header includes. An ordinary non-template function can often put its body in a separately compiled .cpp instead.

A member from a template base class may need `this->` to tell the compiler where to look; that is relevant to MutantStack's `this->c`.

In C++20, a **constraint** limits which types a template accepts. `convertible_to<double,int>` says that a conversion is allowed for these types; it does not promise that every double value fits in an int.

## Overloading: Same Name, Different Parameters

An overload is another function with the same name but different parameters. For my vector/list/deque searches:

- The easyfind receiving `T&` returns an iterator that can read/write an element.
- The easyfind receiving `const T&` returns a const_iterator that can read the element but not change it.

For an ordinary vector the compiler picks the first; for a const vector it picks the second. It chooses based on the argument and parameter types, not on which return type I would prefer. Changing only the return type does not make a valid overload.

Templates and overloading are separate tools: the template handles different container types; the overloads handle different ways of accessing those containers.

## Header Structure and Direct Includes

A header should include the library headers for the tools it uses itself. For easyfind, `<algorithm>` supplies std::find and `<exception>` supplies std::exception.

The program may compile without a direct include because another header happened to include it too. That is an indirect include. It is not something to depend on: different libraries or later changes may bring in different headers.

An include guard uses `#ifndef`, `#define`, and `#endif` to prevent processing the header twice during one source file's compilation. Template bodies belong inside that guard. An explanatory comment outside the guard does no harm, but I can keep related comments together inside it for readability.

The generic easyfind functions do not directly name vector/list/deque, so those includes belong in the code that creates those containers. A commented-out vector example does not require a vector include.

To check header independence, compile a tiny source that includes only easyfind.hpp. Then separately create containers and call both overloads to check their bodies.

## ADL: Argument-Dependent Lookup

An unqualified function call can search namespaces associated with the argument types, in addition to ordinary lookup. `::swap(a,b)` deliberately names the global function and suppresses ADL for that call. Generic library code often uses `using std::swap; swap(a,b);` to allow a type's associated custom swap and retain the standard fallback.

## Containers and Adaptors

Containers organize data and normally own their stored values. If those values are raw pointers, the container owns the pointer values, not the pointed-to objects. `array` has fixed size; `stack` does not expose `begin`/`end`. Automatic growth and iteration are not universal properties of every container-like interface.

| Family | Types | Key distinction |
| --- | --- | --- |
| Sequence | vector, deque, list; array and forward_list from C++11 | Values arranged in a sequence |
| Ordered associative | set, multiset, map, multimap | Keys ordered by a comparator; lookup O(log n) |
| Unordered associative (C++11) | unordered_set/map and multi variants | Hash lookup average O(1), worst O(n); no sorted order |
| Container adaptors | stack, queue, priority_queue | Restricted interface over backing storage |

`push_back` adds at the back of vector/list/deque; `push_front` is available for list/deque, and forward_list; `push` belongs to stack/queue/priority_queue. Map and set use insertion APIs suited to their keys. `pop` removes without returning a value; read `top`/`front` first and ensure the adaptor is not empty.

Vector offers contiguous storage and O(1) indexing. Appending is **amortized O(1)**: most appends are cheap, but a growth step can move/copy O(n) elements. List has O(1) insertion at a known node, but locating that node still costs time and traversal has weaker locality.

Vector **size** is the number of elements. **Capacity** is how many elements its allocation can currently hold without reallocation. `reserve` changes capacity without creating elements; `resize` changes size. Neither automatically enforces a custom logical limit such as Span's maximum count.

## Iterators, Ranges, and Lifetimes

An iterator represents a position in a collection. `*it` accesses the element at that position; `++it` moves to the next position. The word **dereference** means using `*it` to access the element.

Classic algorithms usually use `[first,last)`: start at first and stop before last. `end()` means the position after the last element, not another stored value. Do not read `*end()`. For an empty container, begin equals end because there is no first element.

An iterator usually does not own the data or keep it alive. If its container is destroyed or its storage changes in certain ways, the old iterator may become unusable. This is called invalidation.

| Category | Example operation | Typical source |
| --- | --- | --- |
| Input | Single-pass read and increment | Input stream |
| Output | Write and increment | Back-insertion adaptor |
| Forward | Multipass read/increment | forward_list (C++11) |
| Bidirectional | Also decrement | list, ordered set/map |
| Random access | Also offset/subtract compatible positions | vector, deque, array |
| Contiguous (C++20) | Also consecutive underlying storage | vector<int>, array |

An input iterator can read a source that is consumed as it goes. Counting first may leave nothing for a second pass. Forward iterators can walk the same range more than once, so they support counting and then copying. `std::distance` requires valid positions from a real range; it cannot safely test whether arbitrary positions are valid.

Mutation can invalidate borrowed positions. Vector reallocation invalidates all iterators/references/pointers; erase invalidates positions at and after the erased element. List insertion preserves iterators and erase invalidates the erased ones. Deque end insertion preserves existing element references but invalidates iterators. Check the exact operation's documented rules.

For vector/list/deque, iterator can read/write an element; const_iterator can only read it. Both can advance. `const iterator` is different: the iterator variable cannot advance, but its element may still be writable. The const easyfind overload needs a read-only type both for its returned iterator and its local result variable.

## Algorithms and Preconditions

| Tool | Purpose | Requirement or useful fact |
| --- | --- | --- |
| `find` | First matching value | O(n); missing value returns last |
| `sort` | Order a range | Random access and strict weak ordering; O(n log n) comparisons |
| `min_element`, `max_element` | Extreme positions | O(n); on an empty range return last |
| `minmax_element` (C++11) | Both extreme positions | O(n); result is a pair of iterators |
| `copy` | Copy values to an output range | Destination must have space, or use an inserter |
| `for_each` | Apply callable to each value | Callable must accept element expressions |
| `lower_bound`, `upper_bound` | Ordered insertion/search positions | Appropriate partitioning; sorted data satisfies the usual preconditions |
| `binary_search` | Check membership in ordered data | Appropriate ordering/partitioning; does not return a found iterator |
| `adjacent_difference` | First value followed by consecutive differences | `<numeric>`; default subtraction uses input value type |
| `reverse` | Reverse a range | Bidirectional iterators |

`std::distance`, `advance`, and iterator adaptors come from `<iterator>`. `insert` is normally a container member; `std::inserter` and `std::back_inserter` adapt writes into insertion. There is no general `std::insert` algorithm.

A comparator for sorting must model **strict weak ordering**. In particular, `comp(x,x)` is false, and ordering must be consistent and transitive. `<=` is not a valid ordinary sort comparator. Binary-search comparisons may be logarithmic while iterator traversal is linear on non-random-access ranges; use a tree container's member lookup when searching its keys.

For Span: longest span is max minus min in O(n). Shortest span comes from adjacent differences in a sorted copy, O(n log n) total. Sorting a copy preserves observable original state. Duplicate values make the shortest gap zero. Convert each operand to the chosen safe arithmetic type before subtracting.

## Complexity and Testing

| Complexity | Typical growth |
| --- | --- |
| O(1) | Constant work |
| O(log n) | Tree search; repeated halving |
| O(n) | Visit each element |
| O(n log n) | Efficient comparison sorting |
| O(n²) | Compare many pairs; may be acceptable for tiny inputs |

Complexity counts how work grows; actual performance also depends on allocation, locality, data size, and element operations. Memory complexity matters too: sorting a copied vector uses O(n) extra element storage.

Start with small fixed inputs where I know the answer. **Duplicates** means a value appears more than once: for `7,1,7`, easyfind must return the first 7. An **empty container** stores no elements. A **missing value** is a value the container does not contain. A **target** is the value I ask the function to find.

For easyfind, compare the returned position with the expected position, not only the printed value. Both 7s print the same, so position matters. For missing/empty searches, check that the catch block is reached without trying to read a missing element. For a const container, test a successful read, and separately confirm that attempting a write is rejected by the compiler.

Then test larger inputs, numeric limits, rejected operations, copies that can change independently, self-assignment, and const access. Call each template member I want to check; including its declaration alone is not enough.

Compiler warnings catch some mistakes; they do not prove correctness. AddressSanitizer detects many memory errors; UndefinedBehaviorSanitizer detects many invalid operations. Neither catches every defect. Recovery-mode sanitizer diagnostics still indicate a failed check even with exit status 0.

## Beyond CPP08: Ranges, Views, and Composition

C++20 ranges algorithms can work with range objects; views describe lazy operations such as filtering without necessarily owning the elements. `std::span` is a non-owning view of contiguous storage, distinct from the exercise class named Span. A view does not extend the lifetime of its source automatically; some view adaptors can own their source, so inspect the particular type rather than assuming all views borrow.

Iteration exposes representation capabilities. MutantStack can use the protected `c` member as an exercise, but standard adaptors are not polymorphic bases with virtual destructors. Use value objects here; do not delete a derived adaptor through its base pointer. Composition gives an application more control over what it exposes.

For the full CPP08 walkthrough and typed checkpoints, see [Journal-August.md](Journal-August.md). For outstanding defects with evidence, see [Code-review.md](Code-review.md).
