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
| ex01: Span | Store a limited number of integers; calculate smallest/largest gaps | Current version checked on 13 October 2026: demo and template checks pass |
| ex02: MutantStack | Keep stack operations and add a way to walk through its values | Still needs iteration, assignment, and build fixes |

For easyfind, “extra checks” refers to separate scratch tests. Span's current `main.cpp` already saves checks for its calculations, insertion limits, copying and 10,000 values; additional template checks were run separately.

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

My first easyfind receives `T&`; the second receives `const T&`. Both currently use `auto` to deduce the iterator returned by std::find: mutable for an ordinary vector, read-only for a const vector.

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
3. The current `#include <stdexcept>` also makes `std::exception` available. Its direct header is `<exception>`, singular; `<stdexcept>` declares the more specific errors used by Span.
4. Both template definitions: these normally stay in the header so the compiler can see their bodies when it needs them.

The functions do not directly use vector/list/deque, so their headers can stay in the caller. The vector example at the bottom is a comment and needs no additional include.

An **indirect include** brings a declaration through another header. For clear dependencies, include the header for each library tool used directly.

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

The current const vector is `cvec = {1, 22}`; searching for 22 succeeds. The missing-22 message comes from the list search instead.

### Checked on 8 October 2026

The eight demo searches built and ran. Separate scratch tests passed 15 runtime checks: found/missing/empty/duplicate cases for vector/list/deque, const-vector success/failure, and writing through a mutable result. The iterator types were checked at compile time. Writing through a const result was rejected as expected. The header compiled by itself.

These checks used the pushed code unchanged. I still need to type the extra cases into my own demo if I want them saved with the exercise.

## 4. ex01 — Span

Based on [Span.hpp](../42modules/08/ex01/Span.hpp), [Span.cpp](../42modules/08/ex01/Span.cpp) and [main.cpp](../42modules/08/ex01/main.cpp), commit `79e6974`, checked on 13 October 2026. Earlier review findings concern older code.

The concepts are **initialization and ownership**, **constrained templates**, and **algorithms with safe arithmetic**. A span is a gap between stored numbers.

### Checkpoint 1 — Explain how an empty, bounded object is constructed

Start with the two private members:

| Name or expression | What it represents |
| --- | --- |
| `_collection` | The object's `vector<int>` of numbers |
| `_collection.size()` | How many numbers are stored now |
| `_capacity` | The maximum count this Span allows |
| `_collection.capacity()` | Allocated space, measured in elements; vector can grow beyond it |
| `maxSize` | A constructor parameter supplying the initial limit |

The rule to preserve is `_collection.size() <= _capacity`. Vector does not enforce this custom limit; my insertion methods do.

```cpp
Span::Span() : _capacity(0) {}

Span::Span(unsigned int maxSize) : _capacity(maxSize) {
    _collection.reserve(_capacity);
}
```

Both constructors initialize `_capacity`. The colon starts the **member initializer list**, before the body inside `{ }`. For `Span object(5);`: argument 5 → parameter `maxSize` → member `_capacity`. The member retains the limit after construction.

The omitted `_collection` still runs vector's default constructor and becomes empty. Explicitly writing `_collection()` would do the same. The integer member has no constructor supplying a useful default value, so I initialize `_capacity` myself.

Construction follows **declaration order in the header**: `_collection`, then `_capacity`, then the body. Both members exist before `reserve` runs.

`reserve(5)` prepares storage but leaves size zero; `resize(5)` creates five elements. This Span must start empty. Reserving may allocate and move existing elements, so it is not generally O(1).

The header declares the constructor; the .cpp defines its initialization and body. `explicit` allows `Span object(5);` and rejects implicit conversion through `Span object = 5;`. The default constructor takes no input to convert.

**OCF and `= default`:** the compiler supplies copying, assignment and destruction. Copies get independent vector storage and the same limit. Assignment replaces existing state and returns `Span&`; destruction lets vector release storage. Together with the default constructor, these cover Orthodox Canonical Form.

**Checkpoint question:** Immediately after `Span object(5);`, what are the limit and stored count, and what happened before the constructor body started?

### Checkpoint 2 — Trace insertion and separate type checks from size checks

