#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=207 lang=cpp
 *  word : labeled requisites prerequisites indicates 
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    
    vector<bool> onPath;
    vector<bool> visited;
    bool result = true;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        onPath.resize(numCourses, false);
        visited.resize(numCourses, false);

        buildGraph(prerequisites, graph);
        // for (auto x : graph) {
        //     cout << x[0] << ' ' << x[1] << endl;
        // }
        for (int i = 0; i < numCourses; i ++) {
            travelGraph(graph, i);
            if (!result) {
                return result;
            }
        }
        return result;
    }

    void buildGraph(vector<vector<int>>& prerequisites, vector<vector<int>>& graph) {
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        return;
    }

    void travelGraph(vector<vector<int>>& graph, int& index) {
        if (onPath[index] || !result) {        //cycle
            result = false;
        }

        if (visited[index] || !result) return; //have traveled this line


        onPath[index] = true;
        visited[index] = true;
        for (auto x : graph[index])
            travelGraph(graph, x);
        onPath[index] = false;

    }
};
// @lc code=end


