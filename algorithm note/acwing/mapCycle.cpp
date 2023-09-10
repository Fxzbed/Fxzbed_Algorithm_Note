#include <vector>
#include <iostream>
#include <algorithm>

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

    //@topologySort vector
    vector<int> topologyArray;

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
   
    void topologySort(int& index) {
        topologySort_(index);
        reverseSort();
        cout << "TopologySort result is : \n";
        for (auto& x : this->topologyArray) cout << x << ' ';
        putchar('\n');
    }

private:
    void topologySort_(int& index) {
        if (onPath[index]) this->cycleJudge = true; //find cycle!

        if (isVisited[index] || this->cycleJudge) return;   //have visited this line || have cycle to exit

        onPath[index] = true;
        isVisited[index] = true;
        for (auto x : graph[index]) 
            travelNode(x);
        topologyArray.push_back(index);
        onPath[index] = false; //return onPath to false because one travel find one cycle!
    }

    inline void reverseSort() {reverse(this->topologyArray.begin(), this->topologyArray.end());}


};