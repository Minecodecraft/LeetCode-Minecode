//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2020/2/22.
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
    int countOrders(int n) {
        long long res = 1;
        int MOD = 1e9+7;
        for (long long i = 1; i <= n; ++i) {
            long long multi = i * (i*2-1) % MOD;
            res *= multi;
            res %= MOD;
        }
        return res % MOD;
    }
};

int main() {
    Solution sol = Solution();
    for (int i = 1; i <= 30; ++i) {
        cout << i << "\t" << sol.countOrders(i) << endl;
    }
    return 0;
}
