/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 *
 * Method: Dynamic Programming
 * Data Structure: Array
 * Remarks: Please refer to README.md for detailed explanation
 *
 */

// @lc code=start
class Solution {
private:
    int n, m;
    vector<string> pizza;
    long long int P = 1e9 + 7;
    long long int g[55][55];
    long long int f[55][55][15];

    int dp(int r, int c, int l) {
        if (f[r][c][l] != -1) return f[r][c][l];

        if (l == 0) {
            f[r][c][l] = g[r][c] > 0 ? 1 : 0;
            return f[r][c][l];
        }

        f[r][c][l] = 0;

        // cut horizontally to [row, i-1] [i, n-1]
        for (int i = r + 1; i < n; i++) {
            if (g[r][c] - g[i][c] > 0 && g[i][c] >= l) {
                f[r][c][l] = (f[r][c][l] + dp(i, c, l - 1)) % P;
            }
        }

        // cut vertically to [col, j-1] [j, m-1]
        for (int j = c + 1; j < m; j++) {
            if (g[r][c] - g[r][j] > 0 && g[r][j] >= l)
                f[r][c][l] = (f[r][c][l] + dp(r, j, l - 1)) % P;
        }

        return f[r][c][l];
    }

public:
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].length();
        this->pizza = pizza;
        memset(g, 0, sizeof(g));
        memset(f, -1, sizeof(f));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                g[i][j] = g[i][j + 1];
                for (int l = i; l < n; l++) g[i][j] += (pizza[l][j] == 'A');
            }
        }

        return dp(0, 0, k - 1);
    }
};
// @lc code=end
