/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table, String
 *
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // use 2 hash table to store pattern-word bijection
        unordered_map<char, string> pattern2word;
        unordered_map<string, char> word2pattern;
        istringstream iss(s);
        string w;
        char p;

        // traversal the string to compare the match
        int i = 0;
        for (; i < pattern.size() && iss >> w; i++) {
            p = pattern[i];
            // add to hash table if the pattern is new
            if (pattern2word.find(p) == pattern2word.end() &&
                word2pattern.find(w) == word2pattern.end()) {
                pattern2word[p] = w;
                word2pattern[w] = p;
            }
            // not matched
            else if (pattern2word[p] != w || word2pattern[w] != p)
                return false;
        }

        // size not match: more pattern or more word
        if (i != pattern.size() || iss >> w) return false;

        // size matched
        return true;
    }
};
// @lc code=end
