//
//  main.cpp
//  464. Can I Win
//
//  Created by 边俊林 on 2019/9/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/can-i-win/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int m = maxChoosableInteger, d = desiredTotal;
        int sum = m*(m+1)/2;
        if (m >= d) return true;
        if (sum < d) return false;
        if (sum == d) return m & 1;
        return backtrack(m, d, 0);
    }

private:
    unordered_map<int, bool> vis;

    bool backtrack(int m, int d, int bits) {
        if (d <= 0) return false;
        if (vis.count(bits) > 0)
            return vis[bits];
        for (int i = 0; i < m; ++i) {
            if (bits & (1 << i)) continue;
            if (!backtrack(m, d - i - 1, bits | (1 << i)))
                return vis[bits] = true;
        }
        return vis[bits] = false;
    }
};

int main() {

    return 0;
}
