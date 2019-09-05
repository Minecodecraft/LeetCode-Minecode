//
//  main.cpp
//  363. Max Sum of Rectangle No Larger Than K
//
//  Created by 边俊林 on 2019/9/4.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int maxx = INT_MIN;
        for (int l = 0; l < cols; ++l) {
            vector<int> sum (rows, 0);
            for (int r = l; r < cols; ++r) {
                for (int j = 0; j < rows; ++j)
                    sum[j] += matrix[j][r];
                set<int> rowsum;
                rowsum.insert(0);
                int cursum = 0, curmax = INT_MIN;
                for (int j = 0; j < rows; ++j) {
                    cursum += sum[j];
                    auto it = rowsum.lower_bound(cursum - k);
                    if (it != rowsum.end())
                        curmax = max(curmax, cursum - *it);
                    rowsum.insert(cursum);
                }
                maxx = max(maxx, curmax);
            }
        }
        return maxx;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {1,0,1},{0,-2,3}
        {2, 2, -1}
    };
    int res = sol.maxSumSubmatrix(mat, 0);
    cout << res << endl;
    return 0;
}
