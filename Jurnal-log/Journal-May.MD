# C++ Learning Journal: 42 CPP Modules
 
A chronicle of my journey through C++ fundamentals, from basic CPP concepts to advanced polymorphism and memory management.
 
---
 
## Module Overview
 
| Module | Duration | Focus Area                 |
|--------|----------|----------------------------|
| CPP05  | 2 days   |		Exceptions			 |
| CPP06  | 2 days   |  							 |
| CPP07  | 3 days   |  |
| CPP08  | 6 days   |  |
| CPP09  | 6 days   |  |



---
05:
ex00 - `<exception>` provides `std::exception`, the standard exception base class; `<stdexcept>` provides common derived error types.

**TRY** - anticipation
**THROW** - signal occurance
**CATCH** - handle

	std::bad_alloc - new
	std::bad_cast - dynamic_cast
	std::logic_error - internal logic
	std::runtime_error


# exception class is designed to be thrown and caught:
	they are used with throw and catch in catch blocks. 
	-> it inherits from the base class : public std::exception
	-> it creates a nested class inside the main class who's rules becomes logically tied to exception.
	->> default public method what(): returns error message;
		-virtual: use my custom method version
		-const char* - standard C string return message
		-what() const - won't modify exception object
		-throw(): exception specification(promise that what() won't call excep itself while curr exc is handeled, to avoid crash)

# the throw flow: stack unwinding
**throw by value happens** - handeled by the class
	program stops it's normal path: constructor aborts building the obj 
	-> when unwinding to a handler, destroy completed automatic objects and constructed base/member subobjects. A failed constructor does not run the destructor of the complete object. Avoid exceptions escaping destructors; an exception escaping one during unwinding can terminate the program.
	->skips all until the matching catch block : exceptions are matched by their DATA TYPE
	->in the main we use base class match without specific type, it works because of inheritance and we just want the log message.
	->specific type is used in cases when we want to fix the problem or change the behaviour.
	->after chatch block finshes, the program continues.

**catching by &** and with *virtual* custom overriden what() polymorphism is **dynamic dispatch** :
	the fucntion that runs is decided by the obj not the type

# hpp: clues
because of const name: it must be set at instantiation if obj is created.
because obj must instantiate a valid grade range an exception must be thrown if invalid.
**to fullfill these requirements we need a parameterised consturctor that will initialise:**
inside the block we check if valid, then assign. while name must be set at construction.

# cpp: flow
MAIN : TRIES(suspects) -> CLASS : THROWS(alarm) -> MAIN : CATCHES(the fix)

the order of catch matching matters: always order from most specific(derived classes) to most generic(base classes)

base class catch is a common use for log errors or to move on

specific type when planning to fix a problem or react differently.




	ex01
# DEPENDENCY : USES-A - weakest class relashionship
Form and Bureaucrat interact with Form -> Association

different from *aggregation* - a pointer/reference memeber - but owner doesn't control obj's lifetime

WE HAVE BeSigned() and IsSigned() where they interact by reference.

**The Bureaucrat asks the Form to sign it using form.beSigned(*this)*. The Form checks the Bureaucrat's credentials. If the credentials are bad, the Form throws an exception.**

This is exactly why we can use a forward declaration (class Bureaucrat;) inside Form.hpp instead of #include "Bureaucrat.hpp". We are just telling the compiler: "Hey, a class called Bureaucrat exists. I'm going to take a reference to it in a function later, but I don't own one, so you don't need to build it right now." If they had a "HAS-A" relationship, the forward declaration wouldn't work, because the compiler would need to know exactly how many bytes of memory a Form takes up to put it inside the Bureaucrat object.

Since Bureaucrat acts like a caller - trying to do risky job - we gave throw catch blocks inside cpp implementation.
Because of encapusaltion - each class should handle their own business.

	ex02 : authorized behaviour. no generic Form
## one abstract, beExec() is pure virtual, base class AForm delegating 3 concrete forms with own actions.
	Bureaucrat can sign and execute them.
	execute() uses template method: validation
encoding rules into code : permission levels ->abstract class
contains exceptions classes because of form logic.
objects behave like real things : follow same rules different behaviour
force error handling
# template for many forms - base abstract class AForm

-template defines common behaviour
-each concrete class implements unique action
-handling of multiple forms and features/behaviours

polymorphic excution: each subclass creates different execution of the form using same method.

execute() - validation and delegation
beExec() - virtual dispatch
execForm() - public interface - bureaucrat 

# static type vs dynamic type: polymorphism and virtual
static array of pointers to AForm - new Form alloc
dynamic forms[i++] -> execute forms - at runtime
	correct implemetnation chosen at runtime based on type

# open-closed principle (class is open for extention but closed for modification)
possible to add different forms.
AForm::execute();
same checks - different actions;

	ex03: create obj from a string
# factory pattern method - allocating memory
A factory function receives a name and creates the correct subclass object.
We don't create forms manually. The caller doesn't have to know the class name. It tells what it needs then the factory class calls the appropriate class.
If/else avoided by using dispatch table:
two arrays that loops in a makeForm that returns a pointer to a newly created AForm object.
So intern's job is object creation.
Polymorphism: it retruns a generic form that can be any of the children forms of AForm class;

Function Pointer Array
 - create array of x things: creators[3]
 - * creators[3]: things are pointers, to funcitons
 - (std::string) : these functions take string as param
 - * AFrom: will return pointer to base abstract class 

these creation functions are static -> they don't get the * this pointer. 

## rand() - fake random number generator
	srand(n) - sets the starting point - without it program runs the same squence 
	time(NULL) - returns current Unix timestamp - starting point number -> robotomy result varies.
	rand() % 2 gives 0 or 1. For ordinary simulation, C++11 `<random>` provides explicit engines and distributions. Cryptographic randomness is a separate requirement; simulation engines must not be assumed secure.

## CPP05 — missing theory and validation checklist

### Invariants and failure before mutation

Bureaucrat grades have a bounded valid range; lower numbers represent higher authority. Validate construction input before exposing an object, and validate promotion/demotion before changing its grade. Exercise both valid boundaries and a rejected step beyond each boundary. A failed operation should preserve the old valid state.

Signing and execution are separate transitions. A signed form can still reject execution because the executing grade is insufficient. The shared base checks authorization; each concrete form performs its action. This is the Template Method pattern, independent of C++ template syntax.

### Choose a consistent error contract

A function that throws on an invalid signing attempt cannot promise `noexcept`. If a function instead returns a status, its caller must inspect that status. Header, definition, and caller must agree on return type and exception behavior. The current ex01 mixes these designs; see [Code-review.md](Code-review.md).

`what()` should return a stable message without throwing. C++98 uses the matching `throw()` specification for a standard exception override; modern C++ uses `noexcept`, and `override` checks the signature. Throw by value and catch by const reference; a bare `throw;` rethrows the active exception without slicing it.

### Side effects and ownership

File creation can fail even with a valid grade. Check open/write results and report actual I/O failures. Do not claim a side effect succeeded merely because permission was granted.

An Intern factory returns ownership of a created form under the exercise's raw-pointer interface. The caller must release it on every path, including failed signing/execution. In modern code a unique_ptr return value can encode that ownership; verify the permitted interface before changing the exercise.

### Read-only identity and copying

Const names/grade requirements must initialize in the constructor and cannot be reassigned. Define which mutable state assignment copies and which identity remains unchanged. Do not use const_cast to force assignment into a const member.

### Test plan

- Valid/invalid construction at both grade limits.
- Successful and rejected promotion/demotion with state preserved on failure.
- Unsigned execution, insufficient-grade signing, insufficient-grade execution, and successful execution.
- Known/unknown factory names, correct concrete action, and cleanup after exceptions.
- Fixed-seed robotomy runs for reproducibility; random outcomes are not proof of correctness.

Connect these checks to the basic, strong, and no-throw guarantees in [basics.MD](basics.MD).


