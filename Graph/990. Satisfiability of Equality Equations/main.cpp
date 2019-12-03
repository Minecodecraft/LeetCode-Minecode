//
//  main.cpp
//  990. Satisfiability of Equality Equations
//
//  Created by 边俊林 on 2019/12/3.
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
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) fa[i] = i;
        vector<int> neg;
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '!') neg.push_back(i);
            else Union(equations[i][0]-'a', equations[i][3]-'a');
        }
        for (int idx: neg) {
            int l = equations[idx][0]-'a', r = equations[idx][3]-'a';
            if (Find(l) == Find(r)) return false;
        }
        return true;
    }

private:
    vector<int> fa = vector<int> (26);

    void Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu != pv) fa[pu] = pv;
    }

    int Find(int u) {
        if (fa[u] == u) return u;
        return fa[u] = Find(fa[u]);
    }
};

int main() {

    return 0;
}
