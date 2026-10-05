# C++ Learning Journal: 42 CPP Modules
 
A chronicle of my journey through C++ fundamentals, from basic OOP concepts to advanced polymorphism and memory management.
 
---
 
## Module Overview
 
| Module | Duration | Focus Area                 |
|--------|----------|----------------------------|
| CPP00  | 2 days   | Class basics, canon form   |
| CPP01  | 2 days   | Memory, refs, pointers     |
| CPP02  | 3 days   | Operator overloading       |
| CPP03  | 6 days   | Inheritance, constructors  |
| CPP04  | 6 days   | Polymorphism, virtual dtor |

---

## CPP03: Inheritance and Constructors

### Core Concept: Building New Classes on Top of Existing Ones

Understanding how classes can inherit from each other and the implications of the construction chain.

---

### Ex00: Class Design Fundamentals

**Goal:** Model a game entity with stateful behavior

#### Key Concepts

**Object State:** Defined by attributes that change through member functions
- Data and actions on that data are coupled together
- State changes are controlled through methods

#### Orthodox Canonical Form (OCF) Implementation

**Constructor:** Establishes object's initial state

**Methods that modify state:**
- `attack()` → Action that consumes energy points
- `takeDamage()` → Reduces hit points (minimum 0)
- `beRepaired()` → Increases hit points if enough energy available

#### Object Behavior Depends on Internal State

Particularly hit points and energy points.

#### Testing Strategy in `main()`

1. **Object creation verification:** Objects can be created in different ways
2. **Assignment operator:** Existing object can receive state from another object
3. **Energy consumption:** Repeated actions drain energy
4. **Death state:** Dead ClapTrap is prevented from repairing
5. **Normal state:** Fresh object can repair successfully
6. **Energy limit:** Once exhausted, further actions must fail

**Key insight:** The object behavior depends entirely on its internal state.

---

### Ex01: Inheritance Basics - ScavTrap

**Concept:** Construction Chain

When creating a derived object:
1. Constructor creates base-class part first
2. Then constructs derived-class part
3. Child class doesn't inherit the constructor automatically—it calls parent's constructor

#### Access Modifiers for Inheritance

**`protected` keyword:** Makes attributes available to child classes
- Use instead of `private` when inheritance is expected
- Derived object reuses parent's data and methods instead of duplicating them

**Mental model:** One object with layers

#### Method Overriding

In modern C++:
```cpp
void attack(const std::string &target) override;
```

In older C++, overriding still happens without the `override` keyword **if the base function is virtual and the signature matches**. A same-named non-virtual base function is hidden instead. The modern keyword asks the compiler to verify an override.

---

### Ex02: FragTrap - Multiple Derived Classes

Building a second derived class from the same base, demonstrating that multiple classes can inherit from one parent while maintaining their own unique behaviors.

---

### Ex03: DiamondTrap - Multiple Inheritance & Virtual Inheritance

**The Diamond Problem:** Classic multiple inheritance shape

```
        ClapTrap
        /      \
   ScavTrap  FragTrap
        \      /
       DiamondTrap
```

#### Multiple Inheritance Creates Ambiguity

**Concept:** A class can inherit traits from multiple derived classes → trait composition

#### Identity Management

**Dual identity:**
- Its own name
- Inherited name (to show that an object has its own identity but also a base identity)

The derived class may keep its own state while also managing inherited state explicitly.

#### Conflict Resolution

In multiple inheritance, when parent classes have the same function name:
- You don't take both versions
- One parent's version is chosen (e.g., `attack()` from ScavTrap)

**Result:** DiamondTrap is a ClapTrap with data and behavior from child classes available, while having its own identity.

**Testing:** `whoAmI()` method clearly tests the multiple identity tracking.

#### Virtual Inheritance Solution

**Problem:** Duplicate base subobject ambiguity  
**Solution:** `virtual` keyword creates one shared ClapTrap base

```cpp
class ScavTrap : virtual public ClapTrap
class FragTrap : virtual public ClapTrap
```

**Important:** Once ClapTrap is a virtual base, the hybrid class (DiamondTrap) must construct it directly.

#### Two Types of Ambiguity Resolution

