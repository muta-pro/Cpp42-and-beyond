# August learning journal — CPP08: containers, iterators, algorithms

## Module map

| Exercise | Main lesson | Current status |
| --- | --- | --- |
| ex00: easyfind | Function templates, generic search, iterator results, exceptions | Current demo builds and runs; const and edge-case coverage to add |
| ex01: Span | Container ownership, bounded insertion, member templates, efficient algorithms, numeric safety | Unfinished constructors and interface/build mismatches |
| ex02: MutantStack | Container adaptors, inheritance, dependent names, exposing iteration | Iteration and meaningful demo missing; assignment and flags need correction |

Prerequisites: CPP05 exceptions, CPP06 conversions, CPP07 templates. The goal is to connect those tools: **store values in a container, describe a valid range with iterators, choose an algorithm, preserve the type's invariants**.

## 1. The STL model

The standard library is broader than the STL: streams, strings, exceptions, and other facilities also belong to the standard library. STL usually refers to generic containers, iterators, algorithms, and associated function objects and allocators.

- **Container:** owns or organizes a collection of values.
- **Iterator:** a position with operations the algorithm can use.
- **Algorithm:** performs work on a range without depending on one concrete container.
- **Predicate or comparator:** behavior supplied to an algorithm.
- **Adaptor:** presents a restricted interface over another component; `std::stack` is a container adaptor.

Algorithms do not eliminate loops internally. They let me express a standard operation and reuse its tested implementation. I choose storage based on access patterns, then choose an algorithm compatible with its iterators.

| Container | Useful property | Important cost or constraint |
| --- | --- | --- |
| `vector<T>` | Contiguous storage, random indexing, fast iteration | Middle insertion/erase O(n); growth can invalidate positions |
| `deque<T>` | Random indexing, efficient insertion at either end | Not contiguous; iterator invalidation differs from vector |
| `list<T>` | Stable iterators to surviving nodes; insertion at a known position O(1) | No random indexing; finding the position is O(n) |
| `set<T>` | Unique ordered keys | Key lookup O(log n); elements cannot be changed through iterators |
| `map<K,V>` | Ordered key/value entries | Elements are pairs with const keys; use member lookup for keys |
| `stack<T>` | LIFO operations: push, top, pop | No public iterator interface; default backing container is deque |

`array<T,N>` and unordered containers are C++11 additions. `forward_list` is C++11 too. Do not mix these into a C++98 answer accidentally.

## 2. Ranges and iterator validity

Most classic algorithms take a half-open range **`[first, last)`**. It includes `first` and excludes `last`.

- `begin()` denotes the first element if one exists.
- `end()` is a past-the-end position and must never be dereferenced.
- Empty container: `begin() == end()`.
- Both iterators must describe a valid range; `last` must be reachable from `first` using operations permitted for the category.

An iterator is not necessarily a raw pointer or a smart pointer. It does not usually own the object. It becomes unusable when its referenced storage or element is invalidated.

### Categories tell me which operations are available

| Category | What it adds | Example |
| --- | --- | --- |
| Input | Read and advance, potentially single pass | `istream_iterator` |
| Output | Write and advance | `back_insert_iterator` |
| Forward | Multiple passes over the same range | `forward_list` iterator (C++11) |
| Bidirectional | Move backward too | `list` iterator |
| Random access | Jump by offsets, subtract compatible positions | `vector`, `deque` iterators |
| Contiguous (C++20 concept) | Consecutive positions map to consecutive storage | `vector<int>` iterator |

`std::find` works with input iterators. `std::sort` needs random-access iterators. Therefore a list uses `list.sort()`, not `std::sort(list.begin(), list.end())`.

`std::distance` is O(1) for random-access iterators and O(n) for typical other categories. Counting and then inserting traverses twice, so a simple precheck design should require forward iterators. An input iterator might consume its source on the first pass.

### Invalidation examples to memorize

- Vector growth that reallocates invalidates all its iterators, references, and pointers. Without reallocation, appending still invalidates the old `end()`.
- Vector erase invalidates positions at and after the erased element.
- List insertion preserves existing iterators; erasure invalidates those to erased elements.
- Deque insertion at either end invalidates iterators but preserves references to existing elements. Check the rules for other operations separately.
- Ordered associative insertion preserves existing iterators; erasure invalidates the erased ones.

A returned iterator is useful only while its original container and position remain valid.

## 3. ex00 — easyfind

### Contract before implementation

Input: a container of integer values and a target integer. Result: an iterator to the **first** matching value. Missing target: signal failure according to the chosen contract, currently an exception.

`std::find` compares elements to the target and returns `last` when no element matches. It does not throw merely because a value was absent; my wrapper adds that behavior.

The search is O(n). A sorted container does not automatically make `std::find` faster. For a set, member `find` uses its key-search structure and is O(log n).

### Dependent type names

