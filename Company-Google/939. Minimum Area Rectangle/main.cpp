//
//  main.cpp
//  939. Minimum Area Rectangle
//
//  Created by Jaylen Bian on 8/7/20.
//  Copyright © 2020 边俊林. All rights reserved.
//

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
// Solution 1: Best
/*
class Solution {

    int idx(int x, int y) {
        return x * 40001 + y;
    }

public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        unordered_set<int> ext;
        for (auto& pt: points) {
            mp[pt[0]].insert(pt[1]);
            ext.insert(idx(pt[0], pt[1]));
        }
        int res = INT_MAX;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int x1 = it->first;
            auto& st = it->second;
            for (auto y1it = st.begin(); y1it != st.end(); ++y1it) {
                int y1 = *y1it;
                for (auto y2it = next(y1it); y2it != st.end(); ++y2it) {
                    int y2 = *y2it;
                    for (auto nit = next(it); nit != mp.end(); ++nit) {
                        int x2 = nit->first;
                        if (ext.count(idx(x2, y1)) && ext.count(idx(x2, y2)))
                            res = min(res, abs((x2-x1) * (y2-y1)));
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
 */

// Solution 2: Not the best, but it's also a good way.
class Solution {
    int idx(int x, int y) {
        return x * 40001 + y;
    }
public:
    int minAreaRect(vector<vector<int>>& pts) {
        unordered_set<int> ext;
        for (auto& pt: pts)
            ext.insert(idx(pt[0], pt[1]));
        int res = INT_MAX;
        for (int i = 0; i < pts.size(); ++i) {
            for (int j = i+1; j < pts.size(); ++j) {
                int x1 = pts[i][0], x2 = pts[j][0];
                int y1 = pts[i][1], y2 = pts[j][1];
                if (x1 == x2 || y1 == y2)
                    continue;
                if (ext.count(idx(x1, y2))
                    && ext.count(idx(x2, y1))) {
                    res = min(res, abs((x2-x1) * (y2-y1)));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main() {

    return 0;
}
