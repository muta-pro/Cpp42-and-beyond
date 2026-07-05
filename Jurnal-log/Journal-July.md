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

ex01:
iter - temp. func. : 
 function pointers: address to a fucntion

