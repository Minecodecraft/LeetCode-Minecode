//
//  main.cpp
//  204. Count Primes
//
//  Created by 边俊林 on 2019/10/24.
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
// Solution 1: Sieve of Eratosthenes, O(nloglogn)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> check (n, false);
        vector<int> primes (n, false);
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (!check[i])
                primes[cnt++] = i;
            for (int j = 0; j < cnt; ++j) {
                if (i * primes[j] > n)
                    break;
                check[i * primes[j]] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 10;
//    int n = 2;
//    int n = 5;
    int n = 10000;
    int res = sol.countPrimes(n);
    cout << res << endl;
    return 0;
}
