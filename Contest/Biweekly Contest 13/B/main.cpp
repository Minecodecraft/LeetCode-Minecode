//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/11/16.
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
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> par;
        for (int i = 0; i < regions.size(); ++i) {
            auto& reg = regions[i];
            for (int j = (int)reg.size()-1; j > 0; --j) {
                par[reg[j]] = reg[0];
            }
        }
        
        unordered_set<string> vis1;
        while (true) {
            vis1.insert(region1);
            if (par.count(region1) == 0) break;
            region1 = par[region1];
        }
        string res = region2;
        while (true) {
            if (vis1.count(region2) > 0)
                return region2;
            if (par.count(region2) == 0) break;
            region2 = par[region2];
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<string>> mat = {
        {"Earth","North America","South America"},
        {"North America","United States","Canada"},
        {"United States","New York","Boston"},
        {"Canada","Ontario","Quebec"},
        {"South America","Brazil"}
    };
    string r1 = "Quebec", r2 = "New York";
    string res = sol.findSmallestRegion(mat, r1, r2);
    cout << res << endl;
    return 0;
}
