#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2103 lang=cpp
 * word: distributed rods denotes  
 * [2103] Rings and Rods
 */

// @lc code=start
class Solution {
public:
    // bool isRGB(string rings) {
    //     for (int i = 0; i < rings.size(); i += 2) {

    //     }
    // }
    int rods[100][3] = {0};
    int numRGB[100] = {0};
    int sum = 0;

    inline int getIndex (char& s) {
        if (s == 'R') return 0;
        else if (s == 'G') return 1;
        else if (s == 'B') return 2;
        return -1;
    }

    int countPoints(string rings) {
        int n = rings.size() / 2;
        for (int i = 0, x = 1; x < rings.size(); i += 2, x += 2) {
            char color = rings[i];
            int num = rings[x];

            if (rods[num][getIndex(color)]++ == 0) {
                numRGB[num] ++;
                if (numRGB[num] == 3) {
                    sum ++;
                }
                // rods[num][getIndex(color)] = 1;
            } else {
                continue;
            }
        }
        return sum;  
    }
};
// @lc code=end


