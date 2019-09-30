//
//  main.cpp
//  218. The Skyline Problem
//
//  Created by 边俊林 on 2019/9/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> points;
        for (int i = 0; i < buildings.size(); ++i) {
            points.insert({buildings[i][0], -buildings[i][2]});
            points.insert({buildings[i][1], buildings[i][2]});
        }
        pair<int, int> currp = {0, 0};
        multiset<int> height = {0};
        vector<vector<int>> res;
        for (auto it = points.begin(); it != points.end(); ++it) {
            if (it->second < 0) height.insert(-it->second);
            else height.erase(height.find(it->second));
            if (currp.second != *height.rbegin()) {
                currp.first = it->first;
                currp.second = *height.rbegin();
                res.push_back({currp.first, currp.second});
            }
        }
        return res;
    }
};


int main() {
    Solution sol = Solution();
    vector<vector<int>> buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
    };
    auto res = sol.getSkyline(buildings);
    cout << res.size() << endl;
    return 0;
}
