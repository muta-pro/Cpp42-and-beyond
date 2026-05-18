# C++ Learning Journal: 42 CPP Modules
 
A chronicle of my journey through C++ fundamentals, from basic OOP concepts to advanced polymorphism and memory management.
 
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

	std::bad_alloc - new
	std::bad_cast - dynamic_cast
	std::logic_error - internal logic
	std::runtime_error


~ exception class is design to be thrown and caught:
	they are used with **throw** and caught in **catch** blocks. 
	- it inherite from the base class : public std::exception
	- it creates a nested class - inside the main class who's rules becomes logically tied to exception.
	- default public method waht() returns error message
		virtual: use my custom method version
		const char* - standard C string return message
		throw(): exception specification (promise to compiler that this fucntion won't call excep itself while other is handeled, to avoid crash)

- the flow:
	throw happens - handeled by the class
	program stops it's normal path - constructor aborts building the obj
	skips all until the matching catch block : exceptions are matched by their data type
	in the main we use base class match without specific type, it works because of inheritance and we just want the log message.
	specific type is used in cases when we want to fix the problem or change the behaviour.
	after chatch block finshes, the program continues.

- catching by & and with *virtual* custom overriden what() -> **dynamic dispatch** 

ex01

Form and Bureaucrat interact