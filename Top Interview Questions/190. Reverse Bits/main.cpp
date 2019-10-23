//
//  main.cpp
//  190. Reverse Bits
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
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bt1 (n), bt2 (n);
        bt2.reset();
        for (int i = 0; i < 32; ++i) {
            bt2[32-i-1] = bt1[i];
        }
        return (uint32_t)bt2.to_ulong();
    }
};

int main() {
    Solution sol = Solution();
//    uint32_t n = 43261596;
    uint32_t n = 4294967293;
    uint32_t res = sol.reverseBits(n);
    cout << res << endl;
    return 0;
}
