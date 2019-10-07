//
//  main.cpp
//  451. Sort Characters By Frequency
//
//  Created by 边俊林 on 2019/10/7.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/sort-characters-by-frequency/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for (auto &ch: s) hash[ch]++;
        vector<pair<char, int>> vec;
        for (auto &item: hash) vec.push_back(make_pair(item.first, item.second));
        auto cmp = [] (pair<char, int>& a, pair<char, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second >= b.second;
        };
        sort(vec.begin(), vec.end(), cmp);
        string res = "";
        for (auto &elem: vec)
            res += string(elem.second, elem.first);
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "tree";
    string s = "cccaaa";
    string res = sol.frequencySort(s);
    cout << res << endl;
    return 0;
}
