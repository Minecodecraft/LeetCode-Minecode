//
//  main.cpp
//  562. Longest Line of Consecutive One in Matrix
//
//  Created by Jaylen Bian on 1/3/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
// Solution 1: 4-dimension array
// O(mn) time complexity, O(mn) space complexity
/*
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size(), n = m == 0 ? 0 : M[0].size();
        vector<vector<vector<int>>> dp (m, vector<vector<int>> (n, vector<int>(4, 0)));

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j]) {
                    dp[i][j][0] = j == 0 ? 1 : dp[i][j-1][0] + 1;
                    dp[i][j][1] = i == 0 ? 1 : dp[i-1][j][1] + 1;
                    dp[i][j][2] = (j == 0 || i == 0) ? 1 : dp[i-1][j-1][2] + 1;
                    dp[i][j][3] = (j == n - 1 || i == 0) ? 1 : dp[i-1][j+1][3] + 1;

                    res = max(res, max(dp[i][j][0], max(dp[i][j][1], max(dp[i][j][2], dp[i][j][3]))));
                }
            }
        }
        return res;
    }
};
 */

// Solution 2: Use 2-dimension array to optimize space complexity.
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size(), n = m == 0 ? 0 : M[0].size();
        vector<vector<int>> dp (n, vector<int>(4, 0));

        int res = 0;
        for (int j = 0; j < m; ++j) {
            vector<vector<int>> tmp (n, vector<int>(4, 0));
            for (int i = 0; i < n; ++i) {
                if (M[j][i]) {
                    tmp[i][0] = i == 0 ? 1 : tmp[i-1][0] + 1;
                    tmp[i][1] = j == 0 ? 1 : dp[i][1] + 1;
                    tmp[i][2] = (i == 0 || j == 0) ? 1 : dp[i-1][2] + 1;
                    tmp[i][3] = (i == n - 1 || j == 0) ? 1 : dp[i+1][3] + 1;

                    res = max(res, max(tmp[i][0], max(tmp[i][1], max(tmp[i][2], tmp[i][3]))));
                }

            }
            swap(tmp, dp);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> arr ={
        {0,1,1,0},{0,1,1,0},{0,0,0,1}
    };
    int res = sol.longestLine(arr);
    cout << res << endl;
    return 0;
}
