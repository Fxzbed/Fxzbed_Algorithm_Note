#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2596 lang=cpp
 *
 * [2596] Check Knight Tour Configuration
 */

// @lc code=start
class Solution {
public:
    vector<array<int, 2>> moveLine;

    void initStep(const int&& n, vector<vector<int>>& grid) {
        moveLine.resize(n * n);

        for (int x = 0; x < n; x ++) {
            for (int y = 0; y < n; y ++) {
                moveLine[grid[x][y]] = {x, y};
            }
        }
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        initStep(grid.size(), grid);

        for (int i = 1; i < moveLine.size(); i ++) {
            int TmpX = abs(moveLine[i][0] - moveLine[i - 1][0]) + abs(moveLine[i][1] - moveLine[i - 1][1]);
            if (TmpX != 3) return false; 
        }

        return true;
    }
};
// @lc code=end


