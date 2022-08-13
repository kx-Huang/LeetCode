/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * Method: Sliding Window
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charCount;
        int left = 0;
        int right = 0;
        int ans = 0;

        // Sliding Window: O(2n) = O(n)
        while (right < s.size()) {
            // add element at window right to hash table
            char c = s[right];
            charCount[c]++;
            // move window left one step right and update the hash table
            // until no duplicate in hash table
            while (charCount[c] > 1) charCount[s[left++]]--;
            // update sub-string length if longer
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};
// @lc code=end
