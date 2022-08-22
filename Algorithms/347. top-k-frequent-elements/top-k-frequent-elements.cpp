/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * Method: n-th Element, Sorting
 * Data Structure: Hash Table, Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // use hash table to freq each number
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        // put all unique number to a vector
        vector<int> v;
        for (auto p : freq) v.push_back(p.first);

        // use nth element to find the first k numbers with highest frequency
        // the comparison method is based on the frequency freq in hash table
        nth_element(v.begin(), v.begin() + k - 1, v.end(),
                    [&freq](int num1, int num2) -> bool {
                        return freq[num1] > freq[num2];
                    });

        // return first k elements
        v.resize(k);
        return v;
    }
};
// @lc code=end
