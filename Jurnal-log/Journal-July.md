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
for swap, instead of making copies, we transfer ownership using **std::move();** -> CAST: LVALUE treated as RVALUE (temp value)

expressions: lvalue and rvalue;
const T&
T&& binds only to rvalues

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

iter(arr, len, [](const int&x){std::cout << x;});

# sizeof(): returns bytes;
	since we need number of elemnts = just divide tot arr bytes with 4 bytes (one element arr[0]);

ex02: class template array - safe, dynamically allocated array that works with any data type; pervents overflows;

the heap alloccation: dynamic memory with new - because we will know the elements during runtime, unlike stack that knows during compile time - it just gives a pointer to _elements address._ 

Array<int> arr(n); - class manages the memory - allocated in the constructor;

deep copy is crucial to avoid pointing at the same memory; allocate new memory and copy the values;

because accessing arrays is familiar to native arrays, but class doesn't know yet how to use it - overload[] ;

assignment operator is used only when obj is assigned to other object, not int to an object;
