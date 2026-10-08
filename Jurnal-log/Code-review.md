# C++ learning review — 5 October 2026

This review records improvements for you to implement. No exercise source, header, test, or Makefile was edited. The learning notes were expanded separately.

## What was checked

All **36 exercise Makefiles** were run with `make -B -j2` in copies outside the checkout, using GCC 14.2.0 and GNU Make 4.4.1. **31 built and 5 failed.** Building is evidence of compile/link readiness, not proof that every behavior is correct.

| Module | Builds passed | Builds failed |
| --- | ---: | --- |
| 00 | 2 / 3 | ex00 |
| 01 | 7 / 8 | ex06 |
| 02 | 4 / 4 | — |
| 03 | 4 / 4 | — |
| 04 | 4 / 4 | — |
| 05 | 3 / 4 | ex01 |
| 06 | 3 / 3 | — |
| 07 | 3 / 3 | — |
| 08 | 1 / 3 | ex01, ex02 |

Runtime checks: Module 08/ex00 produced its expected seven search outcomes without sanitizer diagnostics. Earlier onboarding checks verified zombie lifecycle, integer/string template operations, and the object/pointer/reference example. A new Module 06 boundary input reproduced undefined behavior, described below. Other executables were not comprehensively runtime-tested.

Build logs and probe results for this session are under `/workspace/cpp42-review/`. These local outputs are separate from the Git repository.

No 42 subject PDF is present in the checkout. This review distinguishes your current C++17/20 exploration from a possible C++98 submission; verify the language and exact interfaces against your assigned subject before submission.

## Fix first: Module 08 completion

### 1. Span currently cannot compile or link

Locations: [Span.cpp](../42modules/08/ex01/Span.cpp), [Span.hpp](../42modules/08/ex01/Span.hpp), [main.cpp](../42modules/08/ex01/main.cpp), [Makefile](../42modules/08/ex01/Makefile).

- `Span.cpp:15–21`: the default constructor, copy constructor, and assignment operator are unfinished. A constructor initializer names an existing member, not a new declaration. Assignment must match the declared `Span&` return type, compare object addresses if you use a self-assignment guard, copy the values and capacity, and return `*this`.
- `Span.cpp:25,29`: two definitions have the same `Span(unsigned int)` signature; the second names `_maxSize`, which is not a member. Choose one member name and one constructor definition.
- `main.cpp:20,23,26,33`: the demo calls an iterator overload of `AddNumber`, but the header declares `AddRange`. Decide on one public interface and make all calls consistent. Include `<list>` and `<set>` where those types are used.
- `Makefile:4`: only `main.cpp` is compiled. Add `Span.cpp` to the source list when you type your fixes; otherwise method definitions will not be linked.

Evidence: the normal build fails in `main.cpp`. A separate compile of the unmodified `Span.cpp` also fails on its constructors. Fixing only the demo will expose further errors.

### 2. Span arithmetic must handle the full input domain

Locations: `Span.cpp:43–46,53` and `Span.hpp:33–34`.

Both span calculations subtract `int` values in `int`. For a usual 32-bit `int`, the distance from `INT_MIN` to `INT_MAX` is **4,294,967,295**, which cannot fit in an `int`. The subtraction can overflow before a later cast or return conversion helps.

Type your subtraction in a sufficiently wide type by converting the operands **before** subtracting. Choose a nonnegative result type supported by the subject, and keep declaration, definition, temporary arithmetic, and tests consistent. On this machine, `long long` can represent every difference between two `int` values; this is a C++11 type in standard C++. If using C++98, check the subject's required return type and use a supported arithmetic strategy rather than assuming `long` is always 64-bit.

`std::adjacent_difference` also subtracts using the input values' type by default. Merely making its output vector wider does not solve that. A direct adjacent scan with widened operands is a useful learning implementation.

Evidence: static review; runtime span checks are blocked by the incomplete implementation. Required later tests: duplicate values → shortest span 0; mixed signs; minimum/maximum `int`; fewer than two values → exception.

### 3. MutantStack has both a build flag error and an untested template error

