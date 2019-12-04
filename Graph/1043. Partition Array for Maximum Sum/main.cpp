//
//  main.cpp
//  1043. Partition Array for Maximum Sum
//
//  Created by 边俊林 on 2019/12/4.
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
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp (n+1, 0);
        for (int i = 1; i <= n; ++i) {
            int maxx = 0;
            for (int j = 1; j <= K && i - j >= 0; ++j) {
                maxx = max(maxx, A[i-j]);
                dp[i] = max(dp[i], dp[i-j] + maxx * j);
            }
        }
        return dp[n];
    }
};


int main() {

    return 0;
}
