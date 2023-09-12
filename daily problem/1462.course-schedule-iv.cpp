#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> matrixQuery(numCourses, vector<bool>(numCourses, false));
        vector<int> indgree(numCourses, 0);
        vector<bool> resultVec;
        vector<vector<int>> graph(numCourses);

        for (auto& x : prerequisites) {
            indgree[x[1]]++;
            graph[x[0]].push_back(x[1]);
        }

        queue<int> zeroIndgree;
        for (int x = 0; x < numCourses; x ++) {
            if (indgree[x] == 0) zeroIndgree.push(x);
        }

        while (!zeroIndgree.empty()) {
            auto cur = zeroIndgree.front();
            zeroIndgree.pop();

            for (auto& x : graph[cur]) {
                matrixQuery[cur][x] = true;
                for (int i = 0; i < numCourses; i ++) {
                    matrixQuery[i][x] = matrixQuery[i][cur] | matrixQuery[i][x];
                }

                indgree[x] --;
                if (indgree[x] == 0) zeroIndgree.push(x);
            }
        }

        for (auto x : queries) 
            resultVec.push_back(matrixQuery[x[0]][x[1]]);
        return resultVec;
    }
};
// @lc code=end


