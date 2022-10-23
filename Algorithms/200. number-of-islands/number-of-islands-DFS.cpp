/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * Method: Depth First Search
 * Data Structure: Stack
 *
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = n ? grid[0].size() : 0;

        // DFS: Push adjacent land to stack and pop top to push new adjacent
        int ans = 0;
        stack<pair<int, int>> toExplore;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // DFS
                if (grid[i][j] == '1') {
                    ans++;  // found one island
                    toExplore.push({i, j});
                    grid[i][j] = '0';  // mark "visited"
                    while (!toExplore.empty()) {
                        auto cur = toExplore.top();
                        int x = cur.first;
                        int y = cur.second;
                        toExplore.pop();
                        // detect left
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            toExplore.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }
                        // detect right
                        if (y + 1 < m && grid[x][y + 1] == '1') {
                            toExplore.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                        // detect up
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            toExplore.push({x - 1, y});
                            grid[x - 1][y] = '0';
                        }
                        // detect down
                        if (x + 1 < n && grid[x + 1][y] == '1') {
                            toExplore.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
