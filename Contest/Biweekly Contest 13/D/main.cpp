//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/11/16.
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
    int numberOfWays(int num_people) {
        int np = num_people / 2;
        vector<long long> dp (np+1, 1);
        for (int i = 2; i <= np; ++i) {
            long long sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += (dp[j] * dp[i-j-1]) % MOD;
            }
            sum %= MOD;
            dp[i] = sum;
        }
        return dp[np];
    }
    
    long MOD = 1e9+7;
};

int main() {
    Solution sol = Solution();
//    int n = 4;
    int n = 8;
    int res = sol.numberOfWays(n);
    cout << res << endl;
    return 0;
}
