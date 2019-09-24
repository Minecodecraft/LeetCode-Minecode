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
// Solution 1: Normal Solution
// O(n) Time Complexity O(n) Space Complexity
/*
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> Q;
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == Q.size() % 2) {
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
 */

// Solution 2: Optimize memory usage
// O(n) Time Complexity O(1) Space Complexity
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, flips = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == (flips & 1)) {
                if (i + K - 1 >= A.size()) return -1;
                A[i] -= 2;
                ++flips;
                ++res;
            }
            while (i-K+1 >= 0 && A[i - K + 1] < 0) {
                --flips;
                A[i - K + 1] += 2;
            }
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
