//
//  main.cpp
//  Contest 164
//
//  Created by 边俊林 on 2019/11/24.
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
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp (2, vector<int> (arrLen + 10, 0));

        int type = 0;
        dp[type][1] = 1;
        for (int i = 1; i <= steps; ++i) {
            type = 1-type;
            for (int j = 1; j <= min(steps-i+2, arrLen); ++j) {
                long long cnt = (long long)dp[1-type][j-1] + (long long)dp[1-type][j] + (long long)dp[1-type][j+1];
                cnt = cnt % ((long long)1e9+7);
                dp[type][j] = cnt;
            }
        }

        return dp[type][1];
    }
};

int main() {
    Solution sol = Solution();
//    int s = 3, a = 2;
//    int s = 2, a = 4;
//    int s = 4, a = 2;
    int s = 500, a = 1000000;
    int res = sol.numWays(s, a);
    cout << res << endl;
    return 0;
}
