//
//  main.cpp
//  1168. Optimize Water Distribution in a Village
//
//  Created by 边俊林 on 2019/12/11.
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        fa = vector<int> (n+1);
        for (int i = 0; i < n+1; ++i) fa[i] = i;
        
        for (int i = 1; i <= n; ++i)
            pipes.push_back({0, i, wells[i-1]});
        sort(pipes.begin(), pipes.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        int res = 0;
        for (auto& pipe: pipes) {
            if (Union(pipe[0], pipe[1]))
                res += pipe[2];
        }
        return res;
    }
    
private:
    vector<int> fa;
    
    bool Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv) return false;
        fa[pu] = pv;
        return true;
    }
    
    int Find(int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa[u]);
    }
};

int main() {

    return 0;
}
