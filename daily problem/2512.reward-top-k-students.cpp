#include "Fxzbed_algorithms.hpp"
#include <sstream>
using namespace std;
/*
 * @lc app=leetcode id=2512 lang=cpp
 *
 * [2512] Reward Top K Students
 */

// @lc code=start
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        vector<pair<int, int>> rank;
        unordered_map<string, int> feedbackMap;
        for (auto& x : positive_feedback) feedbackMap[x] = 3;
        for (auto& x : negative_feedback) feedbackMap[x] = -1;

        int i = 0;
        for (auto& x : report) {
            int rankSocre = 0;
            stringstream singleWord(x);
            while (singleWord >> x) {
                if (feedbackMap.count(x)) {
                    // cout << x << '|' << endl;
                    rankSocre += feedbackMap[x];            
                } 
            }
            rank.push_back({rankSocre, student_id[i++]});        
        }
        
        sort(rank.begin(), rank.end(), [](pair<int, int>& a, pair<int, int>& b)->bool {
            if (a.first > b.first) return true;
            else if (a.first == b.first) return a.second < b.second;
            return false;
        });

        // for (auto& x : rank) cout << x.first << endl;

        vector<int> res;
        for (int i_ = 0; i_ < k; i_ ++) {
            res.push_back(rank[i_].second);
        }
        return res;
    }
};
// @lc code=end

