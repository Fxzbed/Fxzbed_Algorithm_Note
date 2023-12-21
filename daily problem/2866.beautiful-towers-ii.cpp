#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2866 lang=cpp
 *
 * [2866] Beautiful Towers II
 */

// @lc code=start
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        vector<long long> suf(n), pre(n);
        stack<int> s1, s2;
        for (int i = 0; i < n; i ++) {
            while (!s1.empty() && maxHeights[i] < maxHeights[s1.top()]) {
                s1.pop();
            }
            if (s1.empty()) {
                pre[i] = (long long)(i + 1) * maxHeights[i];
            } else {
                pre[i] = pre[s1.top()] + (long long)(i - s1.top()) * maxHeights[i];
            }
            s1.emplace(i);
        }

        for (int i = n - 1; i >= 0; i --) {
            while (!s2.empty() && maxHeights[i] < maxHeights[s2.top()]) {
                s2.pop();
            }
            if (s2.empty()) {
                suf[i] = (long long)(n - i) * maxHeights[i];
            } else {
                suf[i] = suf[s2.top()] + (long long)(s2.top() - i) * maxHeights[i];
            }
            s2.emplace(i);
            res = max(res, pre[i] + suf[i] - maxHeights[i]);
        }
        return res;
    }
};
// @lc code=end

