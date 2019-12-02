//
//  main.cpp
//  839. Similar String Groups
//
//  Created by 边俊林 on 2019/12/1.
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
    int numSimilarGroups(vector<string>& A) {
        int sz = A.size();
        UnionFind(sz);

        for (int i = 0; i < sz-1; ++i) {
            for (int j = i+1; j < sz; ++j) {
                if (canMerge(A, i, j))
                    Union(i, j);
            }
        }
        int res = 0;
        unordered_set<int> vis;
        for (int i = 0; i < sz; ++i) {
            int p = Find(i);
            if (vis.count(p) == 0) {
                vis.insert(p);
                ++res;
            }
        }
        return res;
    }

private:
    vector<int> fa;

    void UnionFind(int sz) {
        fa = vector<int> (sz);
        for (int i = 0; i < sz; ++i) fa[i] = i;
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        fa[pu] = fa[pv];
        return true;
    }

    int Find(int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa[u]);
    }

    bool canMerge(vector<string>& A, int l, int r) {
        int dif = 0;
        for (int i = 0; i < A[l].length(); ++i)
                if (A[l][i] != A[r][i] && ++dif > 2)
                    return false;
        return true;
    }
};

int main() {

    return 0;
}
