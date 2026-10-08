# August learning journal — CPP08: containers, iterators, algorithms

## What I am learning

I already know how to store one number, use functions, and write classes. This module teaches me to work with collections of values without writing every storage and search operation myself.

The three main pieces are:

| Piece | Plain meaning | Example |
| --- | --- | --- |
| Container | An object that stores a collection of values | A vector holding `10, 20, 30` |
| Iterator | An object that represents a position in a collection | A position pointing at the value `20` |
| Algorithm | A ready-made function that performs an operation | `std::find` searches between two positions |

An algorithm still uses loops internally. I use it because it already expresses an operation such as searching or sorting.

| Exercise | What I practice | Progress |
| --- | --- | --- |
| ex00: easyfind | Search different containers; handle missing values; read const containers | Latest pushed version checked on 8 October 2026: builds, demo runs, and extra checks pass |
| ex01: Span | Store a limited number of integers; calculate smallest/largest gaps | Still needs the fixes recorded in the code review |
| ex02: MutantStack | Keep stack operations and add a way to walk through its values | Still needs iteration, assignment, and build fixes |

“Extra checks pass” means tests run separately in the cloud workspace passed. Those extra tests have not been added to my exercise's `main.cpp`.

## 1. Choosing a container

The STL, or Standard Template Library, is the part of the standard library built around containers, iterators, and algorithms. The standard library also contains other tools such as streams and exceptions.

| Container | How to picture it | Useful property | Limitation |
| --- | --- | --- | --- |
| `vector<T>` | Values next to each other in memory | Fast access by index; easy to walk through | Adding/removing in the middle shifts values |
| `deque<T>` | A sequence with room to grow at either end | Fast indexing and adding at front/back | Its whole sequence is not one continuous memory block |
| `list<T>` | Linked nodes, each containing a value | Insert/remove at a known position without moving other nodes | Finding that position may require walking through the list |
| `set<T>` | Unique values kept in order | Efficient lookup; no duplicate keys | Stored keys cannot be changed through its iterators |
| `map<K,V>` | Keys paired with values, ordered by key | Look up a value by its key | Each element is a pair, not just the key |
| `stack<T>` | A pile: add/remove at the top | Useful when the newest value must be handled first | No public `begin()` or `end()` |

In `vector<int>`, `int` is the type of each stored element. In my easyfind template, however, `T` represents the **whole container type**, such as `vector<int>`.

`array`, `forward_list`, and unordered containers are available from C++11. Concepts and ranges are C++20 features. The compiler's selected language version decides which syntax I can use.

## 2. Understanding an iterator

An iterator is a position, not the value itself. For an iterator named `it`:

| Expression | Meaning |
| --- | --- |
| `*it` | Access the element at that position |
| `++it` | Move to the next position |
| `it == values.end()` | Ask whether it is the position after the last element |

The word **dereference** means “access the value using `*it`.”

For values `10, 20, 30`:

```text
positions:    [10]    [20]    [30]    end
               ^
             begin
```

`end()` does not point at a fourth value. It marks where the sequence stops. Never read `*values.end()`.

If a container is empty, `begin()` equals `end()`: there is no first element to read.

### What does [first, last) mean?

The brackets describe which positions belong to a range. **Include first, stop before last.** Most classic algorithms use this rule.

```cpp
std::find(values.begin(), values.end(), 20);
```

This means: start at the first element, search for 20, and stop when reaching the position after the last element.

The two positions must describe a real, valid range. Positions from unrelated containers are not a range I can safely pass to an algorithm.

### Different iterators have different abilities

These names describe what an iterator can do:

| Name | Plain meaning | Example |
| --- | --- | --- |
| Input | Read and move forward; the source may only be usable once | Reading from a stream |
| Output | Write and move forward | Adding results through a back-insertion iterator |
| Forward | Walk forward, and walk the same range again | forward_list iterator |
| Bidirectional | Walk forward or backward | list iterator |
| Random access | Also jump by an offset, like an array index | vector/deque iterator |
| Contiguous (C++20) | Also refers to consecutive elements in consecutive memory | vector of ordinary integers |

`std::find` can walk forward. `std::sort` needs to jump around, so it requires random-access iterators. A list does not have those; it provides its own `list.sort()`.

`std::distance(first,last)` counts the steps between valid positions. With a vector it can calculate the distance directly; with a list it walks through the elements.

An input iterator can represent a source that gets consumed as I read it. Counting that source first may leave nothing for a second pass. A forward iterator supports walking the same range again.

### When can an old iterator stop working?

This is called **iterator invalidation**. An iterator does not own the elements or keep them alive.