`AddNumber(int value)` checks `size() >= _capacity`, throws `overflow_error` if full, otherwise appends using `push_back(value)`. The default, zero-capacity Span rejects its first number.

The range version is defined in the header:

```cpp
template <std::forward_iterator Iter>
requires std::same_as<std::iter_value_t<Iter>, int>
void AddRange(Iter first, Iter last) {
    const auto amountToAdd = std::distance(first, last);
    if (amountToAdd < 0)
        throw std::invalid_argument("Range is reversed");
    const std::size_t spaceLeft = _capacity - _collection.size();
    if (static_cast<std::size_t>(amountToAdd) > spaceLeft)
        throw std::overflow_error("Range does not fit");
    _collection.insert(_collection.end(), first, last);
}
```

**Read its declaration from the inside out:**

| Part | Meaning and reason |
| --- | --- |
| `template <std::forward_iterator Iter>` | `Iter` is a placeholder **type**. The forward_iterator concept requires an iterator supporting repeated passes. |
| `std::iter_value_t<Iter>` | Obtain the iterator's element type. The `_t` suffix names a type helper. |
| `std::same_as<std::iter_value_t<Iter>, int>` | Require element type int. Inner `<Iter>` feeds the helper; outer brackets hold the two compared types. |
| `requires` | Accept this function version only when the requirement holds. |
| `void AddRange(Iter first, Iter last)` | Return nothing; receive two iterator objects by value, of the same deduced type. |

For `object.AddRange(values.begin(), values.end())` with `vector<int>`:

```text
Iter = vector<int>::iterator
    -> iter_value_t<Iter> = int
    -> same_as<int, int> is satisfied
```

A list supplies another iterator type with int elements. Const-vector iterators still access int, so they work too. `vector<double>` is rejected at compilation, before any call or exception. This `same_as` rule replaces the earlier `convertible_to` conversion policy.

Span is an ordinary class; **AddRange is a member function template**. Its header definition lets the compiler form versions for callers' iterator types. Concepts and `requires` need C++20 in compiler and editor settings.

std::forward_iterator is a concept - rule about type to support;
repeated trasversal, reading and moving foreward: list, vector, set;
count elements with std::distance;
traverse again to insert elements;

std::iter_value_t<Iter>
get the type of the element iterator is accessing
std::same_as<type, int>
    must be an int;
**Read its body in execution order:**

| Statement | What happens and why |
| --- | --- |
| `amountToAdd = std::distance(first, last)` | Count elements. `auto` deduces a signed difference type; `const` fixes the local count. Forward iterators allow this counting pass, then a copying pass. |
| `if (amountToAdd < 0)` and throw | Reject a negative distance before unsigned conversion; detects a reversed vector range. |
| `spaceLeft = _capacity - _collection.size()` | Calculate remaining slots using unsigned count type `size_t`. The class rule prevents subtracting a larger count from a smaller limit. |
| `static_cast<std::size_t>(amountToAdd) > spaceLeft` and throw | Convert the nonnegative count to the size type; reject an oversized range before inserting. |
| `insert(_collection.end(), first, last)` | Append copies. Argument one is the destination; first/last delimit the source, excluding last. |

Supply a valid range from one container. Negative-count checking cannot validate unrelated positions; a reversed list range can already be invalid inside `distance`. An empty valid range adds nothing, even to a full Span.

**Headers:** `<iterator>` supplies iterator concepts, type helpers and distance; `<concepts>` supplies same_as; `<cstddef>` supplies size_t; `<vector>` supplies storage; `<stdexcept>` supplies the exceptions.

**Checkpoint question:** With limit 5 and two stored numbers, trace a source range containing three numbers. Which checks happen while compiling, and which happen when the call runs?

### Checkpoint 3 — Explain every step that turns stored numbers into gaps

The current shortest-span implementation is:

```cpp
long long Span::shortestSpan() const {
    if (_collection.size() <= 1)
        throw std::logic_error("Not enough values");
    std::vector<long long> sorted(_collection.begin(), _collection.end());
    std::sort(sorted.begin(), sorted.end());
    std::vector<long long> differences(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
    auto smallest = std::min_element(differences.begin() + 1, differences.end());
    return *smallest;
}
```

