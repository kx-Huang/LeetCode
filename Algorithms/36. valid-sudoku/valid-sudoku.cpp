/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * Method: Iterative Traversal
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row, col, box for storing number information: O(n^2)
        //
        //    col 0   1   2   3   4   5   6   7   8
        // row 0  *   *   * | *   *   * | *   *   *
        //     1  * box 0 * | * box 1 * | * box 2 *
        //     2  *   *   * | *   *   * | *   *   *
        //        --------- + --------- + ---------
        //     3  *   *   * | *   *   * | *   *   *
        //     4  * box 3 * | * box 4 * | * box 5 *
        //     5  *   *   * | *   *   * | *   *   *
        //        --------- + --------- + ---------
        //     6  *   *   * | *   *   * | *   *   *
        //     7  * box 6 * | * box 7 * | * box 8 *
        //     8  *   *   * | *   *   * | *   *   *
        //
        // example: if row[i][num] is true, then num+1 exists in row i
        // example: if col[j][num] is true, then num+1 exists in col j
        // example: if box[k][num] is true, then num+1 exists in box k
        //
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        // construct row/col/box and check if valid or not: O(n^2)
        // if a pair of numbers are conflict:
        // 1. add first number to row/col/box
        // 2. compare second number with the first number in row/col/box
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int num = c - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    // found duplicates in the same row/col/box
                    if (row[i][num] || col[j][num] || box[k][num]) return false;
                    // add number to row/col/box for future comparison
                    row[i][num] = true;
                    col[j][num] = true;
                    box[k][num] = true;
                }
            }
        }
        return true;
    }
};
// @lc code=end
