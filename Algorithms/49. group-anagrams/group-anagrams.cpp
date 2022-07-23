/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * Method: Sorting, Iterative Traversal
 * Data Structure: Hash Table, String
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() < 2) return vector(1, strs);

        unordered_map<string, vector<string>> anagrams;

        // sort string to group the anagrams in hash table: O(nlogn)
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            anagrams[tmp].push_back(s);
        }

        // output the value (anagram groups) in hash table: O(n)
        vector<vector<string>> ans;
        for (auto a : anagrams) ans.push_back(a.second);
        return ans;
    }
};
// @lc code=end
