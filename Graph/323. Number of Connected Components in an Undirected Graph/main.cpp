//
//  main.cpp
//  323. Number of Connected Components in an Undirected Graph
//
//  Created by 边俊林 on 2019/12/12.
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> fa (n);
        for (int i = 0; i < n; ++i) fa[i] = i;

        int sz = n;
        for (auto& edge: edges) {
            int pu = Find(fa, edge[0]);
            int pv = Find(fa, edge[1]);
            if (pu != pv) {
                fa[pu] = pv;
                --sz;
            }
        }
        return sz;
    }

private:
    int Find(vector<int>& fa, int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa, fa[u]);
    }
};

int main() {

    return 0;
}
