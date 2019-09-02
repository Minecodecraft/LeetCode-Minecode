//
//  main.cpp
//  338. Counting Bits
//
//  Created by 边俊林 on 2019/9/2.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/counting-bits/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
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
    vector<int> countBits(int num) {
        vector<int> res = {0};
        int level = 0, idx = 1;
        while (idx <= num) {
            int end = min(num, idx + (1 << level) - 1);
            for (; idx <= end; ++idx) {
                res.push_back(res[idx - (1 << level)] + 1);
            }
            ++level;
        }
        return res;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
//    int n = 2;
    int n = 5;
    auto res = sol.countBits(n);
    printVector(res);
    return 0;
}
