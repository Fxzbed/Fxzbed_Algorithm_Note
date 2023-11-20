/*
 * @lc app=leetcode id=2656 lang=cpp
 *
 * [2656] Maximum Sum With Exactly K Elements 
 */
#include "Fxzbed_algorithms.hpp"
using namespace std;
// @lc code=start
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = nums[0], res = 0;
        for (auto& x : nums) m = max(x, m);

        while (k --) res += m ++; 
        return res;
    }
};
// @lc code=end

