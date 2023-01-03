/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * Method: Breadth First Search
 * Data Structure: Hash Table, Queue
 *
 */

// @lc code=start

/*
   0 0 0 0 0 0 0    0 0 0 0 0 0 0
   0 1 1 1 1 0 0    0 2 2 2 2 0 0
   0 1 0 0 1 0 0    0 2 0 0 2 0 0      2
   1 0 1 0 1 0 0 => 3 0 4 0 2 0 0 => 3 0 4 => 15+1+1+1=18
   0 1 0 0 1 0 0    0 2 0 0 2 0 0      2
   0 1 0 0 1 0 0    0 2 0 0 2 0 0
   0 1 1 1 1 0 0    0 2 2 2 2 0 0
*/

class Solution {
private:
    int max_group_size = 0;
    unordered_map<int, int> islandArea;

    // use BFS to get area of each island, name them with integer
    void getGroupArea(vector<vector<int>>& grid) {
        // queue for BFS, store location
        queue<pair<int, int>> q;
        // current group id, start from 2 (0 and 1 already occupied)
        int cur_group_id = 2;
        // current group size
        int cur_group_size = 0;
        //  boundary
        int lenX = grid.size();
        int lenY = grid[0].size();

        // BFS: O(n^2)
        for (int i = 0; i < lenX; i++) {
            for (int j = 0; j < lenY; j++) {
                // only do BFS when is not visited
                if (grid[i][j] != 1) continue;
                // start BFS by pushing one first location
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    int x = cur.first;
                    int y = cur.second;
                    int id = grid[x][y];
                    // not explored yet
                    if (id == 1) {
                        // found an unexplored island, update group size
                        cur_group_size++;
                        // mark the group id
                        grid[x][y] = cur_group_id;
                        // put unvisited island into queue
                        if (x + 1 < lenX && grid[x + 1][y] == 1)
                            q.push({x + 1, y});
                        if (x - 1 >= 0 && grid[x - 1][y] == 1)
                            q.push({x - 1, y});
                        if (y + 1 < lenY && grid[x][y + 1] == 1)
                            q.push({x, y + 1});
                        if (y - 1 >= 0 && grid[x][y - 1] == 1)
                            q.push({x, y - 1});
                    }
                }
                // BFS for a group done, save result and move to next group
                islandArea[cur_group_id] = cur_group_size;
                max_group_size = max(cur_group_size, max_group_size);
                cur_group_id++;
                cur_group_size = 0;
            }
        }
    }

    int getMaxSize(vector<vector<int>>& grid) {
        int ans = max_group_size;
        int lenX = grid.size();
        int lenY = grid[0].size();
        // find '0' and try connect islands: O(n^2)
        for (int i = 0; i < lenX; i++) {
            for (int j = 0; j < lenY; j++) {
                if (grid[i][j] == 0) {
                    int size = 1;
                    unordered_map<int, int> mark;
                    if (i + 1 < lenX) {
                        int id = grid[i + 1][j];
                        size += mark[id] ? 0 : islandArea[id];
                        mark[id] = 1;
                    }
                    if (i - 1 >= 0) {
                        int id = grid[i - 1][j];
                        size += mark[id] ? 0 : islandArea[id];
                        mark[id] = 1;
                    }
                    if (j + 1 < lenY) {
                        int id = grid[i][j + 1];
                        size += mark[id] ? 0 : islandArea[id];
                        mark[id] = 1;
                    }
                    if (j - 1 >= 0) {
                        int id = grid[i][j - 1];
                        size += mark[id] ? 0 : islandArea[id];
                        mark[id] = 1;
                    }
                    ans = max(size, ans);
                }
            }
        }
        return ans;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.size() == 1) return 1;
        getGroupArea(grid);
        return getMaxSize(grid);
    }
};
// @lc code=end
