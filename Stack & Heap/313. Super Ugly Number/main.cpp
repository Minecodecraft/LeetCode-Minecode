//
//  main.cpp
//  313. Super Ugly Number
//
//  Created by 边俊林 on 2019/10/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/super-ugly-number/
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int> indexs (len, 0), nums (n, INT_MAX);
        nums[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < len; ++j)
                nums[i] = min(nums[i], nums[indexs[j]] * primes[j]);
            for (int j = 0; j < len; ++j)
                indexs[j] += (nums[i] == primes[j] * nums[indexs[j]]);
        }
        return nums[n-1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> primes = {
//        2, 7, 13, 19
//        2, 3, 5
        3,5,7,11,19,23,29,41,43,47
    };
    int n = 15;
//    int n = 2;
//    int n = 12;
    int res = sol.nthSuperUglyNumber(n, primes);
    cout << res << endl;
    return 0;
}
