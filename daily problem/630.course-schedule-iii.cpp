#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=630 lang=cpp
 * 
 * word: duration indicate continuously simultaneously
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto sortSec = [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };
        sort(courses.begin(), courses.end(), sortSec);
        priority_queue<int> pd;

        int rntTime = 0;

        for (auto& x : courses) {
            int duration = x[0];
            int lastDay = x[1];

            rntTime += duration;
            pd.push(duration);

            while (rntTime > lastDay) {
                rntTime -= pd.top();
                pd.pop();
            }
        }

        return pd.size();
    }
};
// @lc code=end


