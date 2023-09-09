#include <vector>
#include <iostream>

using namespace std;

class mapCycleJudge
{
private:

    //@back result
    bool cycleJudge = false;

    //@onPath Node
    vector<bool> onPath;

    //@isVisited Node
    vector<bool> isVisited;

    //@graph saved by [][]
    vector<vector<int>> graph;

public:
    //@construct map by [][]    
    //input : first -> second
    mapCycleJudge(vector<vector<int>>& input, int& num) {
        onPath.resize(num, false);
        isVisited.resize(num, false);
        //@buildGraph
        graph.resize(num);
        for (auto x : input) {
            graph[x[0]].push_back(x[1]);
        }
    }

    void travelNode(int& index) {
        if (onPath[index]) this->cycleJudge = true; //find cycle!

        if (isVisited[index] || this->cycleJudge) return;   //have visited this line || have cycle to exit

        onPath[index] = true;
        isVisited[index] = true;
        for (auto x : graph[index]) 
            travelNode(x);
        
        onPath[index] = false; //return onPath to false because one travel find one cycle!
    }
};