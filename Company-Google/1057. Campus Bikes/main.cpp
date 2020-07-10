//
//  main.cpp
//  1057. Campus Bikes
//
//  Created by Jaylen Bian on 7/10/20.
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
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& ws, vector<vector<int>>& bs) {
        const int MAXN = 2010;
        vector<vector<pair<int, int>>> bkt (MAXN);
        int n = ws.size(), m = bs.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dis = abs(ws[i][0] - bs[j][0]) + abs(ws[i][1] - bs[j][1]);
                bkt[dis].push_back({i, j});
            }
        }

        vector<bool> visb (m, false);
        vector<int> res (n, -1);
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < bkt[i].size(); ++j) {
                auto& pir = bkt[i][j];
                if (!visb[pir.second] && res[pir.first] == -1) {
                    visb[pir.second] = true;
                    res[pir.first] = pir.second;
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
