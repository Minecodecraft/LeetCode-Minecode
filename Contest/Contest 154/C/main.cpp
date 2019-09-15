//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

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
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (k <= 0) return 0;
        int len = arr.size();
        int newlen = len * min(2, k);
        vector<int> cal (newlen);
        for (int i = 0; i < newlen; ++i)
            cal[i] = arr[i % len];

        vector<long long> dp (newlen+1, 0);
        for (int i = 1; i <= newlen; ++i)
            dp[i] = max(dp[i-1], (long long)0) + cal[i-1];
        long long maxx = *max_element(dp.begin(), dp.end());
        long long totsum = accumulate(arr.begin(), arr.end(), 0);

        long long res = maxx;
        if (totsum > 0 && k - 2 > 0)
            res = maxx + totsum * (k-2);
        res %= (long long)(1e9 + 7);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
//        1,2
        1,-2,1
//        -5, 4, -4, -3, 5, -3
    };
//    int k = 2;
    int k = 3;
    int res = sol.kConcatenationMaxSum(arr, k);
    cout << res << endl;
    return 0;
}