1. **Duplicate base subobject:** Solved by virtual inheritance
2. **Same-function-name:** Solved by explicit qualification (e.g., `ScavTrap::attack()`)

#### Constructor overwriting problem: 
    
    when Diamond obj is created - constructors are called in an order that each call overwrites the values of shared variables of the previous. 

    SOLUTION is the use of static const vars in parent class to set correct values.
    Because of virtual inheritance, ScavTrap::_EnergyPoints is not a separate variable. It points to the exact same shared foundation variable that FragTrap just changed to 100.


---

## CPP04: Polymorphism and Virtual Destructors

### Core Concept: Runtime Type Determination

Polymorphism allows objects to behave differently based on their actual type, even when accessed through base class pointers.

---

### Modern C++ Features Used

- `override` keyword → Forces compiler to verify function is actually overriding
- `= default` for constructors → Explicitly request compiler-generated version
- Direct member initialization → Initialize at declaration
- `std::unique_ptr` → Smart pointers instead of raw pointers (though this module uses raw pointers for learning)
- `auto main() -> int` → Trailing return type syntax

**Benefit:** These keywords force the compiler to fire warnings if syntax is wrong.

---

### Static vs. Dynamic Binding

#### Static Binding (Early Binding)
- Compiler determines which function to call at compile-time
- Occurs without `virtual` keyword
- Based on pointer/reference type, not object type

#### Dynamic Binding (Late Binding)
- Determined at runtime
- Requires `virtual` keyword
- Based on actual object type

#### Upcasting

**Definition:** Converting a derived pointer/reference to an accessible, unambiguous base pointer/reference. It does not require dynamic allocation.

```cpp
Animal* animal = new Dog();
```

Without `virtual`, the compiler treats it as an `Animal` → static binding.

#### V-Table (Virtual Table)

A common implementation for classes with virtual functions (not a language-mandated layout):
- Compiler generates a table of virtual function pointers
- Lets the compiler check the actual class of the object at runtime
- Even though the pointer type is `Animal`, it dynamically binds to `Dog::makeSound()`

**Memory safety:** Virtual destructor ensures subclass destructor is called, preventing memory leaks.

**Key insight:** `virtual` makes the compiler check the structure beneath the syntax.

---

### Ex00: Basic Polymorphism

Demonstrating how virtual functions enable polymorphic behavior through base class pointers.

---

### Ex01: Composition & Deep Copy

**Core Challenge:** Memory management when working with pointer members

Classes contain a pointer member: `Brain* _brain`

#### Concept 1: Composition (Has-A Relationship)

Combining smaller objects to create a complex one.
- `Dog` HAS-A `Brain`
- `Cat` HAS-A `Brain`

#### Concept 2: The Shallow Copy Trap

**Problem:** By default, copying an object copies pointer values, not what they point to.
- Two objects share the same memory address
- Deleting one object's `_brain` invalidates the other's pointer
- Second deletion causes double-free → crash

**Solution: Deep Copy**
- Allocate brand new instance of `Brain`
- Copy the contents of the original `Brain`
- Each object owns its own `Brain`

**Earlier sketch — allocation-failure safety is incomplete:** The assignment below deletes the old Brain before creating a replacement. If allocation throws, the member dangles. It also omits copying the base state. Use it to identify the problem, not as a finished implementation: establish replacement ownership before releasing old state.
```cpp
// Copy constructor
Dog(const Dog& other) {
    _brain = new Brain(*other._brain);  // Deep copy
}

// Assignment operator
Dog& operator=(const Dog& other) {
    if (this != &other) {
        delete _brain;                  // Clean up old
        _brain = new Brain(*other._brain);  // Deep copy new
    }
    return *this;
}
```

#### Testing Strategy: Two Arrays

**1. Brain array `Animal arr[]`:**
- Tests DEEP COPY
- Teaches how to copy big data from one heap allocation to another
- No shared pointers

**2. Pointer array `Animal* arr[]`:**
- Tests polymorphic destruction
- Putting two subclass objects into generic array
- Loop to delete: no leaks of `Brain` because base class destructor is virtual
- **Avoids object slicing:** Storing objects directly would remove `Brain` from subclass to fit into base `Animal` slot
- Pointers are all memory-address-sized, pointing to different complete objects

