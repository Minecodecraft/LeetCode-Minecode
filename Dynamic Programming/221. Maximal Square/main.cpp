//
//  main.cpp
//  221. Maximal Square
//
//  Created by 边俊林 on 2019/8/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/maximal-square/
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
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), 0));
        vector<vector<int>> top (matrix.size(), vector<int> (matrix[0].size(), 0));
        vector<vector<int>> left (matrix.size(), vector<int> (matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i == 0)
                    top[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else
                    top[i][j] = matrix[i][j] == '1' ? top[i-1][j]+1 : 0;

                if (j == 0)
                    left[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else
                    left[i][j] = matrix[i][j] == '1' ? left[i][j-1]+1 : 0;
            }
        }

        int maxx = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = 1;
                if (i > 0 && j > 0)
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(left[i][j], top[i][j]));
                maxx = max(maxx, dp[i][j]);
            }
        }
        return maxx * maxx;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs = {
        "10100", "10111", "11111", "10010"
    };
//    vector<string> strs = {"0"};
//    vector<string> strs = {
//        "0001",
//        "1101",
//        "1111",
//        "0111",
//        "0111"
//    };
    vector<vector<char>> matrix (strs.size());
    for (int i = 0; i < strs.size(); ++i) {
        for (int j = 0; j < strs[i].length(); ++j) {
            matrix[i].push_back(strs[i][j]);
        }
    }
    int res = sol.maximalSquare(matrix);
    cout << res << endl;
    return 0;
}
