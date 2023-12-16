#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> an(1010);
        int n = cost.size();
        an[0] = 0;
        an[1] = 0;
        for (int i = 2; i < n + 1; i ++) {
            an[i] = min(an[i - 1] + cost[i - 1], an[i - 2] + cost[i - 2]);
        }
        return an[n];
    }
};
// @lc code=end

