# LeetCode [![wakatime](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4.svg)](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4) <!-- omit in toc -->

Personal solutions and notes for LeetCode problems in `C++`.

## Table of Content: <!-- omit in toc -->

- [Acknowledgement](#acknowledgement)
- [0. Environment Setup](#0-environment-setup)
  - [0.1 VSCode Settings](#01-vscode-settings)
  - [0.2 Clang-format for `C++`](#02-clang-format-for-c)
  - [0.3 Keyboard Shortcut for Code Submission](#03-keyboard-shortcut-for-code-submission)
  - [0.4 Helpful VSCode Extensions](#04-helpful-vscode-extensions)
- [1. Data Structure](#1-data-structure)
- [1.1 Binary Heap](#11-binary-heap)
  - [1.2 Hash Table](#12-hash-table)
  - [1.3 Linked List](#13-linked-list)
- [2. Methodology](#2-methodology)
  - [2.1 Backtracking](#21-backtracking)
  - [2.2 Binary Search](#22-binary-search)
  - [2.3 Dynamic Programming](#23-dynamic-programming)
  - [2.4 Prefix Sum](#24-prefix-sum)
  - [2.5 Two Pointers](#25-two-pointers)

## Acknowledgement

- Special thanks to [**Ruida Huang**](https://www.linkedin.com/in/ruida-huang-a777a7220/) and student organization **Sparks US** @University of Michigan-Ann Arbor that provides the initial category of LeetCode problems for me to start with
- Great thanks to all contributors of online resouces

## 0. Environment Setup

The framework is auto-generated by `LeetCode VSCode Extension` for quick problem preview and code submission in VSCode. Configure your own with following settings:

1. [VSCode Settings](#1-vscode-settings)
2. [Clang-format for `C++`](#2-clang-format-for-c)
3. [Keyboard Shortcut for Code Submission](#3-keyboard-shortcut-for-code-submission)
4. [Helpful VSCode Extensions](#4-helpful-vscode-extensions)

### 0.1 VSCode Settings

`settings.json`:

```json
  "leetcode.defaultLanguage": "cpp",
  "leetcode.workspaceFolder": "~/Github/LeetCode/Algorithms",
  "leetcode.filePath": {
    "default": {
      "folder": "${id}. ${kebab-case-name}",
      "filename": "${kebab-case-name}.${ext}"
    }
  }
```

### 0.2 Clang-format for `C++`

Add options to `.clang-format` yaml file, configuration details can be found [here](https://releases.llvm.org/6.0.0/tools/clang/docs/ClangFormatStyleOptions.html)

Sample:

```yaml
---
Language: Cpp
BasedOnStyle: Google
IndentWidth: 4
...
```

### 0.3 Keyboard Shortcut for Code Submission

Bind in `Code - Preferences - Keyboard Shortcuts`, or `keybindings.json`:

```json
{
  "key": "shift+l",
  "command": "leetcode.submitSolution"
}
```

### 0.4 Helpful VSCode Extensions

- *GitLens — Git supercharged*: Visualize code authorship
- *Markdown All in One*: Format markdown files
- *Non-breaking space highlighter*: Visualizes odd characters
- *Trailing Spaces*: Highlight trailing spaces
- *Clang-Format*: Code formatter


## 1. Data Structure

## 1.1 Binary Heap

- Time Complexity

  |        | Best     | Average  | Worst    | Remarks                                                                                                                                                                                       |
  | ------ | -------- | -------- | -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  | Create | O(n)     | O(n)     | O(n)     | Put all the items into a complete binary tree. Starting at the rightmost array position that has a child, *percolate down* all nodes in reverse level-order.                                  |
  | Push   | O(1)     | O(logn)  | O(logn)  | Insert new item as the rightmost leaf of the tree. *Percolate up* newItem to an appropriate spot in the heap to restore the heap property.                                                    |
  | Pop    | O(1)     | O(logn)  | O(logn)  | Save the root to be returned. Move the item in the rightmost leaf of the tree to the root. *Percolate down* the recently moved item at the root to its proper place to restore heap property. |
  | Sort   | O(nlogn) | O(nlogn) | O(nlogn) | Initialize a min heap with all the elements to be sorted. Repeatedly call *pop* to extract elements out of the heap.                                                                          |

- Ordering: Yes

- Template in C++: [`std::priority_queue`](https://en.cppreference.com/w/cpp/container/priority_queue)

- LeetCode Problems:

  |     | Title             | Difficulty | Time     | Space |
  | --- | ----------------- | ---------- | -------- | ----- |
  | 313 | Super Ugly Number | Medium     | O(nlogk) | O(n)  |

### 1.2 Hash Table

- Time Complexity:

  |        | Best | Average | Worst | Remarks                                                     |
  | ------ | ---- | ------- | ----- | ----------------------------------------------------------- |
  | Access | O(1) | O(1)    | O(n)  |                                                             |
  | Search | O(1) | O(1)    | O(n)  |                                                             |
  | Insert | O(1) | O(1)    | O(n)  | Rehashing cost is amortized to O(1) over individual inserts |
  | Delete | O(1) | O(1)    | O(n)  |                                                             |
  | Rehash | O(n) | O(n)    | O(n)  |                                                             |

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

### 1.3 Linked List

- Time Complexity:

  |        | Best | Average | Worst |
  | ------ | ---- | ------- | ----- |
  | Access | O(1) | O(n)    | O(n)  |
  | Search | O(1) | O(n)    | O(n)  |
  | Insert | O(1) | O(1)    | O(1)  |
  | Delete | O(1) | O(1)    | O(1)  |

- Related Methodology: **Slow-Fast Pointer**

- LeetCode Problems:

  |     | Title                  | Difficulty | Time | Space |
  | --- | ---------------------- | ---------- | ---- | ----- |
  | 234 | Palindrome Linked List | Easy       | O(n) | O(1)  |

## 2. Methodology

### 2.1 Backtracking

|     | Title           | Difficulty | Time     | Space    |
| --- | --------------- | ---------- | -------- | -------- |
| 46  | Permutations    | Medium     | O(n*n!)  | O(n*n!)  |
| 47  | Permutations II | Medium     | O(n*n!)  | O(n*n!)  |
| 78  | Subsets         | Medium     | O(n*2^n) | O(n*2^n) |

### 2.2 Binary Search

- Time Complexity:

  | Best | Average | Worst   |
  | ---- | ------- | ------- |
  | O(1) | O(logn) | O(logn) |

- Space Complexity:

  |           | Best | Average | Worst   |
  | --------- | ---- | ------- | ------- |
  | Iterative | O(1) | O(1)    | O(1)    |
  | Recursive | O(1) | O(logn) | O(logn) |

- LeetCode Problems:

  |     | Title                  | Difficulty | Time    | Space |
  | --- | ---------------------- | ---------- | ------- | ----- |
  | 35  | Search Insert Position | Easy       | O(logn) | O(1)  |
  | 704 | Binary Search          | Easy       | O(logn) | O(1)  |

### 2.3 Dynamic Programming

|     | Title             | Difficulty | Time     | Space |
| --- | ----------------- | ---------- | -------- | ----- |
| 313 | Super Ugly Number | Medium     | O(nlogk) | O(n)  |
| 322 | Coin Change       | Medium     | O(n*m)   | O(m)  |

### 2.4 Prefix Sum

|     | Title                        | Difficulty | Time | Space |
| --- | ---------------------------- | ---------- | ---- | ----- |
| 238 | Product of Array Except Self | Medium     | O(n) | O(n)  |
| 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |

### 2.5 Two Pointers

|     | Title                              | Difficulty | Time   | Space  |
| --- | ---------------------------------- | ---------- | ------ | ------ |
| 15  | 3Sum                               | Medium     | O(n^2) | O(n^2) |
| 16  | 3Sum Closest                       | Medium     | O(n^2) | O(n^2) |
| 167 | Two Sum II - Input Array Is Sorted | Medium     | O(n)   | O(1)   |
| 475 | Heaters                            | Medium     | O(n+m) | O(1)   |
| 977 | Squares of a Sorted Array          | Easy       | O(n)   | O(n)   |
