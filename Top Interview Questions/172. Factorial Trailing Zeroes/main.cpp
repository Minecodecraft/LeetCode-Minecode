//
//  main.cpp
//  172. Factorial Trailing Zeroes
//
//  Created by 边俊林 on 2019/10/23.
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
    int trailingZeroes(int n) {
        int res = 0;
        for (long i = 5; (n / i) > 0; i *= 5) {
            res += (n / i);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 3;
//    int n = 5;
//    int n = 0;
//    int n = 1808548329;
    int n = 15;
    int res = sol.trailingZeroes(n);
    cout << res << endl;
    return 0;
}
