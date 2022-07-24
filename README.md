# LeetCode [![wakatime](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4.svg)](https://wakatime.com/badge/user/7d2c2fc8-bd1d-4e1e-bb2b-b49c6120ed53/project/888b92b9-c84f-4617-b31c-3668de8ecca4)

This repo contains my personal solutions and notes for LeetCode problems in `C++`.

The framework is auto-generated by `LeetCode VSCode Extension` for reviewing, coding and submitting problems in VSCode. See [Environment Setup](#environment-setup) for more details.

The problems are categorized into two parts:

1. Data Structure:
  - [Hash Table](#11-hash-table)
  - [Heap](#12-heap)

2. Methodology:
  - [Backtracking](#21-backtracking)
  - [Binary Search](#22-binary-search)
  - [Dynamic Programming](#23-dynamic-programming)
  - [Prefix Sum](#24-prefix-sum)
  - [Two Pointers](#25-two-pointers)

## 1. Data Structure

### 1.1 Hash Table

- Time Complexity:

  |        | Best | Average | Worst |
  |--------|------|---------|-------|
  | Access | O(1) | O(1)    | O(n)  |
  | Search | O(1) | O(1)    | O(n)  |
  | Insert | O(1) | O(1)    | O(n)  |
  | Delete | O(1) | O(1)    | O(n)  |
  | Rehash | O(n) | O(n)    | O(n)  |

  *Note*: amortized to O(1) on average per operation

- Ordering: No

- Template in C++:
  - [**`std::unordered_map`**](https://en.cppreference.com/w/cpp/container/unordered_map)
  - [**`std::unordered_set`**](https://en.cppreference.com/w/cpp/container/unordered_set)

|     | Title                        | Difficulty | Time | Space |
|-----|------------------------------|------------|------|-------|
| 1   | Two sum                      | Easy       | O(n) | O(n)  |
| 128 | Longest Consecutive Sequence | Medium     | O(n) | O(n)  |
| 217 | Contains Duplicate           | Easy       | O(n) | O(n)  |
| 349 | Intersection of Two Arrays   | Easy       | O(n) | O(n)  |
| 560 | Subarray Sum Equals K        | Medium     | O(n) | O(n)  |

## 1.2 Heap

|     | Title                     | Difficulty | Time     | Space |
|-----|---------------------------|------------|----------|-------|
| 313 | Super Ugly Number         | Medium     | O(nlogk) | O(n)  |


## 2. Methodology

### 2.1 Backtracking

|     | Title        | Difficulty | Time    | Space |
|-----|--------------|------------|---------|-------|
| 46  | Permutations | Medium     | O(n*n!) | O(n!) |

### 2.2 Binary Search

- Time Complexity:

  | Best | Average | Worst    |
  |------|---------|----------|
  | O(1) | O(logn) | O(logn)  |

- Space Complexity:

  |           | Best | Average | Worst    |
  |-----------|------|---------|----------|
  | Iterative | O(1) | O(1)    | O(1)     |
  | Recursive | O(1) | O(logn) | O(logn)  |

|     | Title                  | Difficulty | Time    | Space |
|-----|------------------------|------------|---------|-------|
| 35  | Search Insert Position | Easy       | O(logn) | O(1)  |
| 704 | Binary Search          | Easy       | O(logn) | O(1)  |

### 2.3 Dynamic Programming

|     | Title                     | Difficulty | Time     | Space |
|-----|---------------------------|------------|----------|-------|
| 313 | Super Ugly Number         | Medium     | O(nlogk) | O(n)  |

### 2.4 Prefix Sum

|     | Title                              | Difficulty | Time | Space |
|-----|------------------------------------|------------|------|-------|
| 238 | Product of Array Except Self       | Medium     | O(n) | O(n)  |
| 560 | Subarray Sum Equals K              | Medium     | O(n) | O(n)  |

### 2.5 Two Pointers

|     | Title                              | Difficulty | Time   | Space |
|-----|------------------------------------|------------|--------|-------|
| 167 | Two Sum II - Input Array Is Sorted | Medium     | O(n)   | O(1)  |
| 475 | Heaters                            | Medium     | O(n+m) | O(1)  |
| 977 | Squares of a Sorted Array          | Easy       | O(n)   | O(n)  |

## Environment Setup

### VSCode Settings

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

### Clang-format for `C++`

Add options to `.clang-format` yaml file, configuration details can be found [here](https://releases.llvm.org/6.0.0/tools/clang/docs/ClangFormatStyleOptions.html)

Sample:

```yaml
---
Language: Cpp
BasedOnStyle: Google
IndentWidth: 4
...
```

### Keyboard Shortcut for Code Submission

Bind in `Code - Preferences - Keyboard Shortcuts`, or `keybindings.json`:

```json
{
  "key": "shift+l",
  "command": "leetcode.submitSolution"
}
```
