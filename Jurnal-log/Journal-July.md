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
- building containers - linkedlist, stack, queue - > class containers to hold anythyng

- generic algorythms - sorting/searching/swapping

- utility/conversion functions

ex00:

