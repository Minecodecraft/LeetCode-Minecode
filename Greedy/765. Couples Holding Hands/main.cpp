//
//  main.cpp
//  765. Couples Holding Hands
//
//  Created by 边俊林 on 2019/11/3.
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
    int minSwapsCouples(vector<int>& row) {
        int sz = row.size();
        UnionFind(sz);
        vector<int> pos (sz, 0);
        for (int i = 0; i < sz; ++i)
            pos[row[i]] = i;
        for (int i = 0; i < sz; ++i) {
            int cur = row[i], cp = cur & 1 ? cur-1 : cur+1;
            int curPair = i/2, cpPair = pos[cp]/2;
            Union(curPair, cpPair);
        }
        return countStep();
    }
    
private:
    vector<int> f;
    
    int countStep() {
        unordered_map<int, int> cnt;
        for (int i = 0; i < f.size(); ++i)
            cnt[Find(i)]++;
        int res = 0;
        for (auto& kv: cnt)
            res += kv.second-1;
        return res;
    }
    
    void UnionFind(int capacity) {
        f = vector<int> (capacity);
        for (int i = 0; i < capacity; ++i)
            f[i] = i;
    }
    
    bool Union(int u, int v) {
        int p1 = Find(u);
        int p2 = Find(v);
        
        if (p1 == p2)
            return false;
        f[p1] = p2;
        // TODO: Use Weighted Union-find
        return true;
    }
    
    int Find(int u) {
        if (f[u] == u)
            return u;
        return f[u] = Find(f[u]);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> row = {
        0, 2, 1, 3
//        3, 2, 0, 1
    };
    int res = sol.minSwapsCouples(row);
    cout << res << endl;
    return 0;
}