#### Concept: Delegation

**Brain:** Owns raw data → array of strings (ideas)  
**Dog/Cat:** Messenger → Receives the idea and passes it to Brain

---

### Ex02: Abstract Base Class

**Definition:** A class with at least one pure virtual function

```cpp
class Animal {
    virtual void makeSound() const = 0;  // Pure virtual
};
```

**Characteristics:**
- Incomplete and cannot be instantiated as an object
- Provides shared interface design
- May provide some implementation for derived classes
- Forces derived classes to implement specific functions

**Purpose:** Define a contract that derived classes must fulfill.

---

### Ex03: Interface vs. Abstract - Design Patterns

This exercise introduces advanced OOP patterns using the example of a magic system.

---

#### Pattern 1: Prototype Pattern (Cloning)

**Problem:** Polymorphic copy for abstract base classes without knowing the type at compile-time.

**Challenge:** The object must copy itself according to its real runtime type.

#### Use of Base Pointers

Program handles materias through base-class pointers:
```cpp
AMateria* m;
```

**Benefit:** One inventory can hold different derived types (Ice, Cure), as long as they inherit from the base.

#### The Cloning Problem

Real type is hidden behind base pointer. When cloning:
```cpp
AMateria* copy = original->clone();
```

**If we tried:**
```cpp
AMateria copy = *original;  // WRONG - object slicing
```

**Two problems:**
1. **Object slicing:** Derived-class specific data gets lost, only base-class gets copied
2. **Cannot instantiate abstract class:** `AMateria` is abstract

**Solution:** `clone()` method
```cpp
virtual AMateria* clone() const = 0;

// In Ice class:
AMateria* clone() const override {
    return new Ice(*this);  // Creates new Ice, preserving type
}
```

The object creates a copy of itself with the correct dynamic type preserved.

---

#### Pattern 2: Interface-Based Design

**Interface class:** Defines rules (pure virtual functions) that concrete classes must implement.

**Example:**
```cpp
class ICharacter {
public:
    virtual void equip(AMateria* m) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
    virtual ~ICharacter() {}
};
```

No data members, only pure virtual functions → pure interface.

---

### Inventory Management & Factory Pattern

#### 1. Character Class - Fixed-Size Array Pattern

**Data structure:** Fixed-size array of materia pointers

**Methods:**
- `equip(AMateria*)` → Fills first empty slot (NULL)
- `unequip(int idx)` → Sets slot to NULL (doesn't delete—caller's responsibility)
- `use(int idx, ICharacter& target)` → Calls `materia->use(target)`

**Earlier deep-copy sketch — not a complete assignment operator:** The following lacks a self-assignment guard and `return *this`, and deletes ownership before risky cloning. On self-assignment it can read freed objects. Type a replacement that stages owned clones safely before committing; consult the exception guarantees in [basics.MD](basics.MD).
```cpp
Character& operator=(const Character& other) {
    // 1. Clean up old materias
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
    // 2. Deep copy new materias
    for (int i = 0; i < 4; i++) {
        _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
    }
}
```

#### 2. MateriaSource Class - Factory Pattern

**Purpose:** Type-based creation of materias

**Methods:**
- `learnMateria(AMateria*)` → In the current code, takes ownership of the supplied prototype rather than cloning it; document that ownership contract
- `createMateria(const std::string& type)` → Returns clone of template by type

**Pattern:** Factory that creates objects based on string identifiers

```cpp
AMateria* createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    return NULL;
}
```

**Key insight:** The factory doesn't need to know all possible types at compile-time. It uses the stored templates and their `clone()` method.

---

### Design Pattern Summary

| Pattern | Purpose | Implementation |
|---------|---------|----------------|
| **Prototype** | Clone objects preserving runtime type | `clone()` method returns `new DerivedType(*this)` |
| **Interface** | Define contracts for classes | Pure virtual functions only |
| **Factory** | Create objects by type identifier | Store templates, return clones by string lookup |
| **Composition** | Build complex objects from simpler ones | Classes contain pointers to other objects |
| **Deep Copy** | Safe copying of objects with heap data | Copy constructor and assignment operator allocate new memory |

---

## Key Learnings