- If a vector needs a new allocation while growing, all old positions into its elements become unusable. Even without that move, appending changes the old end position.
- Removing a vector element makes positions at that element and later unusable.
- Inserting a list node leaves existing positions usable. Removing a node invalidates positions to that node.
- Adding at a deque's front/back invalidates iterators, although references to existing elements stay valid.
- Inserting in an ordered set/map preserves existing iterators; removing an element invalidates positions to the removed element.

Read the rule for the particular container operation before reusing an old iterator.

## 3. ex00 — easyfind, step by step

### What should this function do?

Give it a container and an integer to search for.

- If that integer exists, return a position pointing to its first occurrence.
- If it does not exist, throw an exception so the caller can handle the missing value.

`std::find` itself does not throw just because a value is absent. It returns the final position supplied to it. My easyfind adds the exception.

### Reading the template syntax

Start with a function for one specific container:

```cpp
std::vector<int>::const_iterator
easyfind(const std::vector<int>& cont, int n);
```

This declaration says: “Search a read-only vector of integers and return a read-only position in that vector.”

A template lets me replace the repeated container type with a placeholder:

```cpp
template <typename T>
typename T::const_iterator easyfind(const T& cont, int n);
```

| Part | Read it as |
| --- | --- |
| `template <typename T>` | This function pattern has a placeholder type named T |
| `const T& cont` | Receive the original container without copying it; do not change it through cont |
| `T::const_iterator` | The read-only iterator type provided by that container |
| The second `typename` | Tell the compiler that T::const_iterator is a type name |
| `int n` | The integer I want to find |

For a const vector call, the compiler fills in `T = std::vector<int>`. This is called **template instantiation**: using the pattern to form a function for a particular type.

`::` means “look inside this scope.” `std::vector` names vector inside std; `T::const_iterator` names a type inside the container class.

A **type** describes what kind of object I can create. A **variable** is an actual object with a name. In `T::const_iterator it`, the type is `T::const_iterator`; the variable name is `it`.

### What does overload mean?

An overload is another function with the same name but different parameters.

My first easyfind receives `T&` and returns `T::iterator`. My second receives `const T&` and returns `T::const_iterator`.

For my ordinary vector call, the compiler picks the first. For my const vector call, it picks the second. It uses the argument and parameter types to choose; changing only a return type cannot create an overload.

Templates let me reuse these patterns for different containers. Overloading lets me offer a mutable and a read-only version.

| Iterator for vector/list/deque | Read a value | Change a value | Move to next position |
| --- | --- | --- | --- |
| `iterator` | Yes | Yes | Yes |
| `const_iterator` | Yes | No | Yes |

`const iterator` is a different spelling: it prevents moving the iterator variable itself. It is not the same as `const_iterator`.

In the const overload, both the return type **and the local variable holding the search result** must allow read-only access. My earlier compile error happened because the local variable was still a mutable iterator.

### Why check end before using the result?

Searching `10,20,30` for 99 returns `end()`. Reading `*it` at that position would be invalid.

My function already compares the result with end and throws if they are equal. The caller's catch block can then print “not found.” I do not need to dereference the missing result.

### Is the header organized correctly?

The current header has the needed pieces:

1. `#ifndef` / `#define` / `#endif`: the include guard prevents the contents being processed twice in one source file's compilation.
2. `#include <algorithm>`: declares `std::find`.
3. `#include <exception>`: declares `std::exception`. The filename is singular: **exception**, not exceptions.
4. Both template definitions: these normally stay in the header so the compiler can see their bodies when it needs them.

The functions do not directly use vector/list/deque, so their headers can stay in the caller. The vector example at the bottom is a comment and needs no additional include.

It previously worked because another included header happened to bring in std::exception too. This is an **indirect include**. I should include the header for each library tool I use directly rather than rely on that coincidence.

### Small tests I can type myself

A test means: choose an input, run the function, and compare the result with something I already know should happen.

| What to try | What should happen | What I learn |
| --- | --- | --- |
| vector `10,20,30`, search 20 | Position points to 20 | Ordinary search works |
| Same kind of search in a list and deque | Found value is correct | The template works with more than one container |
| Empty vector, search 20 | Catch the missing-value exception | An empty collection is handled safely |
| `7,1,7`, search 7 | Returned position equals begin | It finds the first 7, not the later one |
| `10,20,30`, search 99 | Catch the exception; do not read a missing element | Missing values are handled safely |
| Const vector `1,2`, search 1 | Read 1 through the returned iterator | Read-only containers work |

Repeat the empty, duplicate, and missing-value tests with list/deque when comfortable.

To check that a const result cannot write, try assigning through `*it` in a **separate small compilation**. That attempt should fail to compile. Do not leave it in the normal executable and expect the build to succeed.

My current demo uses const `cvec = {1}` and searches for 22, so “number 22 not found” is the correct result. Add a separate search for 1 to see the const overload succeed too.