In `typename T::iterator`, the type of `T::iterator` depends on the template argument. `typename` tells the parser to treat that dependent qualified name as a type.

Returning the iterator preserves access to the found position. Returning a copied integer would lose its position and connection to the container.

### Const correctness

A mutable container can expose a mutable iterator. A const container exposes a `const_iterator`, which prevents modifying elements through it. Add two overloads and make their return types agree with their parameters. A `const_iterator` can still advance; it is the pointed-to value that is read-only.

`const iterator` means the iterator object itself cannot move. It is different from `const_iterator`.

### Your checkpoint

Before typing, answer: when search fails, which iterator does `std::find` return, and why must I compare it before dereferencing?

Then type the const overload, include the exception header directly, and test:

| Case | Expected |
| --- | --- |
| vector/list/deque with a match | Correct found value |
| Empty container | Missing-value exception |
| Repeated target values | Iterator to first occurrence |
| Missing value | Exception, no dereference of end |
| Const vector | Search succeeds, result cannot write the element |

The existing demo already covers seven searches. Preserve those outcomes while adding the missing cases.

## 4. ex01 — Span

### Representation and invariants

Use an owning `vector<int>` for values and an unsigned capacity limit. The vector manages allocation and cleanup through RAII.

An **invariant** is a condition every usable object must preserve:

1. Stored count never exceeds the logical limit: `_num.size() <= _capacity`.
2. Copying preserves both the values and the limit.
3. Read-only queries leave the stored values and their order unchanged.
4. A rejected insertion leaves the object in the promised state.

`reserve(N)` requests storage capacity but creates no values: size stays zero. `resize(N)` creates N elements. Reserved memory is an optimization, not enforcement of the exercise limit; `push_back` can still grow unless I check the invariant.

### Construction, copying, assignment

A member initializer initializes an existing member: it is not a place to declare a variable. Members initialize in declaration order, regardless of the order written in the initializer list.

The vector already implements independent value copying and cleanup. I do not need to manually delete it. Modern application code can often use the **Rule of Zero**; an exercise requiring Orthodox Canonical Form may still ask me to write the special members.

Assignment returns `Span&` so assignment chaining behaves normally. `this` is a pointer; `&other` is the other object's address; `*this` is the current object. A self-assignment guard must compare addresses, not a pointer with an object.

### Guided checkpoint A: make state coherent

Type only the constructors and copy operations first.

1. Choose one capacity name and remove the duplicate constructor definition yourself.
2. Initialize the default state deliberately (a zero-capacity default is a reasonable choice if the subject allows it).
3. Copy both data members; return the current object from assignment.
4. Make the header and implementation signatures match.
5. Add `Span.cpp` to the Makefile's sources, and use one name consistently for range insertion.

Explain before continuing: why is copying a vector different from copying a raw owning pointer?

### Single-value insertion

Check whether size already equals the limit, throw if full, otherwise append the value. A full zero-capacity object must reject its first insertion. Check **before** changing state.

### Range insertion and member templates

A member template gives one operation its own template parameter. Span stays a concrete class storing `int`; its range member accepts iterators from different compatible sources.

The public range is `[first,last)`. A count-before-insert approach can reject oversized valid ranges before altering state. The definition normally belongs in the header because other translation units need to see it to instantiate it.

For your C++20 exploration:

- `std::forward_iterator<Iter>` expresses the multipass requirement.
- `std::convertible_to<std::iter_value_t<Iter>, int>` checks implicit convertibility.
- That conversion constraint does **not** prove a value fits in `int`: a large `double` is still convertible. For stricter numeric safety, require actual int values or validate each conversion under a documented policy.

For C++98, use a normal member-template parameter and document its iterator/value requirements; concepts and `requires` are unavailable.

`distance < 0` does not validate arbitrary iterators. Reversed random-access positions can have a negative distance; reversed list ranges or iterators from unrelated containers already violate the operation's preconditions. Do not execute invalid-range tests expecting an exception.

If a range comes from the same vector being modified, range insertion has aliasing hazards. Your private storage currently prevents ordinary callers obtaining those iterators; retain that design or stage a source copy if you later expose them.

### Guided checkpoint B: insertion

Test one value, exactly full, one beyond full, empty range, a fitting range, and a too-large **valid** range. After rejection, compare the stored state with its previous state. If you retain two-pass counting, explain why an input iterator is insufficient.

### Longest span

For at least two values, longest span is `maximum - minimum`. `std::minmax_element` (C++11) returns a pair of iterators; finding both takes O(n). C++98 can use separate `min_element` and `max_element` passes, still O(n).

Widen operands before subtracting. For the 32-bit `int` used here, the full span can exceed signed `int`; choose a suitable nonnegative result type and agree on it across the whole interface.

### Shortest span

Sort a **copy** of the values and scan adjacent pairs. Why adjacent? In sorted order, the distance between non-neighbors is a sum of consecutive nonnegative gaps, so it cannot be smaller than every gap it contains.

