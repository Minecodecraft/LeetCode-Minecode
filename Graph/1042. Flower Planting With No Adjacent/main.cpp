//
//  main.cpp
//  1042. Flower Planting With No Adjacent
//
//  Created by 边俊林 on 2019/12/4.
//  Copyright © 2019 边俊林. All rights reserved.
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
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> color (N, 0);
        vector<vector<int>> g (N);
        for (auto& path: paths) {
            g[path[0]-1].push_back(path[1]-1);
            g[path[1]-1].push_back(path[0]-1);
        }
        for (int i = 0; i < N; ++i) {
            vector<bool> colors (5, true);
            for (auto& neg: g[i]) colors[color[neg]] = false;
            for (int tar = 1; tar <= 4; ++tar)
                if (colors[tar]) {
                    color[i] = tar; break;
                }
        }
        return color;
    }
};

int main() {

    return 0;
}