### Checked on 8 October 2026

The current seven demo searches built and ran. Separate scratch tests passed 15 runtime checks: found/missing/empty/duplicate cases for vector/list/deque, const-vector success/failure, and writing through a mutable result. The iterator types were checked at compile time. Writing through a const result was rejected as expected. The header compiled by itself.

These checks used the pushed code unchanged. I still need to type the extra cases into my own demo if I want them saved with the exercise.

## 4. ex01 — Span

### Begin with the stored state

Span keeps integers in a vector and remembers the maximum count it allows.

An **invariant** is a rule that must remain true while an object is usable. For Span:

- The stored count must never exceed the limit.
- A copied Span must contain the same values and limit, independently of the original.
- Asking for a span must not change the stored values or their original order.
- Rejecting an insertion must preserve the state promised by the function.

`reserve(10)` prepares space but does not create ten elements. `resize(10)` actually creates ten elements. The exercise's limit is my own rule; vector can grow further unless I check it.

to release the reserved memory -> swap()
    std::vector<int>().swap(v); internal buffer get's swaped with a temporary empty vector that get's destroyed at the end of the expression.

*performance* 
reserve() is memeber method in vector used to preallocate memory increasing it's capacity - not changing it's size (adding elements) - modifies internal buffer size. this reserves memory in advance perventing multiple allocatoins and data copies during elements addition. O(1);

### First checkpoint: constructors and copying

A constructor initializer names an existing member, such as `_capacity`; it is not a place to declare a new variable.

Keep one constructor definition for each signature and one consistent capacity member name. Initialize the default state deliberately. The vector can copy its values itself; I do not need to manually delete its contents.

Copy construction creates a new object. Assignment replaces the state of an existing object. Assignment returns `Span&`; `return *this` returns the current object by reference. To check for self-assignment, compare `this` with `&other`: both are addresses.

Ensure declarations in the header match definitions in the source, and include Span.cpp in the Makefile's sources. Use the same range-function name in the header and demo.

In modern code, allowing vector/string to handle cleanup and copying is called the **Rule of Zero**. If the exercise asks for explicit special members, write them, but keep the container's automatic ownership.

### Second checkpoint: add values safely

For one value: check space first, then append. A zero-capacity Span rejects its first value.

For a range: receive a first position and an ending position. Count how many elements will be added, check that they fit, then insert. A rejected oversized valid range should not partly fill the object.

A **member template** is a class function with its own type placeholder. Span still stores int, but its range function can accept positions from different containers. Keep that template definition in the header so the compiler can use it for each iterator type.

Your C++20 constraint `std::forward_iterator<Iter>` means “accept an iterator that can walk the same range more than once.” That matters because counting and then inserting are two passes.

`std::convertible_to<...,int>` asks whether the type can convert to int. It does not prove every value fits: a huge double can still have a permitted conversion that is unsafe for that particular value. Choose an int-only requirement or a documented checked conversion policy.

A negative distance check cannot validate every bad range. Never use positions from unrelated containers, and do not reverse a list range expecting an exception. If I later expose positions into my private storage, inserting from that same storage needs special care; a separate source copy can avoid the overlap.

Test one value, exactly full, one beyond full, an empty range, a fitting range, and a valid range too large to fit. After rejection, verify the previous contents remain as promised.

### Third checkpoint: largest and smallest gaps

A span is the distance between stored values, not the distance between their positions.

For `6,3,17,9,11`:

- Largest gap: 17 minus 3 = **14**.
- Sort a copy: `3,6,9,11,17`.
- Neighboring gaps: `3,3,2,6`.
- Smallest gap: **2**.

Checking neighbors works because a gap between non-neighbors is the sum of smaller neighboring gaps. It cannot beat every gap contained in it. Repeated values give a smallest gap of zero.

`minmax_element` (C++11) finds the smallest and largest values and returns two iterator positions in a pair. Separate min/max passes are another option. Sorting a copy lets the query leave my original ordering unchanged.

**Do the arithmetic in a type large enough before subtracting.** On this machine, the gap between INT_MIN and INT_MAX is 4,294,967,295, which does not fit in signed int. Casting the result afterward is too late. A suitably wide intermediate such as long long on this machine helps; the return type must also hold the result.

`adjacent_difference` first copies the initial value to its output, then writes gaps. Its default subtraction still uses the input value type. A larger output type alone does not fix int overflow. A loop over neighbors, converting both operands before subtracting, is a clear first implementation to type.

| Values or operation | Expected result |
| --- | --- |
| No values or one value; ask either span | Exception: there are not two values to compare |
| `6,3,17,9,11` | Smallest 2; largest 14 |
| `5,5` | Both 0 |
| `-10,-3,2` | Smallest 5; largest 12 |
| INT_MIN and INT_MAX | Exact full distance, with safe arithmetic |
| Ask twice | Same answer; original values unchanged |
| Copy, then change one object | Other object's values unchanged |
| Values 0 through 9999 | Smallest 1; largest 9999 |

