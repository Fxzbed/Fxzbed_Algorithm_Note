#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=2525 lang=cpp
 *
 * [2525] Categorize Box According to Criteria
 */

// @lc code=start
class Solution {
public:
    const int N = 1e4;
    string categorizeBox(int length, int width, int height, int mass) {
        auto isBulky = [&]() -> bool {
          if (length >= N || width >= N || height >= N || (1ll * length * width * height) >= 1e9) {
            return true;
          }
          return false;
        };

        auto isHeavy = [&]() -> bool {
          return mass >= 100 ? true : false;
          return true;
        };

        bool isBulky_ = isBulky();
        bool isHeavy_ = isHeavy();

        if (isBulky_ && isHeavy_) return "Both";
        if (isBulky_ && !isHeavy_) return "Bulky";
        if (!isBulky_ && isHeavy_) return "Heavy";
        if (!isBulky_ && !isHeavy_) return "Neither"; 

        return "";
    }
};
// @lc code=end