### Memory Management
- Understanding stack vs. heap allocation
- When to use references vs. pointers
- RAII pattern for automatic resource cleanup
- Deep copy vs. shallow copy: preventing double-free errors
- Composition: managing lifetime of owned objects

### Object-Oriented Design
- Proper constructor/destructor patterns
- Const correctness for performance and safety
- Member function pointers for flexible dispatch
- Virtual destructors for polymorphic deletion
- Abstract base classes as contracts

### Operator Overloading
- Making custom types behave like built-in types
- Fixed-point arithmetic without floating-point operations
- Efficient geometric algorithms using only integer math

### Inheritance Patterns
- Construction chain: base before derived
- `protected` vs. `private` access control
- Virtual inheritance solving the diamond problem
- Multiple inheritance and conflict resolution
- Object slicing prevention with pointers

### Polymorphism
- Static binding vs. dynamic binding
- Virtual functions and V-tables
- Upcasting and runtime type determination
- Pure virtual functions and abstract classes
- Interface-based design

### Design Patterns
- **Prototype Pattern:** Cloning objects preserving runtime type
- **Factory Pattern:** Type-based object creation
- **Composition Pattern:** Has-A relationships
- **Interface Pattern:** Defining contracts through pure virtual functions

### Best Practices
- Prefer `const` references to avoid unnecessary copies
- Use initialization lists for const and reference members
- Choose algorithms that avoid division and floating-point operations when precision matters
- Always make base class destructors virtual when using inheritance
- Use deep copy for classes managing heap memory
- Leverage polymorphism through base class pointers/references

---

## Resources & References

- 42 School C++ Modules (CPP00-CPP04)
- The C++ Programming Language - Bjarne Stroustrup
- Effective C++ - Scott Meyers

---

## CPP03–CPP04: Additional theory checkpoints

### CPP03 — construction order, hiding, and slicing

Construction order is: virtual bases, direct bases in declaration order, members in declaration order, then the constructor body. Destruction reverses that order. Writing a different initializer-list order does not change it. The most-derived class initializes a shared virtual base.

Access and inheritance are different decisions. Public inheritance preserves the public base interface; private inheritance restricts it. Use protected members only when the design needs derived access; private state with a deliberate interface often protects invariants better.

Overloading means different parameter lists. Overriding replaces virtual behavior with a matching derived implementation. Hiding can make base overloads unavailable by name; a `using Base::function` declaration can restore an overload set. `Base::function()` explicitly calls that implementation.

Copying a derived object into a base value slices away its derived part. A base reference or pointer can preserve access to the dynamic object, but does not automatically own or extend its lifetime. Test both value and reference cases to see the distinction.

The diamond exercise combines two issues: a shared base's state and ambiguous inherited names. Virtual inheritance solves shared identity; explicit qualification solves name ambiguity. State changes in constructor bodies can still overwrite the same shared base members, so trace the final invariant rather than assuming a qualification selects separate storage.

### CPP04 — dispatch, destruction, and owned resources

Virtual dispatch during a constructor/destructor uses the class currently being constructed/destroyed, not a more-derived part whose lifetime is not active. Avoid relying on derived behavior to establish or clean up a base invariant.

Deleting a derived object through a base pointer without a virtual destructor is undefined behavior. A polymorphic class needs at least one virtual function for the usual runtime-checked downcasts; that virtual function does not have to be its destructor. A virtual destructor is the safe deletion requirement when the base is used as an owning polymorphic interface.

An abstract class can have constructors, data, and ordinary member functions. A pure virtual destructor still needs a definition because derived destruction calls it. Vtables are a common implementation technique, not a mandated C++ object layout.

Composition with Brain means owning a separate resource. Independent copying must clone the state, not just copy its pointer. If a later allocation or clone throws during construction, clean up earlier resources; the enclosing destructor will not run for an object that never finished construction.

For Materia: document who owns a newly created, equipped, rejected, and unequipped object. Never equip the same owning pointer twice. Test self-assignment and partial-copy failure in addition to successful cloning. A clone's base-pointer return type preserves a uniform interface, while virtual dispatch selects the concrete clone implementation.

See [Code-review.md](Code-review.md) for the current MateriaSource self-assignment defect and copy-safety follow-ups. Study coverage and verified implementation progress are separate.


