//
//  main.cpp
//  1136. Parallel Courses
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
    int minimumSemesters(int n, vector<vector<int>>& relas) {
        vector<vector<int>> g (n+1);
        vector<int> ind (n+1, 0);
        for (auto& rela: relas) {
            ind[rela[1]]++;
            g[rela[0]].push_back(rela[1]);
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (ind[i] == 0) q.push(i);

        int res = 0;
        while (q.size()) {
            ++res;
            int sz = q.size();
            while (sz--) {
                int idx = q.front(); q.pop();
                for (auto it = g[idx].begin(); it != g[idx].end(); ++it) {
                    ind[*it]--;
                    if (ind[*it] == 0) q.push(*it);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            if (ind[i] > 0) return -1;
        return res;
    }
};

int main() {

    return 0;
}
