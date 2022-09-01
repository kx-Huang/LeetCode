/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * Method: Iterative Traversal
 * Data Structure: Union-Find Disjoint Set
 *
 */

// @lc code=start
class Solution {
private:
    vector<int> parent;
    vector<int> size;

private:
    int find(int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    void union_set(int a, int b) {
        int i = find(a);
        int j = find(b);
        // return if two nodes have the same root
        if (i == j) return;
        if (size[i] > size[j]) {
            parent[j] = i;
            size[i] += size[j];
        } else {
            parent[i] = j;
            size[j] += size[i];
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;

        // union-find data structure
        parent = vector<int>(len);
        size = vector<int>(len, 1);

        // initialize the parent array: O(n)
        for (int i = 0; i < len; i++) parent[i] = i;

        // use hash table to store previous value
        unordered_map<int, int> record;

        // create union-find disjoint set: O(n)
        for (int i = 0; i < len; i++) {
            int num = nums[i];
            // ignore the number occurred before
            if (record.find(num) != record.end()) continue;
            record[num] = i;
            // union the index of number if found consecutive
            if (record.find(num - 1) != record.end())
                union_set(i, record[num - 1]);
            if (record.find(num + 1) != record.end())
                union_set(i, record[num + 1]);
        }

        // return the largest set
        return *max_element(size.begin(), size.end());
    }
};
// @lc code=end
