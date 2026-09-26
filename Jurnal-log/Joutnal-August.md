# C++ Learning Journal: 42 CPP Modules
 
A chronicle of my journey through C++ fundamentals, from basic CPP concepts to advanced polymorphism and memory management.
 
---
 
## Module Overview
 
| Module | Duration | Focus Area                 |
|--------|----------|----------------------------|
| CPP05  | 8 days   |		Exceptions			 |
| CPP06  | 2 days   |  		casting				 |
| CPP07  | 7 days   |  		Templates		     |
| CPP08  | 6 days   | 		STL & ALGOS          |
| CPP09  | 6 days   |  |


08:

## STL: standard template library & <algorythms> & containers & iterators

	DATA->choose containter->pick algo->respect iterator rules

	instead of manual loop-> use containers

	<algorythms>

## ex:00

**add a range / add number**
# dependent type names;

typename keyword: we are passing entire container class

## ex01: RANGE MEMEBER FUNCTIONS

N -> unsigned int
sotred values = plain int

# template container/interator

Member Template: nested template inside the class;
Iter - placeholder
we ask for two iterators instead of the whole container
	should accept iterators from any source

**template instantiation**

# <concepts>
	template <std::forward_iterator Iter> - tells the compiler to accept iterators that read and move forward.

for largest span:

std::minmax_element -> returns std::pair (two iterators: first is the min, and second is the max)

for shortest span:

The STL way (std::sort): std::sort in modern C++ uses an algorithm called IntroSort (a hybrid of QuickSort, HeapSort, and InsertionSort). It runs in O(N log N) time.

std::adjacent_difference -> stores the calcilated difference od a adjacent pair of the container in a new container;

# addNumbers : function overloading
	the compiler will pick the riht funciton based on args;