Locations: [Makefile](../42modules/08/ex02/Makefile):2, [MutantStack.hpp](../42modules/08/ex02/MutantStack.hpp):24, [main.cpp](../42modules/08/ex02/main.cpp).

- The space in `-fsanitize=undefined, address` splits it into separate shell arguments. Type the sanitizer list as one argument, for example `-fsanitize=address,undefined`.
- `this != assign` compares a pointer with an object. If keeping a guard, compare `this` with the address of `assign`.
- There are no iterator typedefs or `begin`/`end` members yet. Expose the underlying protected container through mutable and const iteration.
- The empty `main()` does not instantiate assignment or check stack behavior. A separate assignment probe confirmed the template error. Test the actual operations, not just header inclusion.
- Rename the executable from `find` to a name that describes this exercise when appropriate.

Implement in stages using the [August guide](Journal-August.md). Copying, assigning, modifying through iterators, reading a const stack, and preserving `top`/`pop` behavior are separate checks.

### 4. easyfind works for the current demo; strengthen its contract

Location: [easyfind.hpp](../42modules/08/ex00/easyfind.hpp):16–23.

The current seven searches work. Next improvements: directly include the header for the exception type you use; add a const-container overload; provide a useful missing-value message; test empty containers and duplicate values. Explain why the return value is an iterator into the original container and why a caller must respect invalidation after later mutations.

These are improvements rather than observed failures in the existing demo. Do not assume an integer `std::find` automatically applies to `std::map` elements, which are key/value pairs.

## Fix next: correctness issues outside Module 08

### 5. ScalarConverter performs an out-of-range cast even after rejecting it

Location: [ScalarConverter.cpp](../42modules/06/ex00/ScalarConverter.cpp):84,145.

Reproduced command: `/workspace/cpp42-review/06/ex00/convert 1000000000000.0`.

The program prints `int: impossible`, then its formatting condition casts the same value to `int`. UndefinedBehaviorSanitizer reports that `1e+12` is outside the representable `int` range. The process returns 0 because the sanitizer recovers; a successful exit alone does not mean this test passed.

Separate formatting from integer conversion. Check finiteness and representability before every conversion, and use a floating-point operation such as `std::modf` to ask whether a value has a fractional part. Check conditions before the dangerous expression: `&&` evaluates left to right. Add boundary cases near both integer limits and large finite float/double values. Review `<cctype>` calls too: convert character inputs to `unsigned char` before classification.

### 6. Array is not exception-safe for arbitrary element types

Location: [Array.hpp](../42modules/07/ex02/Array.hpp):24–34.

Assignment deletes the old allocation before allocating the replacement. If `new` throws, `_elements` still points at freed storage; later destruction can double-delete it. In the copy constructor, if assigning a later element throws, the raw allocated array leaks because the enclosing object's destructor will not run.

Learn the allocate/copy/commit pattern. Construct replacement storage under an owner that cleans up on failure, and replace the old state only after copying succeeds. A C++98 exercise can implement cleanup with carefully scoped `try`/`catch`; modern code can use RAII helpers or a standard container. Copy-and-swap helps assignment only after the copy constructor itself is safe.

Evidence: static review. An `Array<int>` demo cannot expose throwing-element behavior. Later test with an element type that deliberately throws while being copied, as well as independent-copy and self-assignment cases.

### 7. MateriaSource self-assignment leaks its owned prototypes

Location: [MateriaSource.cpp](../42modules/04/ex03/MateriaSource.cpp):33–40.

Only `_clearTempl()` is controlled by the `if`. The clone loop runs even for `source = source`, replacing owned pointers without freeing the originals. Enclose the whole replacement operation in the guard or return early on self-assignment. Then consider staging clones before replacing existing ownership to handle allocation failure.

Related review: `Character::equip` accepts the same owning pointer more than once, which can lead to double deletion. Define and test ownership: one equipped object has one owner; rejected equipment stays with its caller; unequipped equipment must remain reachable for later deletion. Clone loops in both copy constructors also need cleanup if a later clone throws.