Sorting costs O(n log n), scanning O(n), and copying uses O(n) extra storage. Duplicate values give a gap of 0.

`std::sort` has a complexity guarantee; a particular internal sorting strategy is an implementation detail.

Your `adjacent_difference` approach skips its first output correctly: that output is the first input value, not a gap. But default subtraction still occurs in the input type. A widened output vector alone does not avoid signed overflow. For now, type an adjacent scan that widens both operands before subtraction; revisit numeric algorithms afterward.

### Guided checkpoint C: span results

| Stored values / operation | Expected |
| --- | --- |
| Empty or one value; either query | Exception |
| `6,3,17,9,11` | Shortest 2, longest 14 |
| `5,5` | Shortest 0, longest 0 |
| `-10,-3,2` | Shortest 5, longest 12 |
| `INT_MIN,INT_MAX` | Exact full span, no signed overflow |
| Query twice | Same results; original order unchanged |
| Copy then change one object | Other object's values unchanged |
| Exactly 10,000 deterministic values `0..9999` | Shortest 1, longest 9999 |

Start with fixed expected cases. A random stress run can follow, but it cannot replace them. Run with AddressSanitizer and UndefinedBehaviorSanitizer and inspect diagnostics, even when the exit code is zero.

## 5. ex02 — MutantStack

### What std::stack hides

`std::stack<T>` is an adaptor, usually over `deque<T>`. It exposes `push`, `pop`, `top`, `empty`, and `size`. `top()` accesses the newest value; `pop()` removes it and returns nothing. Check for emptiness before either operation.

The actual backing container is its protected member `c`, and the associated type is `container_type`. The exercise exposes iteration over that existing storage; it does not need a second container.

### Dependent base lookup

The base class depends on `T`. Use `this->c` to access the dependent base member. A typedef for an iterator must identify the dependent nested type with `typename`.

Expose mutable and const iterator types. Overload `begin()` and `end()` on the constness of the stack. Reverse iteration is a useful extension after basic iteration works.

Normal forward iteration follows the backing container from oldest/bottom to newest/top. Repeated `top()`/`pop()` visits the values in the opposite order and destroys them.

### Copying and inheritance boundaries

Delegate copying to `std::stack<T>`; its container already has value semantics. Explicit special members are useful practice if required, but no raw allocation is needed here.

Standard containers/adaptors are not intended as runtime-polymorphic bases. Do not delete a MutantStack through a `std::stack<T>*`; the base destructor is not virtual. For this exercise use ordinary values, copies, and references without owning base pointers. In a general application, composition is often a better design.

### Guided checkpoint D: implement iteration

1. Correct the sanitizer argument and pointer/object comparison yourself.
2. Type the iterator typedefs by following `stack → container_type → iterator`.
3. Add mutable `begin`/`end`, then their const overloads.
4. Write a nonempty demo that actually instantiates copy construction and assignment.

Test pushing `5,17`, reading top 17, popping, then reading top 5. Add `3,5,737,0`; forward iteration should now yield `5,3,5,737,0`. Modify an element through a mutable iterator, read through a const stack, copy to another stack, and show that later changes do not affect the copy. Compare the same forward sequence with a list. Never dereference `end()` or call `top()` on an empty stack.

## 6. Completion checklist for today's session

- [ ] Explain half-open ranges and iterator categories without looking at the notes.
- [ ] Explain size versus reserved capacity and state the Span invariant.
- [ ] Type easyfind const support and edge-case checks.
- [ ] Make Span's declarations, definitions, demo, and build sources agree.
- [ ] Implement safe copying and capacity-checked insertion.
- [ ] Get all fixed span cases and the 10,000-value test right.
- [ ] Implement and test mutable/const MutantStack iteration and copying.
- [ ] Build with the chosen language standard and inspect sanitizer diagnostics.
- [ ] Compare submission requirements with your assigned subject before calling it submission-ready.

These boxes remain unchecked until you implement and verify them. The first live step is small: explain the missing-value result of `std::find`, then type the const easyfind overload and send it for review.

## 7. Beyond this module

After these exercises, study **exception guarantees** (basic, strong, no-throw), **Rule of Zero**, **range views and borrowed lifetimes** (C++20), comparator **strict weak ordering**, and deterministic property tests. These concepts explain why an implementation can compile and still violate a lifetime, numeric, or API contract.

For CPP09, preview parsing and associative lookup, stack-based expression evaluation, and algorithms whose complexity must be analyzed. This repository currently has no CPP09 exercise directory, so that is a next topic rather than completed work.

Reference pages: [iterators](https://en.cppreference.com/w/cpp/iterator), [vector invalidation and capacity](https://en.cppreference.com/w/cpp/container/vector), [find](https://en.cppreference.com/w/cpp/algorithm/find), [stack](https://en.cppreference.com/w/cpp/container/stack), [adjacent_difference](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference).
