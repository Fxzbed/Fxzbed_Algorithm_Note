#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2578 lang=cpp
 *
 * [2578] Split With Minimum Sum
 */

// @lc code=start


class Solution {
public:
    int splitNum(int num) {
        int size1, size2, res = 0;

        vector<int> numSingle;
        while (num) {
            int x = num % 10;
            num /= 10;
            numSingle.push_back(x);
        }

        size1 = numSingle.size() / 2;
        size2 = numSingle.size() - size1;

        sort(numSingle.begin(), numSingle.end());

        // cout << numSingle.size() << endl;

        int index = numSingle.size() - 1;
        for (int i = 0; i < size2; i ++) {
            if (index < 0) return res;
            res += numSingle[index--] * pow(10, i);
            if (index < 0) return res;
            res += numSingle[index--] * pow(10, i);
        }

        return res;
    }
};
// @lc code=end

