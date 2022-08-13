/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 *
 * Method: Sliding Window
 * Data Structure: Hash Table
 *
 */
1 1 1 2 3 4
    // @lc code=start
    class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = fruits.size();
        if (len <= 2) return len;

        // store fruit-count pairs in hash table
        unordered_map<int, int> fruitCount;

        // sliding window: O(n)
        int left = 0;
        int right = 0;

        while (right < len) {
            fruitCount[fruits[right]]++;
            // move left one step ahead if window contains more than 2 elements
            //
            // Remarks: Compare "if" statement with "while" loop in LeetCode 3
            //  we can use "if" statement instead of "while" loop because:
            //    1. right and left can keep maximum window, no need to shrink
            //    2. we can easily check if the window is valid or not with
            //       hash table size instead of checking each element's status
            //    3. faster then "while" loop as window never shrink on average
            //
            // Time Complexity: O(n) < O(2n)
            //   still O(n) but smaller constant then using "while" loop
            // Space Complexity: O(n/2) = O(n) (instead of O(1))
            //   can keep up to n/2 fruits in hash table as window never shrink
            //
            if (fruitCount.size() > 2) {
                int fruit = fruits[left];
                // erase from hash table if no this fruit in window
                if (--fruitCount[fruit] == 0) fruitCount.erase(fruit);
                left++;
            }
            right++;
        }

        return right - left;
    }
};
// @lc code=end
