# LeetCode ![](https://img.shields.io/github/directory-file-count/kx-huang/leetcode/Algorithms?color=orange&label=solved) ![](https://img.shields.io/github/last-commit/kx-huang/leetcode) [![wakatime](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4.svg)](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4) ![](https://visitor-badge.glitch.me/badge?page_id=kx-Huang.LeetCode&left_color=gray&right_color=blue) <!-- omit in toc -->

Personal solutions and notes for LeetCode problems in `C++`. More problems will be updated.

## Table of Content <!-- omit in toc -->

- [0. Acknowledgement](#0-acknowledgement)
- [1. Data Structure](#1-data-structure)
  - [1.1 Graph](#11-graph)
  - [1.2 Hash Table](#12-hash-table)
  - [1.3 Heap](#13-heap)
    - [1.3.1 Binary Heap](#131-binary-heap)
  - [1.4 Linked List](#14-linked-list)
  - [1.5 Queue](#15-queue)
  - [1.6 Stack](#16-stack)
  - [1.7 String](#17-string)
  - [1.8 Binary Tree](#18-binary-tree)
    - [1.8.1 AVL Tree](#181-avl-tree)
    - [1.8.2 Binary Search Tree (BST)](#182-binary-search-tree-bst)
    - [1.8.3 K-D Tree](#183-k-d-tree)
    - [1.8.4 Red-black Tree](#184-red-black-tree)
  - [1.9 Union-Find Disjoint Set (UFDS)](#19-union-find-disjoint-set-ufds)
- [2. Methodology](#2-methodology)
  - [2.1 Backtracking](#21-backtracking)
  - [2.2 Divide and Conquer](#22-divide-and-conquer)
  - [2.3 Dynamic Programming](#23-dynamic-programming)
  - [2.4 Greedy](#24-greedy)
  - [2.5 Mathematical Optimization](#25-mathematical-optimization)
    - [2.5.1 Bit Manipulation](#251-bit-manipulation)
    - [2.5.2 Boyer–Moore Majority Vote Algorithm](#252-boyermoore-majority-vote-algorithm)
    - [2.5.3 Reservoir Sampling](#253-reservoir-sampling)
  - [2.6 Prefix Sum](#26-prefix-sum)
  - [2.7 Search](#27-search)
    - [2.7.1 Binary Search](#271-binary-search)
    - [2.7.2 Breadth First Search (BFS)](#272-breadth-first-search-bfs)
    - [2.7.3 Depth First Search (DFS)](#273-depth-first-search-dfs)
  - [2.8 Slow & Fast Pointers](#28-slow--fast-pointers)
  - [2.9 Sorting](#29-sorting)
  - [2.10 Two Pointers](#210-two-pointers)

## 0. Acknowledgement

- Special thanks to [**Ruida Huang**](https://www.linkedin.com/in/ruida-huang-a777a7220/) and student organization **Sparks US** [@University of Michigan-Ann Arbor](https://umich.edu) that provides the initial category of LeetCode problems for me to start with
- If you are pressed for time, go check out this post: [Curated List of Top 75 LeetCode Questions to Save Your Time](https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-75-LeetCode-Questions-to-Save-Your-Time-OaM1orEU)
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

  _Note: Rehashing cost is amortized to O(1) over individual inserts_

- Container in C++

  | Container                                                                                   | Header            |
  | ------------------------------------------------------------------------------------------- | ----------------- |
  | [`std::unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)           | `<unordered_map>` |
  | [`std::unordered_multimap`](https://en.cppreference.com/w/cpp/container/unordered_multimap) | `<unordered_map>` |
  | [`std::unordered_set`](https://en.cppreference.com/w/cpp/container/unordered_set)           | `<unordered_set>` |
  | [`std::unordered_multiset`](https://en.cppreference.com/w/cpp/container/unordered_multiset) | `<unordered_set>` |

- Related Algorithm: [**Rabin–Karp String-searching Algorithm**](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm)

- LeetCode Problem

  |     | Title                                     | Difficulty | Time        | Space   |
  | --- | ----------------------------------------- | ---------- | ----------- | ------- |
  | 1   | Two sum                                   | Easy       | O(n)        | O(n)    |
  | 30  | Substring with Concatenation of All Words | Hard       | O(m\*n)     | O(m)    |
  | 36  | Valid Sudoku                              | Medium     | O(n^2)      | O(n^2)  |
  | 49  | Group Anagrams                            | Medium     | O(nlogn)    | O(n)    |
  | 76  | Minimum Window Substring                  | Hard       | O(m+n)      | O(n)    |
  | 128 | Longest Consecutive Sequence              | Medium     | O(n)        | O(n)    |
  | 187 | Repeated DNA Sequences                    | Medium     | O(n)        | O(2^n)  |
  | 217 | Contains Duplicate                        | Easy       | O(n)        | O(n)    |
  | 290 | Word Pattern                              | Easy       | O(MIN(m,n)) | O(m+n)) |
  | 347 | Top K Frequent Elements                   | Medium     | O(n)        | O(n)    |
  | 349 | Intersection of Two Arrays                | Easy       | O(n)        | O(n)    |
  | 383 | Ransom Note                               | Easy       | O(m+n)      | O(n)    |
  | 451 | Sort Characters By Frequency              | Medium     | O(nlogn)    | O(n)    |
  | 560 | Subarray Sum Equals K                     | Medium     | O(n)        | O(n)    |
  | 621 | Task Scheduler                            | Medium     | O(n)        | O(n)    |
  | 705 | Design HashSet                            | Easy       | O(1)        | O(n)    |
  | 763 | Partition Labels                          | Medium     | O(n)        | O(n)    |
  | 767 | Reorganize String                         | Medium     | O(n)        | O(n)    |
  | 819 | Most Common Word                          | Easy       | O(n)        | O(n)    |
  | 904 | Fruit Into Baskets                        | Medium     | O(n)        | O(n)    |

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

  |        | Step | Procedure                                                                                                     |
  | ------ | :--: | ------------------------------------------------------------------------------------------------------------- |
  | Create |  1   | Put all the items into a complete binary tree.                                                                |
  |        |  2   | Starting at the rightmost array position that has a child, _percolate down_ all nodes in reverse level-order. |
  | Push   |  1   | Insert new item as the rightmost leaf of the tree.                                                            |
  |        |  2   | _Percolate up_ newItem to an appropriate spot in the heap to restore the heap property.                       |
  | Pop    |  1   | Save the root to be returned.                                                                                 |
  |        |  2   | Move the item in the rightmost leaf of the tree to the root.                                                  |
  |        |  3   | _Percolate down_ the recently moved item at the root to its proper place to restore heap property.            |
  | Sort   |  1   | Initialize a min heap with all the elements to be sorted.                                                     |
  |        |  2   | Repeatedly call _pop_ to extract elements out of the heap.                                                    |

- Conatiner in C++: [`std::priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue)

- LeetCode Problem

  |     | Title                | Difficulty | Time     | Space |
  | --- | -------------------- | ---------- | -------- | ----- |
  | 23  | Merge k Sorted Lists | Hard       | O(nlogk) | O(k)  |
  | 313 | Super Ugly Number    | Medium     | O(nlogk) | O(n)  |

### 1.4 Linked List

- Time Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(n)    | O(n)  |
  | Search | O(n)    | O(n)  |
  | Insert | O(1)    | O(1)  |
  | Delete | O(1)    | O(1)  |

- Related Methodology: [**2.8 Slow & Fast Pointers**](#28-slow--fast-pointers)

- Container in C++

  | Container                                                                       | Header           |
  | ------------------------------------------------------------------------------- | ---------------- |
  | [`std::list`](https://en.cppreference.com/w/cpp/container/list)                 | `<list>`         |
  | [`std::forward_list`](https://en.cppreference.com/w/cpp/container/forward_list) | `<forward_list>` |

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
  | 705 | Design HashSet                            | Easy       | O(1)     | O(n)    |

---

### 1.5 Queue

- Time Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(n)    | O(n)  |
  | Search | O(n)    | O(n)  |
  | Insert | O(1)    | O(1)  |
  | Delete | O(1)    | O(1)  |

- LeetCode Problem

  |     | Title                        | Difficulty | Time | Space |
  | --- | ---------------------------- | ---------- | ---- | ----- |
  | 225 | Implement Stack using Queues | Easy       | O(n) | O(n)  |
  | 933 | Number of Recent Calls       | Easy       | O(n) | O(n)  |

---

### 1.6 Stack

- Time Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(n)    | O(n)  |
  | Search | O(n)    | O(n)  |
  | Insert | O(1)    | O(1)  |
  | Delete | O(1)    | O(1)  |

- Container in C++

  | Container                                                         | Header    |
  | ----------------------------------------------------------------- | --------- |
  | [`std::stack`](https://en.cppreference.com/w/cpp/container/stack) | `<stack>` |

- Related Methodology: [**Monotonic Stack**](https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack)

- LeetCode Problem

  |      | Title                                    | Difficulty | Time | Space |
  | ---- | ---------------------------------------- | ---------- | ---- | ----- |
  | 20   | Valid Parentheses                        | Easy       | O(n) | O(n)  |
  | 32   | Longest Valid Parentheses                | Hard       | O(n) | O(n)  |
  | 71   | Simplify Path                            | Medium     | O(n) | O(n)  |
  | 84   | **Largest Rectangle in Histogram**       | Hard       | O(n) | O(n)  |
  | 224  | Basic Calculator                         | Hard       | O(n) | O(n)  |
  | 385  | Mini Parser                              | Medium     | O(n) | O(n)  |
  | 402  | Remove K Digits                          | Medium     | O(n) | O(n)  |
  | 682  | Baseball Game                            | Easy       | O(n) | O(n)  |
  | 726  | Number of Atoms                          | Hard       | O(n) | O(n)  |
  | 739  | **Daily Temperatures**                   | Medium     | O(n) | O(n)  |
  | 907  | **Sum of Subarray Minimums**             | Medium     | O(n) | O(n)  |
  | 946  | Validate Stack Sequences                 | Medium     | O(n) | O(n)  |
  | 1047 | Remove All Adjacent Duplicates In String | Easy       | O(n) | O(n)  |
  | 1249 | Minimum Remove to Make Valid Parentheses | Medium     | O(n) | O(n)  |
  | 2104 | **Sum of Subnumsay Ranges**              | Medium     | O(n) | O(n)  |

---

### 1.7 String

- Template in C++: [`std::basic_istringstream`](https://en.cppreference.com/w/cpp/io/basic_istringstream)

- Useful Function in C++

  | Function                                                                                             | Header        |
  | ---------------------------------------------------------------------------------------------------- | ------------- |
  | [`std::isalpha`](https://en.cppreference.com/w/cpp/string/byte/isalpha)                              | `<cctype>`    |
  | [`std::isdigit`](https://en.cppreference.com/w/cpp/string/byte/isdigit)                              | `<cctype>`    |
  | [`std::isupper`](https://en.cppreference.com/w/cpp/string/byte/isupper)                              | `<cctype>`    |
  | [`std::islower`](https://en.cppreference.com/w/cpp/string/byte/islower)                              | `<cctype>`    |
  | [`tolower`](https://en.cppreference.com/w/c/string/byte/tolower)                                     | `<ctype.h>`   |
  | [`toupper`](https://en.cppreference.com/w/c/string/byte/toupper)                                     | `<ctype.h>`   |
  | [`std::string::substr`](https://en.cppreference.com/w/cpp/string/basic_string/substr)                | `<string>`    |
  | [`std::remove`, `std::remove_if`](https://en.cppreference.com/w/cpp/algorithm/remove)                | `<algorithm>` |
  | [`std::reverse`](https://en.cppreference.com/w/cpp/algorithm/reverse)                                | `<algorithm>` |
  | [`std::find`, `std::find_if`, `std::find_if_not`](https://en.cppreference.com/w/cpp/algorithm/find)  | `<algorithm>` |
  | [`std::atoi`, `std::atol`, `std::atoll`](https://en.cppreference.com/w/cpp/string/byte/atoi)         | `<cstdlib>`   |
  | [`std::stoi`, `std::stol`, `std::stoll`](https://en.cppreference.com/w/cpp/string/basic_string/stol) | `<string>`    |

- Related Data Structure

  - [1.2 Hash Table](#12-hash-table)
  - [1.6 Stack](#16-stack)

- Related Methodology

  - [2.3 Dynamic Programming](#23-dynamic-programming)
  - [2.10 Two Pointers](#210-two-pointers)

- Related Algorithm

  - [Knuth–Morris–Pratt String-searching Algorithm (KMP)](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)
  - [Rabin–Karp String-searching Algorithm](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm)
  - [Sliding Window](https://www.geeksforgeeks.org/window-sliding-technique/)

- LeetCode Problem

  |      | Title                                          | Difficulty | Time        | Space   |
  | ---- | ---------------------------------------------- | ---------- | ----------- | ------- |
  | 3    | Longest Substring Without Repeating Characters | Medium     | O(n)        | O(n)    |
  | 5    | Longest Palindromic Substring                  | Medium     | O(n^2)      | O(n^2)  |
  | 6    | Zigzag Conversion                              | Medium     | O(n)        | O(n)    |
  | 8    | String to Integer (atoi)                       | Medium     | O(n)        | O(1)    |
  | 14   | Longest Common Prefix                          | Easy       | O(m\*n)     | O(n)    |
  | 28   | Implement strStr()                             | Easy       | O(m+n)      | O(m)    |
  | 30   | Substring with Concatenation of All Words      | Hard       | O(m\*n)     | O(m)    |
  | 32   | Longest Valid Parentheses                      | Hard       | O(n)        | O(n)    |
  | 49   | Group Anagrams                                 | Medium     | O(nlogn)    | O(n)    |
  | 71   | Simplify Path                                  | Medium     | O(n)        | O(n)    |
  | 187  | Repeated DNA Sequences                         | Medium     | O(n)        | O(2^n)  |
  | 224  | Basic Calculator                               | Hard       | O(n)        | O(n)    |
  | 225  | Implement Stack using Queues                   | Easy       | O(n)        | O(n)    |
  | 227  | Basic Calculator II                            | Medium     | O(n)        | O(n)    |
  | 268  | Missing Number                                 | Easy       | O(n)        | O(1)    |
  | 290  | Word Pattern                                   | Easy       | O(MIN(m,n)) | O(m+n)) |
  | 383  | Ransom Note                                    | Easy       | O(m+n)      | O(n)    |
  | 385  | Mini Parser                                    | Medium     | O(n)        | O(n)    |
  | 402  | Remove K Digits                                | Medium     | O(n)        | O(n)    |
  | 451  | Sort Characters By Frequency                   | Medium     | O(nlogn)    | O(n)    |
  | 726  | Number of Atoms                                | Hard       | O(n)        | O(n)    |
  | 763  | Partition Labels                               | Medium     | O(n)        | O(n)    |
  | 767  | Reorganize String                              | Medium     | O(n)        | O(n)    |
  | 819  | Most Common Word                               | Easy       | O(n)        | O(n)    |
  | 917  | Reverse Only Letters                           | Easy       | O(n)        | O(1)    |
  | 1047 | Remove All Adjacent Duplicates In String       | Easy       | O(n)        | O(n)    |
  | 1249 | Minimum Remove to Make Valid Parentheses       | Medium     | O(n)        | O(n)    |

---

### 1.8 Binary Tree

- Related Methodology

  - [2.2 Divide and Conquer](#22-divide-and-conquer)
  - [2.7 Search](#27-search)

- LeetCode Problem

  |     | Title                                     | Difficulty | Time   | Space   |
  | --- | ----------------------------------------- | ---------- | ------ | ------- |
  | 99  | Recover Binary Search Tree                | Medium     | O(n)   | O(n)    |
  | 103 | Binary Tree Zigzag Level Order Traversal  | Medium     | O(n)   | O(n)    |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)   | O(logn) |
  | 113 | Path Sum II                               | Medium     | O(n^2) | O(n^2)  |
  | 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)   | O(1)    |

---

#### 1.8.1 AVL Tree

- Complexity

  |        | Average | Worst   |
  | ------ | ------- | ------- |
  | Access | O(logn) | O(logn) |
  | Search | O(logn) | O(logn) |
  | Insert | O(logn) | O(logn) |
  | Delete | O(logn) | O(logn) |

---

#### 1.8.2 Binary Search Tree (BST)

- Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(logn) | O(n)  |
  | Search | O(logn) | O(n)  |
  | Insert | O(logn) | O(n)  |
  | Delete | O(logn) | O(n)  |

- LeetCode Problem

  |     | Title                                     | Difficulty | Time | Space   |
  | --- | ----------------------------------------- | ---------- | ---- | ------- |
  | 99  | Recover Binary Search Tree                | Medium     | O(n) | O(n)    |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n) | O(logn) |

---

#### 1.8.3 K-D Tree

- Complexity

  |        | Average | Worst |
  | ------ | ------- | ----- |
  | Access | O(logn) | O(n)  |
  | Search | O(logn) | O(n)  |
  | Insert | O(logn) | O(n)  |
  | Delete | O(logn) | O(n)  |

---

#### 1.8.4 Red-black Tree

- Container in C++

  | Container                                                               | Header  |
  | ----------------------------------------------------------------------- | ------- |
  | [`std::map`](https://en.cppreference.com/w/cpp/container/map)           | `<map>` |
  | [`std::multimap`](https://en.cppreference.com/w/cpp/container/multimap) | `<map>` |
  | [`std::set`](https://en.cppreference.com/w/cpp/container/set)           | `<set>` |
  | [`std::multiset`](https://en.cppreference.com/w/cpp/container/multiset) | `<set>` |

- Complexity

  |        | Average | Worst   |
  | ------ | ------- | ------- |
  | Access | O(logn) | O(logn) |
  | Search | O(logn) | O(logn) |
  | Insert | O(logn) | O(logn) |
  | Delete | O(logn) | O(logn) |

---

### 1.9 Union-Find Disjoint Set (UFDS)

|     | Title                        | Difficulty | Time | Space |
| --- | ---------------------------- | ---------- | ---- | ----- |
| 128 | Longest Consecutive Sequence | Medium     | O(n) | O(n)  |

---

## 2. Methodology

### 2.1 Backtracking

|     | Title                   | Difficulty | Time      | Space     |
| --- | ----------------------- | ---------- | --------- | --------- |
| 46  | Permutations            | Medium     | O(n\*n!)  | O(n\*n!)  |
| 47  | Permutations II         | Medium     | O(n\*n!)  | O(n\*n!)  |
| 78  | Subsets                 | Medium     | O(n\*2^n) | O(n\*2^n) |
| 113 | Path Sum II             | Medium     | O(n^2)    | O(n^2)    |
| 491 | Increasing Subsequences | Medium     | O(n\*2^n) | O(n\*2^n) |

---

### 2.2 Divide and Conquer

|     | Title                                     | Difficulty | Time      | Space   |
| --- | ----------------------------------------- | ---------- | --------- | ------- |
| 23  | Merge k Sorted Lists                      | Medium     | O(nklogk) | O(logk) |
| 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)      | O(logn) |
| 113 | Path Sum II                               | Medium     | O(n^2)    | O(n^2)  |
| 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)      | O(n)    |
| 148 | Sort List                                 | Medium     | O(nlogn)  | O(logn) |

---

### 2.3 Dynamic Programming

|      | Title                               | Difficulty | Time                 | Space       |
| ---- | ----------------------------------- | ---------- | -------------------- | ----------- |
| 5    | Longest Palindromic Substring       | Medium     | O(n^2)               | O(n^2)      |
| 28   | Implement strStr()                  | Easy       | O(m+n)               | O(m)        |
| 32   | Longest Valid Parentheses           | Hard       | O(n)                 | O(n)        |
| 62   | Unique Paths                        | Medium     | O(m\*n)              | O(1)        |
| 139  | Word Break                          | Medium     | O(m\*n)              | O(m+n)      |
| 313  | Super Ugly Number                   | Medium     | O(nlogk)             | O(n)        |
| 322  | Coin Change                         | Medium     | O(m\*n)              | O(m)        |
| 718  | Maximum Length of Repeated Subarray | Medium     | O(m\*n)              | O(MAX(m,n)) |
| 1444 | Number of Ways of Cutting a Pizza   | Hard       | O(m\*n\*MAX(m,n)\*k) | O(m\*n\*k)  |

---

### 2.4 Greedy

|     | Title            | Difficulty | Time | Space |
| --- | ---------------- | ---------- | ---- | ----- |
| 45  | Jump Game II     | Medium     | O(n) | O(1)  |
| 402 | Remove K Digits  | Medium     | O(n) | O(n)  |
| 621 | Task Scheduler   | Medium     | O(n) | O(n)  |
| 763 | Partition Labels | Medium     | O(n) | O(n)  |

---

### 2.5 Mathematical Optimization

|     | Title                   | Difficulty | Time        | Space  |
| --- | ----------------------- | ---------- | ----------- | ------ |
| 62  | Unique Paths            | Medium     | O(MIN(m,n)) | O(1)   |
| 169 | Majority Element        | Easy       | O(n)        | O(1)   |
| 187 | Repeated DNA Sequences  | Medium     | O(n)        | O(2^n) |
| 229 | Majority Element II     | Medium     | O(n)        | O(1)   |
| 268 | Missing Number          | Easy       | O(n)        | O(1)   |
| 382 | Linked List Random Node | Medium     | O(n)        | O(1)   |

---

#### 2.5.1 Bit Manipulation

- Related Methodology

  - Bit Encoding (optimize space)
  - Double XOR (cancel out)

- LeetCode Problem

  |     | Title                  | Difficulty | Time | Space  |
  | --- | ---------------------- | ---------- | ---- | ------ |
  | 187 | Repeated DNA Sequences | Medium     | O(n) | O(2^n) |
  | 268 | Missing Number         | Easy       | O(n) | O(1)   |

---

#### 2.5.2 Boyer–Moore Majority Vote Algorithm

- Goal: Given an array of size $n$, find all majority elements that appear more than $\lfloor\frac{n}{k}\rfloor$ times.

- Procedure

  - At most $k-1$ majority element in $\{A_1, A_2,..., A_n\}$ can appear more than $\lfloor\frac{n}{k}\rfloor$ times:
    - Initialize $k-1$ candidates $\{C_1, C_2,..., C_{k-1}\}$
    - Initialize $k-1$ vote count $\{V_1, V_2,..., V_{k-1}\}$
  - For $A_i$ in $\{A_1, A_2,..., A_n\}$, do:
    - if any $C_j$ equals $A_i$, increase $V_j$ by 1
    - else if any $V_j$ equals $0$: update $C_j$ to $A_i$ and set $V_j$ to 1
    - else if no candidate equals $A_i$, decrease every vote by 1
  - For $C_i$ in $\{C_1, C_2,..., C_{k-1}\}$, do:
    - Count occurrence of $C_i$ in $\{A_1, A_2,..., A_n\}$
    - if occur more than $\lfloor\frac{n}{k}\rfloor$ times, add to output

- LeetCode Problem

  |     | Title               | Difficulty | Time | Space |
  | --- | ------------------- | ---------- | ---- | ----- |
  | 169 | Majority Element    | Easy       | O(n) | O(1)  |
  | 229 | Majority Element II | Medium     | O(n) | O(1)  |

---

#### 2.5.3 Reservoir Sampling

- Goal: Select $k$ entries from $n$ options $\{X_1, X_2,...,X_n\}$. For any $n\ge k$, each entry is selected with same probability $P(X_i)=\frac{k}{n}$.

- Procedure

  - Choose $\{X_1, X_2,..., X_k\}$ first and put them into the reservoir
  - For $i\in [1,n-k]$, do:
    1. Pick $X_{k+i}$ with probability $P(X_{k+i})=\frac{k}{k+i}$
    2. If $X_{k+i}$ is picked, randomly replace an entry in the reservoir with same probability

  _Note: See [Section 3: Proof of Reservoir Sampling](https://github.com/kx-Huang/LeetCode/tree/master/Resources#resources-) in resources page for detailed proof_

- LeetCode Problem

  |     | Title                   | Difficulty | Time | Space |
  | --- | ----------------------- | ---------- | ---- | ----- |
  | 382 | Linked List Random Node | Medium     | O(n) | O(1)  |

---

### 2.6 Prefix Sum

|     | Title                        | Difficulty | Time | Space |
| --- | ---------------------------- | ---------- | ---- | ----- |
| 238 | Product of Array Except Self | Medium     | O(n) | O(n)  |
| 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |

---

### 2.7 Search

|     | Title                                     | Difficulty | Time      | Space     |
| --- | ----------------------------------------- | ---------- | --------- | --------- |
| 35  | Search Insert Position                    | Easy       | O(logn)   | O(1)      |
| 46  | Permutations                              | Medium     | O(n\*n!)  | O(n\*n!)  |
| 47  | Permutations II                           | Medium     | O(n\*n!)  | O(n\*n!)  |
| 78  | Subsets                                   | Medium     | O(n\*2^n) | O(n\*2^n) |
| 103 | Binary Tree Zigzag Level Order Traversal  | Medium     | O(n)      | O(n)      |
| 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)      | O(logn)   |
| 113 | Path Sum II                               | Medium     | O(n^2)    | O(n^2)    |
| 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)      | O(1)      |
| 491 | Increasing Subsequences                   | Medium     | O(n\*2^n) | O(n\*2^n) |
| 704 | Binary Search                             | Easy       | O(logn)   | O(1)      |

---

#### 2.7.1 Binary Search

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

#### 2.7.2 Breadth First Search (BFS)

- Related Data Structure

  - [1.5 Queue](#15-queue)

- LeetCode Problem

  |     | Title                                    | Difficulty | Time    | Space   |
  | --- | ---------------------------------------- | ---------- | ------- | ------- |
  | 103 | Binary Tree Zigzag Level Order Traversal | Medium     | O(n)    | O(n)    |
  | 200 | Number of Islands                        | Medium     | O(m\*n) | O(m\*n) |

---

#### 2.7.3 Depth First Search (DFS)

- Related Data Structure

  - [1.6 Stack](#16-stack)
  - [1.8 Binary Tree](#18-binary-tree)

    |                                                                                           | Time Complexity | Space Complexity |
    | ----------------------------------------------------------------------------------------- | --------------- | ---------------- |
    | Recursive traversal                                                                       | O(n)            | O(n)             |
    | [Morris traversal](https://github.com/kx-Huang/LeetCode/tree/master/Resources#resources-) | O(n)            | O(1)             |

    _Note: See [Section 2: Morris Traversal](https://github.com/kx-Huang/LeetCode/tree/master/Resources#resources-) in resources page for more details_

- LeetCode Problem

  |     | Title                                     | Difficulty | Time      | Space     |
  | --- | ----------------------------------------- | ---------- | --------- | --------- |
  | 46  | Permutations                              | Medium     | O(n\*n!)  | O(n\*n!)  |
  | 47  | Permutations II                           | Medium     | O(n\*n!)  | O(n\*n!)  |
  | 78  | Subsets                                   | Medium     | O(n\*2^n) | O(n\*2^n) |
  | 99  | Recover Binary Search Tree                | Medium     | O(n)      | O(n)      |
  | 109 | Convert Sorted List to Binary Search Tree | Medium     | O(n)      | O(logn)   |
  | 113 | Path Sum II                               | Medium     | O(n^2)    | O(n^2)    |
  | 114 | Flatten Binary Tree to Linked List        | Medium     | O(n)      | O(1)      |
  | 491 | Increasing Subsequences                   | Medium     | O(n\*2^n) | O(n\*2^n) |

---

### 2.8 Slow & Fast Pointers

|     | Title                  | Difficulty | Time     | Space   |
| --- | ---------------------- | ---------- | -------- | ------- |
| 142 | Linked List Cycle II   | Medium     | O(n)     | O(1)    |
| 148 | Sort List              | Medium     | O(nlogn) | O(logn) |
| 234 | Palindrome Linked List | Easy       | O(n)     | O(1)    |

---

### 2.9 Sorting

- Complexity: See _[Section 1.3: Sorting Algorithm](https://github.com/kx-Huang/LeetCode/tree/master/Resources#resources-)_ in resources page for more details

- Algorithm in C++

  | Algorithm                                                                     | Header        |
  | ----------------------------------------------------------------------------- | ------------- |
  | [`std::nth_element`](https://en.cppreference.com/w/cpp/algorithm/nth_element) | `<algorithm>` |
  | [`std::sort`](https://en.cppreference.com/w/cpp/algorithm/sort)               | `<algorithm>` |

- LeetCode Problem

  |      | Title                                            | Difficulty | Time        | Space   |
  | ---- | ------------------------------------------------ | ---------- | ----------- | ------- |
  | 23   | Merge k Sorted Lists                             | Hard       | O(nk\*logk) | O(logk) |
  | 49   | Group Anagrams                                   | Medium     | O(nlogn)    | O(n)    |
  | 56   | Merge Intervals                                  | Medium     | O(nlogn)    | O(n)    |
  | 88   | Merge Sorted Array                               | Easy       | O(m+n)      | O(m+n)  |
  | 148  | Sort List                                        | Medium     | O(nlogn)    | O(logn) |
  | 347  | Top K Frequent Elements                          | Medium     | O(n)        | O(n)    |
  | 451  | Sort Characters By Frequency                     | Medium     | O(nlogn)    | O(n)    |
  | 726  | Number of Atoms                                  | Hard       | O(n)        | O(n)    |
  | 767  | Reorganize String                                | Medium     | O(n)        | O(n)    |
  | 1846 | Maximum Element After Decreasing and Rearranging | Medium     | O(nlogn)    | O(1)    |

---

### 2.10 Two Pointers

- Related Algorithm

  - [Knuth–Morris–Pratt String-searching Algorithm (KMP)](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)
  - [Rabin–Karp String-searching Algorithm](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm)
  - [Sliding Window](https://www.geeksforgeeks.org/window-sliding-technique/)

- LeetCode Problem

  |     | Title                                          | Difficulty | Time    | Space  |
  | --- | ---------------------------------------------- | ---------- | ------- | ------ |
  | 3   | Longest Substring Without Repeating Characters | Medium     | O(n)    | O(n)   |
  | 15  | 3Sum                                           | Medium     | O(n^2)  | O(n^2) |
  | 16  | 3Sum Closest                                   | Medium     | O(n^2)  | O(n^2) |
  | 28  | Implement strStr()                             | Easy       | O(m+n)  | O(m)   |
  | 30  | Substring with Concatenation of All Words      | Hard       | O(m\*n) | O(m)   |
  | 76  | Minimum Window Substring                       | Hard       | O(m+n)  | O(n)   |
  | 88  | Merge Sorted Array                             | Easy       | O(m+n)  | O(m+n) |
  | 167 | Two Sum II - Input Array Is Sorted             | Medium     | O(n)    | O(1)   |
  | 475 | Heaters                                        | Medium     | O(m+n)  | O(1)   |
  | 763 | Partition Labels                               | Medium     | O(n)    | O(n)   |
  | 904 | Fruit Into Baskets                             | Medium     | O(n)    | O(n)   |
  | 917 | Reverse Only Letters                           | Easy       | O(n)    | O(1)   |
  | 977 | Squares of a Sorted Array                      | Easy       | O(n)    | O(n)   |

---