Start with fixed inputs where I know the answers. Then try a large collection. Random data is useful later, but a random output alone does not tell me whether the answer is right.

### How much work do the algorithms do?

Here n means the number of values, not the number of seconds:

- Finding the smallest/largest values visits the collection: O(n).
- Sorting costs O(n log n) comparisons; checking neighbors afterward is O(n).
- Copying the values needs room for another n values: O(n) extra storage.

std::sort promises a complexity bound, not one particular internal sorting method.

## 5. ex02 — MutantStack

### What a stack gives me

A stack handles the newest value first: **last in, first out**, or LIFO.

| Function | Meaning |
| --- | --- |
| push | Add a value at the top |
| top | Access the current top value |
| pop | Remove it; does not return the value |
| empty | Ask whether any values remain |
| size | Count the stored values |

Check for emptiness before top/pop.

std::stack is a **container adaptor**: it wraps another container and exposes only selected operations. Its usual underlying container is a deque. That container is a protected member named `c`; a derived class can access it.

MutantStack adds a way to walk through the existing values. It should not keep a second copy of the whole collection.

### Follow the iterator type

The type-name path is: stack → its `container_type` → that container's `iterator`.

The backing container type depends on the stack's template argument, so the iterator type is a dependent name. Use typename to mark it as a type. Use `this->c` to refer to the member from the template base class.

Add mutable begin/end functions and const begin/end functions. A const stack should let me read its elements, not change them. Reverse iteration can be a later extension.

Forward iteration walks from the oldest/bottom value to the newest/top value. Repeated top/pop walks the other way and removes values.

### Copying and build checks

Let std::stack copy its own stored values. No raw allocation is needed.

The self-assignment check must compare two addresses: `this` and `&other`. Fix the sanitizer option so it is one argument: `-fsanitize=address,undefined`, without a space after the comma.

An empty main does not test a template's functions. Call assignment, copying, and iteration so the compiler has to check those operations.

Use stacks as ordinary value objects here. Do not delete a MutantStack through a std::stack pointer: std::stack has no virtual destructor. In a general application, keeping a container as a member instead of inheriting from it is often easier to control; that design is called composition.

### My test sequence

Push 5 and 17: top should be 17. Pop once: top should be 5. Then push 3,5,737,0. Walking forward should give `5,3,5,737,0`.

Next, change a value through a mutable iterator; read through a const stack; copy and assign stacks; change one and confirm its copy stays unchanged. Try self-assignment. Compare the forward sequence with the same values in a list. Never read end or access an empty top.

## 6. What remains for this study session

- [ ] Explain T, typename, iterator, const_iterator, and overload in my own words.
- [ ] Type the missing easyfind test cases into my demo.
- [ ] Make Span constructors, signatures, demo calls, and build sources agree.
- [ ] Check that all insertion paths respect the capacity rule.
- [ ] Implement safe gap arithmetic and verify the fixed expected results.
- [ ] Test 10,000 stored values with known answers.
- [ ] Implement and test MutantStack iteration and copying.
- [ ] Build with the chosen language version and read sanitizer diagnostics.

AddressSanitizer checks many memory errors. UndefinedBehaviorSanitizer checks many invalid operations. A diagnostic still means something went wrong even if the process exits with zero. Neither tool proves every behavior is correct.

## 7. Later topics, after the core exercises work

Learn these names gradually:

| Topic | Plain meaning |
| --- | --- |
| Exception guarantees | What remains valid when an operation fails |
| Rule of Zero | Let owning member types manage cleanup and copying |
| Strict weak ordering | A sorting comparison must give consistent answers; x must not be less than itself |
| C++20 views | Ways to describe/filter a sequence without necessarily copying its values |
| Lifetime | How long the data behind an iterator or view stays alive |

For sorting, `<` can be a valid comparison; `<=` is not an ordinary sort comparator because it says an element precedes itself. Ordering also needs consistency and transitivity: if a comes before b and b before c, a must come before c.

A view does not automatically keep borrowed data alive. Some views own their source, so check the particular type. C++20 std::span is a view of consecutive elements; it is different from the exercise class named Span.

For CPP09, later practice parsing, key-based lookup, stack expression evaluation, and comparing algorithm costs. There is no CPP09 exercise directory here yet.

References: [iterators](https://en.cppreference.com/w/cpp/iterator), [vector](https://en.cppreference.com/w/cpp/container/vector), [find](https://en.cppreference.com/w/cpp/algorithm/find), [stack](https://en.cppreference.com/w/cpp/container/stack), [adjacent_difference](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference).
