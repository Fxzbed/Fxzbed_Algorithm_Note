#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2562 lang=cpp
 *
 * [2562] Find the Array Concatenation Value
 */

// @lc code=start
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();

        int left = 0;
        int right = n - 1;
        while (!(left - right == 1)) {
            if (left - right == 0) {
                res += nums[left]; 
                return res;
            }
            res += addFuc(left++, right--, nums);
        }
        return res;
    }

    long long addFuc(int l, int r, vector<int>& nums) {
        int tmp = log10(nums[r]) + 1;
        if (l == r) return nums[l];
        else {
            return (nums[l] * pow(10, tmp) + nums[r]) * 1ll;
        }
    }
};
// @lc code=end


