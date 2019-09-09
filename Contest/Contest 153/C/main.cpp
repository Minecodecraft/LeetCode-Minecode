//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/9/8.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

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
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp (n, vector<int> (2, INT_MIN));
        int maxx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            dp[i][0] = arr[i];
            if (i > 0) {
                dp[i][0] = max(dp[i][0], dp[i-1][0] + arr[i]);
                dp[i][1] = max(dp[i][1], dp[i-1][0]);
                if (dp[i-1][1] != INT_MIN)
                    dp[i][1] = max(dp[i][1], dp[i-1][1] + arr[i]);
            }
            maxx = max(maxx, max(dp[i][0], dp[i][1]));
        }
        return maxx;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
//        1,-2,0,3
//        1, -2, -2, 3
//        -50, -10
        2,9,-4,7,-6,5,8,-5,-6,9
    };
    int res = sol.maximumSum(arr);
    cout << res << endl;
    return 0;
}
