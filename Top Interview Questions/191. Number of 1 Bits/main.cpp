//
//  main.cpp
//  191. Number of 1 Bits
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
    int hammingWeight(uint32_t n) {
        long mask = 1, cnt = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & mask) cnt++;
            mask <<= 1;
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    uint32_t n = 00000000000000000000000010000000;
    int res = sol.hammingWeight(n);
    cout << res << endl;
    return 0;
}
