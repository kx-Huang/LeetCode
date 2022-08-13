/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * Method: Two Pointers
 * Data Structure: String
 *
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Two Pointers: O(n)
        while (left < right) {
            if (isalpha(s[left]) == 0)
                left++;
            else if (isalpha(s[right]) == 0)
                right--;
            else
                swap(s[left++], s[right--]);
        }
        return s;
    }
};
// @lc code=end
