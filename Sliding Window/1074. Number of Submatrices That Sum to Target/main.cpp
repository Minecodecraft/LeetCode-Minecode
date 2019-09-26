//
//  main.cpp
//  1074. Number of Submatrices That Sum to Target
//
//  Created by 边俊林 on 2019/9/25.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                matrix[i][j] += j > 0 ? matrix[i][j-1] : 0;
        for (int l = 0; l < m; ++l) {
            for (int r = l; r < m; ++r) {
                unordered_map<int, int> viscnt;
                viscnt[0] = 1;
                int sum = 0;
                for (int row = 0; row < n; ++row) {
                    sum += matrix[row][r] - (l == 0 ? 0 : matrix[row][l-1]);
                    res += viscnt[sum-target];
                    viscnt[sum]++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {0, 1, 0}, {1, 1, 1}, {0, 1, 0}
        {1, -1}, {-1, 1}
    };
    int target = 0;
    int res = sol.numSubmatrixSumTarget(mat, target);
    cout << res  << endl;
    return 0;
}
