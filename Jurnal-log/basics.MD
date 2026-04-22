
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

In a `struct`:

* members are `public` by default

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

## Heap Preference and Dynamic Allocation

In C++, stack allocation is usually preferred by default because it is simple, automatic, and safe. But heap allocation is useful in specific cases.

Heap allocation is often chosen when:

* object size must be dynamic
* the object must outlive the current scope
* ownership must be shared or transferred
* polymorphism requires handling derived objects through base pointers
* the object is very large

Example:

```cpp
Dog* d = new Dog();
delete d;
```

But raw `new` and `delete` are dangerous because they make lifetime manual. In modern C++, ownership tools replace this more often.

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

* store with left shift by 8
* `n << 8` means `n * 256`

For floats:

* multiply by `256`
* round to nearest integer
* store the result as the internal fixed-point integer

To convert back:

* to float: divide by `256`
* to int: remove the fractional bits, usually with a right shift by 8

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

If `Animal` does not have a virtual destructor, the `Dog` destructor may never run correctly.

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

An **lvalue** is something with an identifiable location in memory. It can appear on the left side of assignment.

An **rvalue** is a temporary value or pure result, usually not something I can assign into.

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

# Final Summary

The big lesson is that C++ is a language of **models and lifetimes**.

A namespace organizes names.
A class models a concept.
An object owns data and lives through a constructor/destructor cycle.
Encapsulation protects meaning.
Inheritance builds hierarchies.
Virtual functions make behavior depend on the real runtime object.
References and const make interfaces safe and expressive.
Fixed-point numbers show how representation can be designed manually instead of taken for granted.
