/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * Method: Sliding Window
 * Data Structure: Hash Table, String
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // initialize target hash table: O(m)
        unordered_map<string, int> target;
        for (string word : words) target[word]++;

        vector<int> ans;
        int stringLen = s.size();
        int wordNum = words.size();
        int wordLen = words[0].size();

        // sliding window with const length: O(m*n)
        for (int i = 0; i <= stringLen - wordNum * wordLen; i++) {
            // use current word map to compare with target word map
            unordered_map<string, int> current;
            // compare word with target in current window: O(m)
            for (int num = 0; num < wordNum; num++) {
                string word = s.substr(i + num * wordLen, wordLen);
                // word is not in target table, move on
                if (target.find(word) == target.end()) break;
                // word is in target table, add to current table
                current[word]++;
                // quantity not match, move on
                if (current[word] > target[word]) break;
            }
            if (current == target) ans.push_back(i);
        }

        return ans;
    }
};
// @lc code=end
