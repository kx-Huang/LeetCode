# LeetCode ![](https://img.shields.io/badge/status-updating-brightgreen) [![wakatime](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4.svg)](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4) ![](https://visitor-badge.glitch.me/badge?page_id=kx-Huang.LeetCode&left_color=gray&right_color=blue) <!-- omit in toc -->

Personal solutions and notes for LeetCode problems in `C++`.

## Table of Content: <!-- omit in toc -->

- [0. Acknowledgement](#0-acknowledgement)
- [1. Data Structure](#1-data-structure)
  - [1.1 Graph](#11-graph)
  - [1.2 Hash Table](#12-hash-table)
  - [1.3 Heap](#13-heap)
    - [1.3.1 Binary Heap](#131-binary-heap)
    - [1.3.2 Binomial Heap](#132-binomial-heap)
    - [1.3.3 Fibonacci Heap](#133-fibonacci-heap)
  - [1.4 Linked List](#14-linked-list)
  - [1.5 Tree](#15-tree)
    - [1.5.1 AVL Tree](#151-avl-tree)
    - [1.5.2 B Tree](#152-b-tree)
    - [1.5.3 B+ Tree](#153-b-tree)
    - [1.5.4 Binary Search Tree (BST)](#154-binary-search-tree-bst)
    - [1.5.5 K-D Tree](#155-k-d-tree)
    - [1.5.6 Red-black Tree](#156-red-black-tree)
    - [1.5.7 Trie](#157-trie)
- [2. Methodology](#2-methodology)
  - [2.1 Backtracking](#21-backtracking)
  - [2.2 Divide and Conquer](#22-divide-and-conquer)
  - [2.3 Dynamic Programming](#23-dynamic-programming)
  - [2.4 Prefix Sum](#24-prefix-sum)
  - [2.5 Reservoir Sampling](#25-reservoir-sampling)
  - [2.6 Search](#26-search)
    - [2.6.1 Binary Search](#261-binary-search)
    - [2.6.2 Depth First Search](#262-depth-first-search)
  - [2.7 Two Pointers](#27-two-pointers)

## 0. Acknowledgement

- Special thanks to [**Ruida Huang**](https://www.linkedin.com/in/ruida-huang-a777a7220/) and student organization **Sparks US** [@University of Michigan-Ann Arbor](https://umich.edu) that provides the initial category of LeetCode problems for me to start with
- `LeetCode VSCode Extension` is used for quick problem preview and code submission
- Great thanks to all resouce contributors of related resouces

## 1. Data Structure
### 1.1 Graph

---

### 1.2 Hash Table

- Time Complexity:

  |        | Best | Average | Worst |
  | ------ | ---- | ------- | ----- |
  | Access | O(1) | O(1)    | O(n)  |
  | Search | O(1) | O(1)    | O(n)  |
  | Insert | O(1) | O(1)    | O(n)  |
  | Delete | O(1) | O(1)    | O(n)  |
  | Rehash | O(n) | O(n)    | O(n)  |

- Remarks: Rehashing cost is amortized to O(1) over individual inserts

- Ordering: No

- Template in C++:
  - [`std::unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)
  - [`std::unordered_set`](https://en.cppreference.com/w/cpp/container/unordered_set)

- LeetCode Problems:

  |     | Title                        | Difficulty | Time | Space |
  | --- | ---------------------------- | ---------- | ---- | ----- |
  | 1   | Two sum                      | Easy       | O(n) | O(n)  |
  | 128 | Longest Consecutive Sequence | Medium     | O(n) | O(n)  |
  | 217 | Contains Duplicate           | Easy       | O(n) | O(n)  |
  | 349 | Intersection of Two Arrays   | Easy       | O(n) | O(n)  |
  | 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |

---

### 1.3 Heap

#### 1.3.1 Binary Heap

- Time Complexity

  |        | Best     | Average  | Worst    |
  | ------ | -------- | -------- | -------- |
  | Create | O(n)     | O(n)     | O(n)     |
  | Push   | O(1)     | O(logn)  | O(logn)  |
  | Pop    | O(1)     | O(logn)  | O(logn)  |
  | Sort   | O(nlogn) | O(nlogn) | O(nlogn) |

- Remarks:
  - Create
    1. Put all the items into a complete binary tree.
    2. Starting at the rightmost array position that has a child, *percolate down* all nodes in reverse level-order.
  - Push
    1. Insert new item as the rightmost leaf of the tree.
    2. *Percolate up* newItem to an appropriate spot in the heap to restore the heap property.
  - Pop
    1. Save the root to be returned.
    2. Move the item in the rightmost leaf of the tree to the root.
    3. *Percolate down* the recently moved item at the root to its proper place to restore heap property.
  - Sort
    1. Initialize a min heap with all the elements to be sorted.
    2. Repeatedly call *pop* to extract elements out of the heap.

- Ordering: Yes

- Template in C++: [`std::priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue)

- LeetCode Problems:

  |     | Title                | Difficulty | Time     | Space |
  | --- | -------------------- | ---------- | -------- | ----- |
  | 23  | Merge k Sorted Lists | Hard       | O(nlogk) | O(k)  |
  | 313 | Super Ugly Number    | Medium     | O(nlogk) | O(n)  |

#### 1.3.2 Binomial Heap

---

#### 1.3.3 Fibonacci Heap

---

### 1.4 Linked List

- Time Complexity:

  |        | Best | Average | Worst |
  | ------ | ---- | ------- | ----- |
  | Access | O(1) | O(n)    | O(n)  |
  | Search | O(1) | O(n)    | O(n)  |
  | Insert | O(1) | O(1)    | O(1)  |
  | Delete | O(1) | O(1)    | O(1)  |

- Related Methodology: **Slow-Fast Pointer**

- LeetCode Problems:

  |     | Title                              | Difficulty | Time     | Space |
  | --- | ---------------------------------- | ---------- | -------- | ----- |
  | 23  | Merge k Sorted Lists               | Hard       | O(nlogk) | O(k)  |
  | 24  | Swap Nodes in Pairs                | Medium     | O(n)     | O(1)  |
  | 25  | Reverse Nodes in k-Group           | Hard       | O(n)     | O(1)  |
  | 86  | Partition List                     | Medium     | O(n)     | O(1)  |
  | 114 | Flatten Binary Tree to Linked List | Medium     | O(n)     | O(1)  |
  | 142 | Linked List Cycle II               | Medium     | O(n)     | O(1)  |
  | 160 | Intersection of Two Linked Lists   | Easy       | O(m+n)   | O(1)  |
  | 234 | Palindrome Linked List             | Easy       | O(n)     | O(1)  |
  | 328 | Odd Even Linked List               | Medium     | O(n)     | O(1)  |
  | 382 | Linked List Random Node            | Medium     | O(n)     | O(1)  |

---

### 1.5 Tree

|     | Title                              | Difficulty | Time     | Space |
| --- | ---------------------------------- | ---------- | -------- | ----- |
| 23  | Merge k Sorted Lists               | Hard       | O(nlogk) | O(k)  |
| 114 | Flatten Binary Tree to Linked List | Medium     | O(n)     | O(1)  |
| 313 | Super Ugly Number                  | Medium     | O(nlogk) | O(n)  |

---

#### 1.5.1 AVL Tree

---

#### 1.5.2 B Tree

---

#### 1.5.3 B+ Tree

---

#### 1.5.4 Binary Search Tree (BST)

---

#### 1.5.5 K-D Tree

---

#### 1.5.6 Red-black Tree

---

#### 1.5.7 Trie

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

|     | Title                | Difficulty | Time      | Space   |
| --- | -------------------- | ---------- | --------- | ------- |
| 23  | Merge k Sorted Lists | Medium     | O(nklogk) | O(logk) |

---

### 2.3 Dynamic Programming

|     | Title             | Difficulty | Time     | Space |
| --- | ----------------- | ---------- | -------- | ----- |
| 313 | Super Ugly Number | Medium     | O(nlogk) | O(n)  |
| 322 | Coin Change       | Medium     | O(m*n)   | O(m)  |

---

### 2.4 Prefix Sum

|     | Title                        | Difficulty | Time | Space |
| --- | ---------------------------- | ---------- | ---- | ----- |
| 238 | Product of Array Except Self | Medium     | O(n) | O(n)  |
| 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |

---

### 2.5 Reservoir Sampling

- To prove: Select $k$ entries from $n$ options $\{X_1, X_2,...,X_n\}$. For any $n\ge k$, each entry is selected with same probability $P(X_i)=\frac{k}{n}$.

- Procedures:
  - Choose $\{X_1, X_2,..., X_k\}$ first and put them into the reservoir
  - For $i\in [1,n-k]$, do:
    1. Pick $X_{k+i}$ with probability $P(X_{k+i})=\frac{k}{k+i}$
    2. If $X_{k+i}$ is picked, randomly replace an entry in the reservoir with same probability

- Proof: **Mathematical Induction**
  - Initial condition $n=k$: $\{X_1, X_2,..., X_k\}$ are all in the reservoir.
  - Keep $k$ constant and increase $n$.
  - When $n=k+1$:
    - $X_{k+1}$ is picked with $P(X_{k+1})=\frac{k}{k+1}=\frac{k}{n}$
    - For $j=1,2,...,k$, the probability of $X_j$ is not being replaced is $P(X_j) = 1-\frac{k}{n}\cdot\frac{1}{k}=\frac{n-1}{n}=\frac{k}{n}$
  - Assume $n=k+i$ is true:
    - For $j\in[1,k+i]$, the probability of $X_j$ is in the reservoir is $P(X_{k+i})=\frac{k}{k+i}$
  - When $n=k+i+1$:
    - For $j=k+i+1$, $X_j$ is picked with $P(X_j)=\frac{k}{k+i+1}=\frac{k}{n}$
    - For $j\in[1,k+i]$, the probability of $X_j$:
      1. in the reservoir last round: $\frac{k}{k+i}$
      2. not being replaced: $1-\frac{k}{k+i+1}\cdot\frac{1}{k}$

      So $P(X_j) = \frac{k}{k+i}\cdot\left(1-\frac{k}{k+i+1}\cdot\frac{1}{k}\right)=\frac{k}{k+i}\cdot\frac{k+i}{k+i+1}=\frac{k}{n}$
  - Q.E.D.

- LeetCode Problems:

  |     | Title                   | Difficulty | Time | Space |
  | --- | ----------------------- | ---------- | ---- | ----- |
  | 382 | Linked List Random Node | Medium     | O(n) | O(1)  |

---

### 2.6 Search

|     | Title                              | Difficulty | Time    | Space |
| --- | ---------------------------------- | ---------- | ------- | ----- |
| 35  | Search Insert Position             | Easy       | O(logn) | O(1)  |
| 114 | Flatten Binary Tree to Linked List | Medium     | O(n)    | O(1)  |
| 704 | Binary Search                      | Easy       | O(logn) | O(1)  |

---

#### 2.6.1 Binary Search

- Time Complexity: O(logn)

- Space Complexity:
  - Iterative: O(1)
  - Recursive: O(logn)

- LeetCode Problems:

  |     | Title                  | Difficulty | Time    | Space |
  | --- | ---------------------- | ---------- | ------- | ----- |
  | 35  | Search Insert Position | Easy       | O(logn) | O(1)  |
  | 704 | Binary Search          | Easy       | O(logn) | O(1)  |

---

#### 2.6.2 Depth First Search

- Binary Tree:

  |                                                  | Time Complexity | Space Complexity |
  | ------------------------------------------------ | --------------- | ---------------- |
  | Recursive traversal                              | O(n)            | O(n)             |
  | Morris traversal^[Resources 2: Morris Traversal] | O(n)            | O(1)             |

- LeetCode Problems:

  |     | Title                              | Difficulty | Time | Space |
  | --- | ---------------------------------- | ---------- | ---- | ----- |
  | 114 | Flatten Binary Tree to Linked List | Medium     | O(n) | O(1)  |

---

### 2.7 Two Pointers

|     | Title                              | Difficulty | Time   | Space  |
| --- | ---------------------------------- | ---------- | ------ | ------ |
| 15  | 3Sum                               | Medium     | O(n^2) | O(n^2) |
| 16  | 3Sum Closest                       | Medium     | O(n^2) | O(n^2) |
| 167 | Two Sum II - Input Array Is Sorted | Medium     | O(n)   | O(1)   |
| 475 | Heaters                            | Medium     | O(m+n) | O(1)   |
| 977 | Squares of a Sorted Array          | Easy       | O(n)   | O(n)   |

---
