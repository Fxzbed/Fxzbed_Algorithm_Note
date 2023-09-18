#include "Fxzbed_algorithms.hpp"

using namespace std;
/*
 * @lc app=leetcode id=LCP 50 lang=cpp
 * 
 * 
 */

class Solution {
public:
    int gemF, gemS;

    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (int i = 0; i < operations.size(); i ++) {
            gem[operations[i][1]] += gem[operations[i][0]] / 2;
            gem[operations[i][0]] -= gem[operations[i][0]] / 2;
        }

        int max = 0, min = 10e3;
        for (auto& x : gem) {
            if (x > max) max = x;
            if (x < min) min = x;
        }

        return max - min;
    }
};

// @lc code=end