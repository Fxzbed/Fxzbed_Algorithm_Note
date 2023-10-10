#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2731 lang=cpp
 *
 * [2731] Movement of Robots
 */

// @lc code=start
class Solution {
public:
    static constexpr long long mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> numsL(n);
        for (int i = 0; i < n; i ++) {
            numsL[i] = 1LL * nums[i] + (s[i] == 'L' ? -d : d);
        }

        sort(numsL.begin(), numsL.end());
        long long res = 0, sum = 0;
        for (long long i = 0; i < n; i ++) {
            res = (res + i * numsL[i] - sum) % mod;
            sum += numsL[i];
        }
        return res;
    }
};
// @lc code=end

