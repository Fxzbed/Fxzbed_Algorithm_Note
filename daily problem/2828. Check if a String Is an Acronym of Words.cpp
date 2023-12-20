#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;
        int idx = 0;
        for (auto &str : words) {
            if (str[0] != s[idx ++]) return false;
        }
        return true;
    }
};