| Line | Syntax, behavior and implementation choice |
| --- | --- |
| Function declaration | `long long` is the return type; `Span::` identifies the class; `()` means no arguments. Trailing `const` prevents changing the object's ordinary members through this method. |
| Count check and throw | A gap needs two values. `logic_error` rejects zero/one and guarantees the later search has a gap to inspect. |
| Construct `sorted` from two iterators | The **range constructor** copies each int into a long long element. The temporary copy preserves original order; widening inputs makes later subtraction safe on this platform. |
| `std::sort(...)` | Sort the copy ascending. Vector supports the required random-access iterators; closest values become neighbors. |
| Construct `differences` from a count | The **count constructor** creates sorted.size() elements, initially zero. The next algorithm needs existing output elements; reserve alone would not create them. |
| `std::adjacent_difference(...)` | Read sorted inputs, write from differences.begin(). Output one copies input one; later outputs are current input minus previous input. |
| `std::min_element(begin() + 1, end())` | Skip the first output, which is not a gap. `+ 1` advances one vector position. `auto smallest` holds the returned iterator, not the number. |
| `return *smallest;` | Read the number at that valid position and return it by value. Temporary vectors are destroyed; the returned number survives independently. |

The trailing `const` applies to the Span object; the local temporary vectors can still be changed and sorted.

One complete trace:

```text
stored:       [6, 3, 17, 9, 11]   unchanged
sorted copy:  [3, 6, 9, 11, 17]
differences:  [3, 3, 3,  2,  6]
               ^ skip this first output
minimum gap:  2
```

A non-neighbor gap is the sum of neighboring nonnegative gaps, so it cannot beat all its component gaps. Duplicate neighbors give zero.

**Widen before subtraction:** largest int minus smallest int is `4294967295` here, exceeding signed int. A wide return type cannot repair earlier overflow. Both inputs and outputs are long long. The range constructor also handles copying between the different vector types.

The longest span uses:

```cpp
auto minmax = std::minmax_element(_collection.begin(), _collection.end());
return static_cast<long long>(*minmax.second)
     - static_cast<long long>(*minmax.first);
```

After the same two-value guard, `minmax_element` returns two iterators in a pair: `first` for minimum, `second` for maximum. `*` reads values; `static_cast<long long>` converts each before subtraction. Above: `17 - 3 = 14`.

`<algorithm>` provides sorting and minimum/maximum searches; `<numeric>` provides adjacent_difference. For n stored values, longest takes O(n); shortest takes O(n log n) and O(n) extra space. A loop tracking the minimum could avoid the second vector; this version practices combining algorithms.

**Checkpoint question:** Explain why `sorted` uses two iterators in its constructor, `differences` uses a count, and the minimum search starts one position after begin.
    sorted receives two iterators because it needs existing input values. differences receives a count because it needs output elements ready for writing. The minimum search skips the first output because adjacent_difference copies the initial input there; the actual gaps begin at the second element.

### What the current demo verifies

`checkSpans` compares expected answers; `checkTooFewValues` checks exceptions. Local catches handle expected rejections; unexpected failures reach the outer catch and return status 1.

| Saved case in main.cpp | Expected behavior |
| --- | --- |
| Five-number example; mixed vector/list/set sources | Gaps 2/14 and 1/54 |
| Duplicates; negative values; integer extremes | Gaps 0/0, 5/12 and 4294967295/4294967295 on this platform |
| Empty or one-value Span | Both queries throw |
| Zero capacity; full object; oversized range | Insertion throws; oversized range adds no values |
| Empty range into a full object | Adds nothing; answers stay the same |
| Copy and assignment, then change each object | Independent results and copied limits |
| Numbers 0 through 9999, filled using `std::iota` | Shortest 1; longest 9999 |

Checked on 13 October 2026: `make re` and `./span` passed with address/undefined-behavior sanitizers. Separate compiler checks accepted const-vector/list iterators, rejected double/stream iterators, and verified explicit construction. Exercise sources stayed unchanged.

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
- [x] Make Span constructors, signatures, demo calls, and build sources agree.
- [x] Check single-number and range insertion limits with valid test inputs.
- [x] Implement safe gap arithmetic and verify the fixed expected results.
- [x] Test 10,000 stored values with known answers.
- [ ] Answer the three Span checkpoint questions in my own words.
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
