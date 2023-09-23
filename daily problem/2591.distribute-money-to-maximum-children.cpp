#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2591 lang=cpp
 *
 * [2591] Distribute Money to Maximum Children
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < 8 + (children - 1)) {
            if (money < children) return -1;
            return 0;
        } else if (money > children * 8) return children - 1;

        int res = 0;
        money -= children;
        int resTmp = money / 7;
        if (resTmp > children) return children - 1;
        int resLos = money % 7;
        if (resLos != 3) return resTmp;
        else if (children - resTmp == 1 || children == resTmp) return resTmp - 1;
        else return resTmp;

        return (res > 0) ? res : 0;
    }
};
// @lc code=end


