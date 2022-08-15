/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table, Ordered Map, String
 *
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        int len = s.size();
        if (len <= 2) return s;

        // Step 1: LeetCode 451: Sort Characters By Frequency
        //   e.g.: aabbaaacc -> aaaaabbcc
        // Step 2: merge two halfs element by element
        //   e.g.: aaaaabbcc -> aaaaa/bbcc -> ababacaca

        // optimize space usage using vector to replace hash table
        vector<int> count(26, 0);
        multimap<int, char> freq;
        string sorted;

        // sort characters by frequency: O(nlogn)
        // (actually O(1) as only 26 alphabet)
        for (char c : s) count[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            int num = count[i];
            // if number of current alphabet exceed half of the string,
            // impossible to make adjacent different
            if (num > (len + 1) / 2) return string("");
            if (num > 0) freq.insert(make_pair(num, i + 'a'));
        }
        for (auto it = freq.rbegin(); it != freq.rend(); it++)
            sorted += string(it->first, it->second);

        int mid = (len - 1) / 2;
        string ans;

        // merge two halfs element by element: O(n)
        for (int i = 0, j = mid + 1; i <= mid; i++, j++) {
            ans += sorted[i];
            if (j < len) ans += sorted[j];
        }

        return ans;
    }
};
// @lc code=end
