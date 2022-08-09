# LeetCode ![](https://img.shields.io/badge/status-updating-brightgreen) [![wakatime](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4.svg)](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4) ![](https://visitor-badge.glitch.me/badge?page_id=kx-Huang.LeetCode&left_color=gray&right_color=blue) <!-- omit in toc -->

Personal solutions and notes for LeetCode problems in `C++`. More problems and notes will be updated.

## Table of Content <!-- omit in toc -->

- [0. Acknowledgement](#0-acknowledgement)
- [1. Data Structure](#1-data-structure)
  - [1.1 Graph](#11-graph)
  - [1.2 Hash Table](#12-hash-table)
  - [1.3 Heap](#13-heap)
    - [1.3.1 Binary Heap](#131-binary-heap)
    - [1.3.2 Binomial Heap](#132-binomial-heap)
    - [1.3.3 Fibonacci Heap](#133-fibonacci-heap)
  - [1.4 Linked List](#14-linked-list)
  - [1.5 Queue](#15-queue)
  - [1.6 Stack](#16-stack)
  - [1.7 String](#17-string)
  - [1.8 Tree](#18-tree)
    - [1.8.1 AVL Tree](#181-avl-tree)
    - [1.8.2 B Tree](#182-b-tree)
    - [1.8.3 B+ Tree](#183-b-tree)
    - [1.8.4 Binary Search Tree (BST)](#184-binary-search-tree-bst)
    - [1.8.5 K-D Tree](#185-k-d-tree)
    - [1.8.6 Red-black Tree](#186-red-black-tree)
    - [1.8.7 Trie](#187-trie)
- [2. Methodology](#2-methodology)
  - [2.1 Backtracking](#21-backtracking)
  - [2.2 Divide and Conquer](#22-divide-and-conquer)
  - [2.3 Dynamic Programming](#23-dynamic-programming)
  - [2.4 Prefix Sum](#24-prefix-sum)
  - [2.5 Reservoir Sampling](#25-reservoir-sampling)
  - [2.6 Search](#26-search)
    - [2.6.1 Binary Search](#261-binary-search)
    - [2.6.2 Breadth First Search (BFS)](#262-breadth-first-search-bfs)
    - [2.6.3 Depth First Search (DFS)](#263-depth-first-search-dfs)
  - [2.7 Slow & Fast Pointers](#27-slow--fast-pointers)
  - [2.8 Sorting](#28-sorting)
  - [2.9 Two Pointers](#29-two-pointers)

## 0. Acknowledgement

- Special thanks to [**Ruida Huang**](https://www.linkedin.com/in/ruida-huang-a777a7220/) and student organization **Sparks US** [@University of Michigan-Ann Arbor](https://umich.edu) that provides the initial category of LeetCode problems for me to start with
- `LeetCode VSCode Extension` is used for quick problem preview and code submission, please check [`config.md`](https://github.com/kx-Huang/LeetCode/blob/master/config.md) for detailed instructions
- Great thanks to all resouce contributors of related resouces

## 1. Data Structure

### 1.1 Graph

---

### 1.2 Hash Table

- Time Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(1)    | O(n)  |
  | Search | O(1)    | O(n)  |
  | Insert | O(1)    | O(n)  |
  | Delete | O(1)    | O(n)  |
  | Rehash | O(n)    | O(n)  |

  *Note: Rehashing cost is amortized to O(1) over individual inserts*

- Template in C++
  - [`std::unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)
  - [`std::unordered_set`](https://en.cppreference.com/w/cpp/container/unordered_set)

- LeetCode Problem

  |     | Title                        | Difficulty | Time | Space |
  | --- | ---------------------------- | ---------- | ---- | ----- |
  | 1   | Two sum                      | Easy       | O(n) | O(n)  |
  | 128 | Longest Consecutive Sequence | Medium     | O(n) | O(n)  |
  | 217 | Contains Duplicate           | Easy       | O(n) | O(n)  |
  | 349 | Intersection of Two Arrays   | Easy       | O(n) | O(n)  |
  | 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |
  | 819 | Most Common Word             | Easy       | O(n) | O(n)  |

---

### 1.3 Heap

#### 1.3.1 Binary Heap

- Time Complexity

  |        | Average  | Worst    |
  | ------ | -------- | -------- |
  | Create | O(n)     | O(n)     |
  | Push   | O(logn)  | O(logn)  |
  | Pop    | O(logn)  | O(logn)  |
  | Sort   | O(nlogn) | O(nlogn) |

- Procedure

  |        | Step  | Procedure                                                                                                     |
  | ------ | :---: | ------------------------------------------------------------------------------------------------------------- |
  | Create |   1   | Put all the items into a complete binary tree.                                                                |
  |        |   2   | Starting at the rightmost array position that has a child, *percolate down* all nodes in reverse level-order. |
  | Push   |   1   | Insert new item as the rightmost leaf of the tree.                                                            |
  |        |   2   | *Percolate up* newItem to an appropriate spot in the heap to restore the heap property.                       |
  | Pop    |   1   | Save the root to be returned.                                                                                 |
  |        |   2   | Move the item in the rightmost leaf of the tree to the root.                                                  |
  |        |   3   | *Percolate down* the recently moved item at the root to its proper place to restore heap property.            |
  | Sort   |   1   | Initialize a min heap with all the elements to be sorted.                                                     |
  |        |   2   | Repeatedly call *pop* to extract elements out of the heap.                                                    |

- Template in C++: [`std::priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue)

- LeetCode Problem

  |     | Title                | Difficulty | Time     | Space |
  | --- | -------------------- | ---------- | -------- | ----- |
  | 23  | Merge k Sorted Lists | Hard       | O(nlogk) | O(k)  |
  | 313 | Super Ugly Number    | Medium     | O(nlogk) | O(n)  |

#### 1.3.2 Binomial Heap

---

#### 1.3.3 Fibonacci Heap

---

### 1.4 Linked List

- Time Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(n)    | O(n)  |
  | Search | O(n)    | O(n)  |
  | Insert | O(1)    | O(1)  |
  | Delete | O(1)    | O(1)  |

- Related Methodology [2.7 Slow & Fast Pointers](#27-slow--fast-pointers)

- LeetCode Problem

  |     | Title                                     | Difficulty | Time     | Space   |
  | --- | ----------------------------------------- | ---------- | -------- | ------- |
  | 23  | Merge k Sorted Lists                      | Hard       | O(nlogk) | O(k)    |
  | 24  | Swap Nodes in Pairs                       | Medium     | O(n)     | O(1)    |
  | 25  | Reverse Nodes in k-Group                  | Hard       | O(n)     | O(1)    |
  | 86  | Partition List                            | Medium     | O(n)     | O(1)    |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)     | O(logn) |
  | 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)     | O(1)    |
  | 142 | Linked List Cycle II                      | Medium     | O(n)     | O(1)    |
  | 148 | Sort List                                 | Medium     | O(nlogn) | O(logn) |
  | 160 | Intersection of Two Linked Lists          | Easy       | O(m+n)   | O(1)    |
  | 234 | Palindrome Linked List                    | Easy       | O(n)     | O(1)    |
  | 328 | Odd Even Linked List                      | Medium     | O(n)     | O(1)    |
  | 382 | Linked List Random Node                   | Medium     | O(n)     | O(1)    |

---

### 1.5 Queue

---

### 1.6 Stack

---

### 1.7 String

- Template in C++: [`std::basic_istringstream`](https://en.cppreference.com/w/cpp/io/basic_istringstream)

- Useful Function in C++

  | Function                                                                              | Header      |
  | ------------------------------------------------------------------------------------- | ----------- |
  | [`std::isalpha`](https://en.cppreference.com/w/cpp/string/byte/isalpha)               | `<cctype>`  |
  | [`std::isupper`](https://en.cppreference.com/w/cpp/string/byte/isupper)               | `<cctype>`  |
  | [`std::islower`](https://en.cppreference.com/w/cpp/string/byte/islower)               | `<cctype>`  |
  | [`tolower`](https://en.cppreference.com/w/c/string/byte/tolower)                      | `<ctype.h>` |
  | [`toupper`](https://en.cppreference.com/w/c/string/byte/toupper)                      | `<ctype.h>` |
  | [`std::string::substr`](https://en.cppreference.com/w/cpp/string/basic_string/substr) | `<string>`  |

- Related Methodology: [2.9 Two Pointers](#29-two-pointers)

- LeetCode Problem

  |     | Title                                          | Difficulty | Time   | Space  |
  | --- | ---------------------------------------------- | ---------- | ------ | ------ |
  | 3   | Longest Substring Without Repeating Characters | Medium     | O(n)   | O(n)   |
  | 5   | Longest Palindromic Substring                  | Medium     | O(n^2) | O(n^2) |
  | 28  | Implement strStr()                             | Easy       | O(m+n) | O(m)   |
  | 819 | Most Common Word                               | Easy       | O(n)   | O(n)   |
  | 917 | Reverse Only Letters                           | Easy       | O(n)   | O(1)   |

---

### 1.8 Tree

- Related Methodology
  - [2.2 Divide and Conquer](#22-divide-and-conquer)
  - [2.6 Search](#26-search)

- LeetCode Problem

  |     | Title                                     | Difficulty | Time | Space   |
  | --- | ----------------------------------------- | ---------- | ---- | ------- |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n) | O(logn) |
  | 114 | Flatten Binary Tree to Linked List        | Medium     | O(n) | O(1)    |

---

#### 1.8.1 AVL Tree

---

#### 1.8.2 B Tree

---

#### 1.8.3 B+ Tree

---

#### 1.8.4 Binary Search Tree (BST)

- LeetCode Problem

  |     | Title                                     | Difficulty | Time | Space   |
  | --- | ----------------------------------------- | ---------- | ---- | ------- |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n) | O(logn) |


---

#### 1.8.5 K-D Tree

---

#### 1.8.6 Red-black Tree

---

#### 1.8.7 Trie

---

## 2. Methodology

### 2.1 Backtracking

|     | Title           | Difficulty | Time     | Space    |
| --- | --------------- | ---------- | -------- | -------- |
| 46  | Permutations    | Medium     | O(n*n!)  | O(n*n!)  |
| 47  | Permutations II | Medium     | O(n*n!)  | O(n*n!)  |
| 78  | Subsets         | Medium     | O(n*2^n) | O(n*2^n) |

---

### 2.2 Divide and Conquer

|     | Title                                     | Difficulty | Time      | Space   |
| --- | ----------------------------------------- | ---------- | --------- | ------- |
| 23  | Merge k Sorted Lists                      | Medium     | O(nklogk) | O(logk) |
| 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)      | O(logn) |
| 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)      | O(n)    |
| 148 | Sort List                                 | Medium     | O(nlogn)  | O(logn) |

---

### 2.3 Dynamic Programming

|     | Title                         | Difficulty | Time     | Space  |
| --- | ----------------------------- | ---------- | -------- | ------ |
| 5   | Longest Palindromic Substring | Medium     | O(n^2)   | O(n^2) |
| 28  | Implement strStr()            | Easy       | O(m+n)   | O(m)   |
| 313 | Super Ugly Number             | Medium     | O(nlogk) | O(n)   |
| 322 | Coin Change                   | Medium     | O(m*n)   | O(m)   |

---

### 2.4 Prefix Sum

|     | Title                        | Difficulty | Time | Space |
| --- | ---------------------------- | ---------- | ---- | ----- |
| 238 | Product of Array Except Self | Medium     | O(n) | O(n)  |
| 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |

---

### 2.5 Reservoir Sampling

- Goal: Select $k$ entries from $n$ options $\{X_1, X_2,...,X_n\}$. For any $n\ge k$, each entry is selected with same probability $P(X_i)=\frac{k}{n}$.

- Procedure
  - Choose $\{X_1, X_2,..., X_k\}$ first and put them into the reservoir
  - For $i\in [1,n-k]$, do:
    1. Pick $X_{k+i}$ with probability $P(X_{k+i})=\frac{k}{k+i}$
    2. If $X_{k+i}$ is picked, randomly replace an entry in the reservoir with same probability

  *Note: See [Section 3: Proof of Reservoir Sampling](https://github.com/kx-Huang/LeetCode/tree/master/Resources) in resources page for detailed proof*

- LeetCode Problem

  |     | Title                   | Difficulty | Time | Space |
  | --- | ----------------------- | ---------- | ---- | ----- |
  | 382 | Linked List Random Node | Medium     | O(n) | O(1)  |

---

### 2.6 Search

|     | Title                                     | Difficulty | Time    | Space   |
| --- | ----------------------------------------- | ---------- | ------- | ------- |
| 35  | Search Insert Position                    | Easy       | O(logn) | O(1)    |
| 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)    | O(logn) |
| 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)    | O(1)    |
| 704 | Binary Search                             | Easy       | O(logn) | O(1)    |

---

#### 2.6.1 Binary Search

- Complexity

  |           | Time    | Space   |
  | --------- | ------- | ------- |
  | Iterative | O(logn) | O(logn) |
  | Recursive | O(1)    | O(logn) |

- LeetCode Problem

  |     | Title                  | Difficulty | Time    | Space |
  | --- | ---------------------- | ---------- | ------- | ----- |
  | 35  | Search Insert Position | Easy       | O(logn) | O(1)  |
  | 704 | Binary Search          | Easy       | O(logn) | O(1)  |

---

#### 2.6.2 Breadth First Search (BFS)

---

#### 2.6.3 Depth First Search (DFS)

- Binary Tree

  |                                                                                | Time Complexity | Space Complexity |
  | ------------------------------------------------------------------------------ | --------------- | ---------------- |
  | Recursive traversal                                                            | O(n)            | O(n)             |
  | [Morris traversal](https://github.com/kx-Huang/LeetCode/tree/master/Resources) | O(n)            | O(1)             |

  *Note: See [Section 2: Morris Traversal](https://github.com/kx-Huang/LeetCode/tree/master/Resources) in resources page for more details*

- LeetCode Problem

  |     | Title                                     | Difficulty | Time | Space   |
  | --- | ----------------------------------------- | ---------- | ---- | ------- |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n) | O(logn) |
  | 114 | Flatten Binary Tree to Linked List        | Medium     | O(n) | O(1)    |

---

### 2.7 Slow & Fast Pointers

|     | Title                  | Difficulty | Time     | Space   |
| --- | ---------------------- | ---------- | -------- | ------- |
| 142 | Linked List Cycle II   | Medium     | O(n)     | O(1)    |
| 148 | Sort List              | Medium     | O(nlogn) | O(logn) |
| 234 | Palindrome Linked List | Easy       | O(n)     | O(1)    |

---

### 2.8 Sorting

|     | Title                | Difficulty | Time       | Space   |
| --- | -------------------- | ---------- | ---------- | ------- |
| 23  | Merge k Sorted Lists | Hard       | O(nk*logk) | O(logk) |
| 148 | Sort List            | Medium     | O(nlogn)   | O(logn) |

---

### 2.9 Two Pointers

- Related Algorithm
  - [Knuth–Morris–Pratt String-searching Algorithm (KMP)](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)
  - [Sliding Window](https://www.geeksforgeeks.org/window-sliding-technique/)

- LeetCode Problem

  |     | Title                                          | Difficulty | Time   | Space  |
  | --- | ---------------------------------------------- | ---------- | ------ | ------ |
  | 3   | Longest Substring Without Repeating Characters | Medium     | O(n)   | O(n)   |
  | 15  | 3Sum                                           | Medium     | O(n^2) | O(n^2) |
  | 16  | 3Sum Closest                                   | Medium     | O(n^2) | O(n^2) |
  | 28  | Implement strStr()                             | Easy       | O(m+n) | O(m)   |
  | 167 | Two Sum II - Input Array Is Sorted             | Medium     | O(n)   | O(1)   |
  | 475 | Heaters                                        | Medium     | O(m+n) | O(1)   |
  | 917 | Reverse Only Letters                           | Easy       | O(n)   | O(1)   |
  | 977 | Squares of a Sorted Array                      | Easy       | O(n)   | O(n)   |

---
