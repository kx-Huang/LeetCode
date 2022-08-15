/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * Method: Sliding Window
 * Data Structure: Hash Table, String
 *
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();

        if (sLen == 0 | tLen == 0 | sLen < tLen) return string("");

        // save the char needed and its number in hash table: O(n)
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        string ans = "";
        int left = 0;
        int right = 0;
        int needs = tLen;      // to save number of all alphabets still needed
        int minLen = INT_MAX;  // to save minimum length of sub string

        // sliding window to find minimum: O(m+n)
        for (; right < sLen; right++) {
            char rightChar = s[right];
            // if the current alphabet is in target alphabets:
            //  decrease number of all alphabet needed
            if (need.find(rightChar) != need.end()) {
                // if current alphabet is needed:
                //  decrease number of all alphabet needed
                if (need[rightChar] > 0) needs--;
                //  decrease number of current alphabet needed
                //  (negative number of need means that we find too much target,
                //   to be discarded when shrinking left)
                need[rightChar]--;
            }

            // after finding a valid sub string by moving right,
            // try to shrink from the left to find minimum
            for (; needs == 0; left++) {
                // save minimum valid window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    ans = s.substr(left, minLen);
                }

                char leftChar = s[left];
                // if it is a target
                if (need.find(leftChar) != need.end()) {
                    // discard this alphabet
                    need[leftChar]++;
                    // if we need this alphabet after we discard it,
                    //  - the window will no longer be valid
                    //  - we can keep on expanding right
                    if (need[leftChar] > 0) needs++;
                }
            }
        }

        return minLen == INT_MAX ? "" : ans;
    }
};
// @lc code=end
