//
//  main.cpp
//  1135. Connecting Cities With Minimum Cost
//
//  Created by 边俊林 on 2019/12/10.
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
    int minimumCost(int n, vector<vector<int>>& conns) {
        UnionFind(n);
        sort(conns.begin(), conns.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        int sum = 0;
        for (auto& conn: conns) {
            if (Union(conn[0], conn[1]))
                sum += conn[2];
        }
        return getSize() == 1 ? sum : -1;
    }

private:
    vector<int> fa;
    int _size;

    int getSize() {
        return _size;
    }

    void UnionFind(int sz) {
        fa = vector<int> (sz+1);
        for (int i = 1; i <= sz; ++i) fa[i] = i;
        _size = sz;
    }

    bool Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv) return false;
        fa[pu] = pv;
        --_size;
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
