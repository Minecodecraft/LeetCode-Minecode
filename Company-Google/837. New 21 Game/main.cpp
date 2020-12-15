//
//  main.cpp
//  837. New 21 Game
//
//  Created by Jaylen Bian on 12/15/20.
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
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp (K+1, 0.0);
        double factor = 1.0 / W;
        dp[0] = 1.0;
        for (int i = 1; i <= K; ++i) {
            vector<double> tmp (K+1, 0.0);
            for (int j = 1; j <= W; ++j) {
                for (int k = j; k <= min(K+j, W); ++k) {
                    tmp[k] += dp[k-j] * factor;
                }
            }
            swap(dp, tmp);
        }
        return accumulate(dp.begin(), dp.begin() + K + 1, 0.0);
    }
};

int main() {
    Solution sol = Solution();
    int N = 10, K = 1, W = 10;
    double res = sol.new21Game(N, K, W);
    cout << res << endl;
    return 0;
}
