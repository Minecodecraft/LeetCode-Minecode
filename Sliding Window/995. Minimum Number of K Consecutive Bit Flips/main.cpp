//
//  main.cpp
//  995. Minimum Number of K Consecutive Bit Flips
//
//  Created by 边俊林 on 2019/9/24.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> Q;
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != 1-(Q.size() % 2)) {
                if (i + K - 1 >= A.size())
                    return -1;
                Q.push(i + K - 1);
                ++res;
            }
            while (!Q.empty() && Q.front() <= i) Q.pop();
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        0, 1, 0
//        1, 1, 0
        0,0,0,1,0,1,1,0
    };
//    int K = 1;
//    int K = 2;
    int K = 3;
    int res = sol.minKBitFlips(nums, K);
    cout << res << endl;
    return 0;
}
