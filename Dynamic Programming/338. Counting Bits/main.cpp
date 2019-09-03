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
