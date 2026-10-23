# C++ DSA Big to Adv

A collection of C++ programs covering the fundamentals of C++, data structures, algorithms, and object-oriented programming.

The source files are organized by topic, and each file uses a descriptive name based on the problem or concept demonstrated in the code.

## Topics

| Folder | Topics covered |
| --- | --- |
| `01. Basic` | Patterns, prime numbers, and number-system conversion |
| `02. Pointer` | Null pointers, pointers, and references |
| `03. Array` | Array operations, searching, sorting, subarrays, stock profit, and rainwater trapping |
| `04. 2D Array` | Matrix operations, spiral traversal, diagonal sums, and sorted-matrix search |
| `05. Character Array & String` | Character arrays, C strings, string operations, palindrome, and anagram checks |
| `06. Vector & DMA` | Dynamic memory allocation and vectors |
| `07. Bit Manupulation` | Bit checking, updating, clearing, counting, and fast exponentiation |
| `08. OOPS` | Classes, objects, constructors, inheritance, polymorphism, abstraction, and operator overloading |
| `09. Recursion` | Factorial, Fibonacci, powers, tiling, subsets, pairing, and recursive string problems |
| `10. Devide & Conquer` | Merge sort, quick sort, and searching in a rotated sorted array |
| `11. BackTracking` | Array changes, subsets, permutations, N-Queens, and grid paths |
| `12. LinkedList` | Singly and doubly linked lists, cycles, merge sort, and zigzag rearrangement |
| `13. Stack` | Stack implementations, string reversal, stock span, next greater element, parentheses, and histograms |
| `14. Queue` | Queues, circular queues, dequeues, queue/stack conversions, and queue problems |
| `15. Greedy Algorithm` | Activity selection, fractional knapsack, coin change, chain length, and job sequencing |
| `16. Binary Tree` | Traversals, tree properties, subtree checks, top view, levels, and lowest common ancestor |
| `17. Binary Search Tree` | BST traversal and key searching |

## Repository Structure

```text
CPP-big-adv/
├── 01. Basic/
├── 02. Pointer/
├── 03. Array/
├── 04. 2D Array/
├── 05. Character Array & String/
├── 06. Vector & DMA/
├── 07. Bit Manupulation/
├── 08. OOPS/
├── 09. Recursion/
├── 10. Devide & Conquer/
├── 11. BackTracking/
├── 12. LinkedList/
├── 13. Stack/
├── 14. Queue/
├── 15. Greedy Algorithm/
├── 16. Binary Tree/
├── 17. Binary Search Tree/
└── README.md
```

## File Naming

Source files use descriptive `snake_case` names instead of numbered filenames. For example:

```text
03. Array/linear_search.cpp
09. Recursion/factorial.cpp
13. Stack/next_greater_element.cpp
16. Binary Tree/lowest_common_ancestor.cpp
17. Binary Search Tree/search_in_bst.cpp
```

This makes it easier to identify the purpose of a program without opening the file.

## Requirements

- A C++ compiler with C++11 support or newer
- A terminal or an IDE such as Visual Studio Code

The programs use standard C++ headers and do not require external libraries.

## Compile and Run

From the repository root, compile any source file with:

```powershell
g++ "03. Array\linear_search.cpp" -o linear_search.exe
.\linear_search.exe
```

For a source file in another folder:

```powershell
g++ "17. Binary Search Tree\search_in_bst.cpp" -o search_in_bst.exe
.\search_in_bst.exe
```

On Linux or macOS, use `/` instead of `\` in paths:

```bash
g++ "03. Array/linear_search.cpp" -o linear_search
./linear_search
```

Some programs read values from standard input. Enter the requested values after starting the executable.

## Suggested Learning Order

The folders are arranged from foundational concepts to more advanced algorithms:

1. Basic C++ syntax and patterns
2. Pointers and arrays
3. Strings and dynamic memory
4. Object-oriented programming
5. Recursion and backtracking
6. Divide-and-conquer and greedy algorithms
7. Linked lists, stacks, and queues
8. Binary trees and binary search trees

## Notes

- Each `.cpp` file is a standalone practice program with its own `main()` function.
- The code is intended for learning and experimentation.
- Some examples demonstrate multiple approaches to the same problem, including different time complexities.
- Executable files generated during local compilation are not part of the source code.
