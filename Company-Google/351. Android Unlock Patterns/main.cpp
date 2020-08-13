//
//  main.cpp
//  351. Android Unlock Patterns
//
//  Created by Jaylen Bian on 8/13/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
    int helper(bool* vis, int (&skip)[10][10], int cur, int remain) {
        if (remain == 0)
            return 1;

        int cnt = 0;
        vis[cur] = true;
        for (int i = 1; i <= 9; ++i) {
            if (!vis[i] && (skip[cur][i] == 0 || vis[skip[cur][i]]))
                cnt += helper(vis, skip, i, remain-1);
        }
        vis[cur] = false;
        return cnt;
    }
public:
    int numberOfPatterns(int m, int n) {
        int skip[10][10];
        memset(skip, 0, 10*10*sizeof(int));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;

        int res = 0;
        bool vis[10] = {false};
        for (int i = m; i <= n; ++i) {
            res += helper(vis, skip, 1, i-1) * 4;
            res += helper(vis, skip, 2, i-1) * 4;
            res += helper(vis, skip, 5, i-1);
        }
        return res;
    }
};

int main() {

    return 0;
}
