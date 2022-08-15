/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table, Ordered Map, String
 *
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        multimap<int, char> freq;
        string ans;

        // use hash table to store character count: O(n)
        for (char c : s) count[c]++;

        // order by frequency using multimap in case same key: O(nlogn)
        for (auto p : count) freq.insert(make_pair(p.second, p.first));

        // cascade characters to form output string: O(n)
        for (auto it = freq.rbegin(); it != freq.rend(); it++)
            ans += string(it->first, it->second);

        return ans;
    }
};
// @lc code=end
