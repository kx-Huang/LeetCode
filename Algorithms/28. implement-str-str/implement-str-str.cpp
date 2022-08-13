/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * Method: KMP String Matching Algorithm
 * Data Structure: String, Array
 *
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int stringLen = haystack.size();
        int patternLen = needle.size();

        if (patternLen == 0) return 0;

        // KMP String Matching Algorithm: O(m+n)
        vector<int> LPS = getLPS(needle);  // O(m)
        int i = 0, j = 0;

        // scan throught string with no backtracking // O(n)
        while (1) {
            // if match, move to next character
            if (haystack[i] == needle[j]) {
                i++, j++;
                // pattern reaches end, found sub-string
                if (j == patternLen) return i - j;
                // string reaches end, no sub-string found
                if (i == stringLen) return -1;
            } else {  // if not match:
                // compare current char with prefix of pattern
                if (j > 0) j = LPS[j - 1];
                // or move on to next character if have nay
                else if (++i == stringLen)
                    return -1;
            }
        }

        // code should not reach here
        assert(false);
    }

private:
    // compute LPS array with pattern string: O(m)
    // LPS: the length of the longest suffix that is also a prefix
    // index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
    // char:  | a | b | a | b | c | a | b | a | b | a |
    // value: | 0 | 0 | 1 | 2 | 0 | 1 | 2 | 3 | 4 | 3 |
    vector<int> getLPS(string pattern) {
        int n = pattern.size();
        vector<int> LPS(n, 0);
        for (int i = 1, len = 0; i < n;) {
            // current char equals the next char of longest prefix
            if (pattern[i] == pattern[len]) LPS[i++] = ++len;
            // the char to compare is:
            //  the next char of the longest prefix of the longest prefix
            else if (len > 0)
                len = LPS[len - 1];
            // the longest prefix of the longest prefix is 0
            else
                LPS[i++] = 0;
        }
        return LPS;
    }
};
// @lc code=end
