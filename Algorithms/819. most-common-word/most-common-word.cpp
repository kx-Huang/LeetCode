/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 *
 * Methods: Iterative Traversal
 * Data Structure: Hash Table, String
 *
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // change all alphabets to lower case and remove punctuations: O(n)
        for (char& character : paragraph)
            character = isalpha(character) ? tolower(character) : ' ';

        // initialize word-count pair to hashtable for O(1) look up: O(n)
        unordered_map<string, int> wordCounts;
        istringstream iss(paragraph);
        string word;
        while (iss >> word) ++wordCounts[word];

        // set banned-words count to zero: O(n)
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        for (auto ban : bannedWords) wordCounts[ban] = 0;

        // get the word with maximum count: O(n)
        pair<string, int> ans("", 0);
        for (auto pair : wordCounts)
            if (pair.second > ans.second) ans = pair;

        return ans.first;
    }
};
// @lc code=end
