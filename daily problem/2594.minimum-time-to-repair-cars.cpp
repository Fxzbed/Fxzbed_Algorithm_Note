/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */
// @lc code=start

/*
Minimum Time to Repair Cars
Category	Difficulty	Likes	Dislikes
algorithms	Medium (43.07%)	465	20

You are given an integer array ranks representing the ranks of some mechanics. ranks is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

 

Example 1:

Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
Example 2:

Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
 

Constraints:

1 <= ranks.length <= 105
1 <= ranks[i] <= 100
1 <= cars <= 106
*/
#include "Fxzbed_algorithms.hpp"

using namespace std;

// class Solution {
// public:
//     long long singleRepair(int& rank, int n) {return rank * pow(n, 2);}

//     void loopAdd(vector<int>& ranks, vector<pair<int, int>>& machanic_rankpair, int& cars, int& maxTime, int& carsRepaired) {
//         for (int i = 0; i < ranks.size(); i ++) {
//             if (ranks[i] > cars) continue;

//             carsRepaired ++;
            
//             if (i != 0) 
//                 machanic_rankpair[i].first = singleRepair(ranks[i], ++machanic_rankpair[i].second);
//             else 
//                 machanic_rankpair.push_back({singleRepair(ranks[i], 1), 1});

//             maxTime = maxTime < machanic_rankpair[i].first ? machanic_rankpair[i].first : maxTime;

//             if (carsRepaired >= cars) return;
//         }       
//     }

//     findAdd(vector<int>& ranks, vector<pair<int, int>>& machanic_rankpair, int& maxTime, int& carsRepaired, int& cars) {

//     }

//     pair<int, int> minFind(vector<pair<int, int>>& lists) {
//         pair<int, int> min = {0, lists[0].first};    //index : times
//         for (int i = 0; i < lists.size(); i ++) {
//             if (lists[i].first < min.second) {
//                 min.first = i;
//                 min.second = lists[i].first;
//             }
//         }
//         return min;
//     }

//     long long repairCars(vector<int>& ranks, int cars) {
//         vector<pair<int, int>> machanic_rankpair; // time : cars_repaired
//         int maxTime = 0, carsRepaired = 0;
//         long long timeSum = 0;
//         pair<int, int> minPair; 

//         sort(ranks.begin(), ranks.end());

//         while (carsRepaired < cars) {
//             loopAdd(ranks, machanic_rankpair, cars, maxTime, carsRepaired);
//              if (carsRepaired >= cars) maxTime;
//             minPair = minFind(machanic_rankpair);
            
//             while (machanic_rankpair[minPair.first].first < maxTime) {
//                 machanic_rankpair[minPair.first].first = singleRepair(ranks[minPair.first], ++machanic_rankpair[minPair.first].second);
//             }
//         }
//     }
// };


//
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long right = (long)ranks[0] * cars * cars, left = 0, mid = 0;

        while (left < right) {
            mid = right + left >> 1;
            long long carsRped = 0;
            for (auto& x : ranks) 
                carsRped += sqrt(mid / x);
            if (carsRped >= cars) right = mid;
            else left = mid + 1; 
        }

        return left;
    }
};
// @lc code=end

