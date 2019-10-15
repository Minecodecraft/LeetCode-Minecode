//
//  main.cpp
//  128. Longest Consecutive Sequence
//
//  Created by 边俊林 on 2019/10/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        UnionFind(n);
        for (int i = 0; i < n; ++i)
            idx[nums[i]] = i;
        for (int i = 0; i < n; ++i) {
            if (idx.count(nums[i] - 1) > 0)
                Union(idx[nums[i]-1], idx[nums[i]]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, sz[i]);
        }
        return res;
    }

private:
    vector<int> p;
    vector<int> sz;
    unordered_map<int, int> idx;

    void UnionFind(int capa) {
        p = vector<int> (capa);
        sz = vector<int> (capa, 1);
        for (int i = 0; i < capa; ++i)
            p[i] = i;
    }

    bool Union(int u, int v) {
        int pu = Par(u);
        int pv = Par(v);
        if (pu == pv) return false;

        if (sz[pu] >= sz[pv]) {
            p[pv] = pu;
            sz[pu] += sz[pv];
        } else {
            p[pu] = pv;
            sz[pv] += sz[pu];
        }
        return true;
    }

    bool Find(int u, int v) {
        return Par(u) == Par(v);
    }

    int Par(int i) {
        while (p[i] != i) {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        100, 4, 200, 1, 3, 2
        0, -1
    };
    int res = sol.longestConsecutive(nums);
    cout << res << endl;
    return 0;
}
