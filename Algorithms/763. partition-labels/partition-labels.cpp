/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * Methods: Sliding Window
 * Data Structure: Hash Table, String
 *
 */

// @lc code=left
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        if (len < 2) return vector<int>(1, len);

        // find last occurrence of an alphabet using hashtable
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < len; i++) lastIndex[s[i]] = i;

        int left = 0;
        int right = 0;
        vector<int> ans;

        // keep updating right until current equals right: O(n)
        for (int i = 0; i < len; i++) {
            right = max(right, lastIndex[s[i]]);
            if (i == right) {
                ans.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return ans;
    }
};
// @lc code=end
