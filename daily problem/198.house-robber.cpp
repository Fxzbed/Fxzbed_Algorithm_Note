#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;

        vector<int> dp;
        dp.resize(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i ++) {
            dp[i] = max((dp[i - 2] + nums[i - 1]), dp[i - 1]);
        }

        return dp[n];
    }
};
// @lc code=end


