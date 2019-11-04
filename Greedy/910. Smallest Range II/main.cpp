//
//  main.cpp
//  910. Smallest Range II
//
//  Created by 边俊林 on 2019/11/3.
//  Copyright © 2019 边俊林. All rights reserved.
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
    int smallestRangeII(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int n = A.size(), lmin = A[0]+K, rmax = A[n-1]-K;
        int mindif = A[n-1] - A[0];
        for (int i = 0; i < n-1; ++i) {
            int maxval = max(rmax, A[i]+K), minval = min(lmin, A[i+1]-K);
            mindif = min(mindif, maxval-minval);
        }
        return mindif;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> a = {
//        1
//        0, 10
        1, 3, 6
//        7,8,8
    };
//    int k = 0;
//    int k = 2;
    int k = 3;
//    int k = 5;
    int res = sol.smallestRangeII(a, k);
    cout << res << endl;
    return 0;
}
