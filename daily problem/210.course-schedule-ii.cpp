#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> line;
    vector<bool> onPath;
    vector<bool> visited;
    bool isCycle = false;

    void buildGraph(vector<vector<int>>& prerequisites, vector<vector<int>>& graph, int& numCourses) {
        onPath.resize(numCourses, false);
        visited.resize(numCourses, false);
        graph.resize(numCourses);
        for (auto& x : prerequisites) {
            graph[x[1]].push_back(x[0]);
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {for (int i = 0; i < numCourses; i ++) line.push_back(i); return line;};

        vector<vector<int>> graph;
        buildGraph(prerequisites, graph, numCourses);

        for (int i = 0; i < numCourses; i ++) {
            travelNode(graph, i);
        }
        if (isCycle) return {};

        reverse(line.begin(), line.end());
        // vector<int> res(numCourses);
        return line;
    }

    //  travel node x -> graph[x][0]
    void travelNode(vector<vector<int>>& graph, int& x) {
        if (onPath[x]) {
            isCycle = true;
        }

        if (visited[x] || isCycle) return;
        
        onPath[x] = true;
        visited[x] = true;
        for (auto& i : graph[x])  {
            travelNode(graph, i);
        }

        line.push_back(x);
        onPath[x] = false;
    }
};
// @lc code=end