Evidence: static review of [Character.cpp](../42modules/04/ex03/Character.cpp):21–28,61–73 and `MateriaSource.cpp:21–28,33–40`; these failure paths were not runtime-tested.

### 8. Fixed-point arithmetic needs a documented numeric contract

Location: [Fixed.cpp](../42modules/02/ex02/Fixed.cpp):21,27,95,101,107,112.

Division has no zero check; addition/subtraction can overflow; conversion from a very large float can exceed `int`; signed shifts of negative values are unsafe under the exercises' C++98 rules. Widening to `long` helps only on platforms where it is sufficiently wide, and narrowing the result can still lose information.

Decide how to handle zero division, out-of-range input, overflow, and negative rounding. Check before performing the operation, and test those choices. Do not rely on sanitizer output to define the behavior for you.

Evidence: static review of the selected implementation; equivalent patterns recur in ex01/ex03. No exhaustive numeric suite was run.

## Other confirmed build failures

| Exercise | Cause | Your next change |
| --- | --- | --- |
| 00/ex00 | Multiple `main` definitions, a modern range loop under C++98, and executable example code at file scope | Keep one program entry point; move alternative examples into notes or separate exercises |
| 01/ex06 | Intentional switch fallthrough is rejected by `-Werror`; severity order is DEBUG, WARNING, INFO, ERROR | Document fallthrough using a compiler-recognized C++98 comment, or `[[fallthrough]]` for C++17; put INFO before WARNING for the usual severity contract |
| 05/ex01 | Header declares `bool beSigned(...) noexcept` with `[[nodiscard]]`, while the implementation defines a throwing `void` function; the caller ignores the declared result | Choose one error contract and align declaration, definition, and caller; a throwing signing operation cannot promise `noexcept` |

## Habits to develop across modules

1. **Pick the language version deliberately.** Concepts are C++20; `auto` type deduction, move semantics, `= default`, and `override` are C++11; `[[nodiscard]]` is C++17. These are valid learning extensions, but not C++98 features.
2. **Make headers self-contained.** Include `<utility>` for `std::move` in `whatever.hpp`, and the appropriate exception header in `easyfind.hpp`. Indirect includes are not a portable contract.
3. **Test template members by calling them.** Header inclusion or an empty executable can miss dependent errors until instantiation.
4. **Turn demos into observable checks.** Print expected versus actual or use assertions; include empty input, duplicates, bounds, copy independence, const use, and exception paths. A random 10,000-value demo is useful for scale but does not replace fixed expected values.
5. **Keep generated artifacts out of version control later.** `01/ex02/main.o` and `08/ex01/main.d` are tracked. When you do housekeeping, add appropriate ignore rules and remove generated artifacts from tracking. A stale object can hide a broken source file.
6. **Fix errors before style.** Consistent names, formatting, and English spelling help, but preventing undefined behavior and defining ownership are the first priorities.

## Today's guided order

Work through the [August journal](Journal-August.md), one checkpoint at a time: easyfind const behavior → Span state and copying → single/range insertion → span arithmetic → MutantStack iteration → boundary and scale checks. Send your first typed change for review before moving on if you want feedback at each step.

The theory notes are prepared. Module 08's code is **not complete yet**; completion depends on you typing and validating the remaining implementations.

## easyfind follow-up — 8 October 2026

GitHub commit `688ff15` fixes the const overload's local iterator type and directly includes `<exception>`. The header structure is correct: include guard, required library includes, then the two template definitions. Its commented vector example is harmless.

The current demo builds and runs all seven searches. Separate scratch tests passed 15 runtime checks for vector/list/deque match, empty, duplicate, and missing cases, const-vector success/failure, and mutable writes. Compile-time checks confirmed the return types, and a write through the const result was rejected as expected. A source including only easyfind.hpp also compiled.

No exercise source or test file was edited for this follow-up. The added checks are outside the checkout, so the repository's demo still needs empty, duplicate, and successful const-search cases if you want those checks saved with your exercise. The August journal and relevant basics sections now explain the terminology and test inputs in simpler language. The earlier all-exercise build counts above remain the dated 5 October review; the full suite was not rerun for this focused check.
