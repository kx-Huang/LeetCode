/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table, String
 *
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;

        // initialize hash table: O(n)
        for (char c : magazine) count[c]++;

        // check whether more characters are required: O(m)
        for (char c : ransomNote)
            if (--count[c] < 0) return false;

        return true;
    }
};
// @lc code=end
