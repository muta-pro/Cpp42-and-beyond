# MutantStack: reading the focused tests

This [main.cpp](main.cpp) follows the subject's example (printed pages 12–13), repeats its operations with a list, and adds a small copying check. Its purpose is to demonstrate the iterator interface you added while showing that normal stack behavior remains available.

There is no separate testing framework. The program prints results you can inspect, compares sequences automatically, and throws an exception if a comparison fails. The numbered comments in main match the sections below. The header's const overloads remain available; the earlier string, sum, search and self-assignment demonstrations have been removed from this focused main.

## How the template connects to main

The header defines a class pattern:

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
```

In main, `MutantStack<int> mstack;` chooses int for T and default-constructs an object named mstack. Using the pattern with a concrete type is called **template instantiation**. The resulting type inherits from std::stack<int>, whose default backing container is std::deque<int>.

```text
MutantStack<T>             class template in the header
      |
      | main supplies T = int
      v
MutantStack<int>           concrete class type
      |
      | default construction
      v
mstack                    an actual object with its own backing container
```

When main calls `mstack.push(5)`, it uses the inherited stack operation. When it calls `mstack.begin()`, it uses our new method, which returns `this->c.begin()` from that same backing container. T is a type chosen during compilation; pushing a value adds an element to the object.

The declaration `MutantStack<int>::iterator it = mstack.begin();` follows the same relationship. `MutantStack<int>::iterator` is the iterator type alias inside this concrete class; `it` is a variable holding a position returned by this particular object's begin method. The alias creates no container and holds no position by itself.

The definitions are in the header so the compiler can see how to instantiate the template and check the operations main actually uses.

## 1. Run the subject's example

The first two pushes store 5 and 17. Top reads the newest value, so the first number printed is 17. Pop removes it; size then prints 1.

The next pushes leave the stack containing:

```text
begin -> [5] [3] [5] [737] [0] -> end
        bottom             top
```

The two iterator declarations save the starting and stopping positions. `++it` moves from 5 to 3; `--it` moves back to 5. Comparing it with a fresh begin position verifies that this round trip succeeded. Both movements are valid because the range contains several values and the decrement happens after the increment.

The while loop reads `*it`, prints the number, and increments the iterator until it equals ite. It never reads end and never pops a value. The numeric output beneath the MutantStack label must be:

```text
17
1
5
3
5
737
0
```

This section demonstrates inherited stack operations and the forward/backward iterator operations used by the subject.

## 2. Repeat the operations with a list

The list performs the same actions through its own interface: push_back corresponds to stack push, back to top, and pop_back to pop. Its output beneath the std::list label should contain the same seven numbers.

The final comparison uses:

```cpp
std::equal(mstack.begin(), mstack.end(),
           reference.begin(), reference.end())
```

The first two arguments describe the stack's values; the other two describe the list's values. This four-iterator overload checks that the ranges have equal lengths and corresponding elements. It does not compare iterator types or memory addresses.

The two printed blocks let you compare top, size and traversal visually. This algorithm additionally checks the final stored sequences automatically. If it returns false, `!` makes the if condition true and the program throws. The following success message is reached only when the comparison passes.

## 3. Check copying and assignment

These lines exercise two different special member functions:

```cpp
MutantStack<int> copied(mstack);
MutantStack<int> assigned;
assigned.push(-1);
assigned = mstack;
```

The first line creates a new object using the **copy constructor**. The second creates a different, empty object. After giving it an initial value, the last line invokes **copy assignment** on that existing object. Assignment must replace the -1 with the source sequence.

The initial equal comparisons verify that both objects contain the complete source sequence. The later pop on copied and top assignment on assigned check independence:

| Object | Final values | Size / top |
| --- | --- | --- |
| mstack | 5, 3, 5, 737, 0 | 5 / 0 |
| copied | 5, 3, 5, 737 | 4 / 737 |
| assigned | 5, 3, 5, 737, 99 | 5 / 99 |

`assigned.top() = 99;` works because mutable top returns a reference to the actual top element. The source must retain its original size and top. This is a small addition to the subject's example, supporting the general requirement for Orthodox Canonical Form.

## 4. Understand the final ordinary-stack copy

```cpp
std::stack<int> ordinary(mstack);
```

Read the declaration as **type — new object name — constructor argument**:

| Part | Meaning |
| --- | --- |
| std::stack<int> | Type of the new object |
| ordinary | Name of that object |
| mstack | Existing source passed to its constructor |

This calls std::stack<int>'s copy constructor. Because MutantStack<int> publicly inherits from std::stack<int>, the constructor can receive a reference to mstack's stack base part. It copies that base's stored values into ordinary's own container.

mstack stays a MutantStack<int>. ordinary is a separate std::stack<int>, exposing the ordinary stack interface. It has push/pop/top but no public begin/end methods: those were additions in the derived class.

The next line pops ordinary. Its size becomes 4 and its top becomes 737, while mstack remains size 5 with top 0. These comparisons demonstrate that copying the base state did not share the container.

The two copy-construction cases therefore differ in their destination types: `copied(mstack)` creates a MutantStack<int>, while `ordinary(mstack)` creates a std::stack<int>. Neither declaration is assignment; `assigned = mstack;` is the assignment expression.

## How the program finishes

Each failed if condition throws runtime_error. The outer catch receives it as `const std::exception&`, prints its message using what(), and returns 1. An exception stops the current path, so later sections do not run after a failure.

If all comparisons pass, execution reaches return 0. Objects created in main clean up automatically; each container owns its storage. The success messages indicate which section completed, rather than replacing its comparisons.

Run from the repository root:

```sh
cd 42modules/08/ex02
make
./mutantstack
```
