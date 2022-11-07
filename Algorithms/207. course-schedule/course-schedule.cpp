/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * Method: Topological Sort
 * Data Structure: Graph, Queue, Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 1) return true;

        // prerequisites: [[1,0]]
        // directed edge in graph: 0 => 1
        // goal: use topological sort to determine whether a loop exists

        // store in-degree and neighbours with hash table: O(V+E)
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> neighbour;
        for (auto edge : prerequisites) {
            int start = edge[1];
            int end = edge[0];
            inDegree[end]++;
            if (inDegree.find(start) == inDegree.end()) inDegree[start] = 0;
            neighbour[start].push_back(end);
        }

        // topological sort: O(V+E)
        queue<int> q;
        vector<int> sorted;
        for (auto node : inDegree)
            if (node.second == 0) q.push(node.first);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sorted.push_back(node);
            for (int n : neighbour[node])
                if (--inDegree[n] == 0) q.push(n);
        }

        // count sorted array size to determine if all the nodes are sorted
        // the size of in-degree hash table represents the size of all nodes
        return sorted.size() == inDegree.size();
    }
};
// @lc code=end
