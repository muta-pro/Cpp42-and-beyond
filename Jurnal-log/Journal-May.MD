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
ex00 - <exceptions> std::exeption -> base class;

**TRY** - anticipation
**THROW** - signal occurance
**CATCH** - handle

	std::bad_alloc - new
	std::bad_cast - dynamic_cast
	std::logic_error - internal logic
	std::runtime_error


# exception class is design to be thrown and caught:
	they are used with throw and caught in catch blocks. 
	-> it inherits from the base class : public std::exception
	-> it creates a nested class inside the main class who's rules becomes logically tied to exception.
	->> default public method what(): returns error message;
		-virtual: use my custom method version
		-const char* - standard C string return message
		-what() const - won't modify exception object
		-throw(): exception specification(promise that what() won't call excep itself while curr exc is handeled, to avoid crash)

# the flow: stack unwinding
	throw happens - handeled by the class
	program stops it's normal path: constructor aborts building the obj 
	-> call all it's destructors in local scope: never throw from a destructor - would terminate the program
	->skips all until the matching catch block : exceptions are matched by their DATA TYPE
	->in the main we use base class match without specific type, it works because of inheritance and we just want the log message.
	->specific type is used in cases when we want to fix the problem or change the behaviour.
	->after chatch block finshes, the program continues.

catching by & and with *virtual* custom overriden what()
is **dynamic dispatch** 

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
# DEPENDENCY : USES-A
Form and Bureaucrat interact with Form -> Association

WE HAVE BeSigned() and IsSigned() where they interact by reference.

**The Bureaucrat asks the Form to sign it using form.beSigned(*this)*. The Form checks the Bureaucrat's credentials. If the credentials are bad, the Form throws an exception.**

This is exactly why we can use a forward declaration (class Bureaucrat;) inside Form.hpp instead of #include "Bureaucrat.hpp". We are just telling the compiler: "Hey, a class called Bureaucrat exists. I'm going to take a reference to it in a function later, but I don't own one, so you don't need to build it right now." If they had a "HAS-A" relationship, the forward declaration wouldn't work, because the compiler would need to know exactly how many bytes of memory a Form takes up to put it inside the Bureaucrat object.

Since Bureaucrat acts like a caller - trying to do risky job - we cave throw catch blocks inside cpp implementation.
Because of encapusaltion - each class should handle their own business.

ex02 : authorized behaviour
encoding rules into code : permission levels ->abstract class
objects behave like real things : follow same rules different behaviour
force error handling
# template for many forms - base abstract class AForm

-template defines common behaviour
-each concrete class implements unique action
-handling of multiple forms and features/behaviours

polymorphic excution: each subclass creates different execution of the form using same method.

# static type vs dynamic type: 
static array of pointers to AForm - new Form alloc
dynamic forms[i++] -> execute forms - at runtime
	correct implemetnation chosen at runtime based on type


possible to add different forms.
same checks - different actions;

ex03: create obj from a string
# factory method
A factory function receives a name and creates the correct subclass object.
We don't create forms manually. The caller doesn't have to know the class name. It tells what it needs then the factory class calls the appropriate class.
If/else avoided by using dispatch table:
to arrays that loops in a makeForm that returns a pointer to a newly created AForm object.
So intern's job is object creation.
Polymorphism: it retruns a generic form that can be any of the children forms of AForm class;


